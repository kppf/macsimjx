package macsim.internal;

//----------------------------------------------------------------------------
// Server.java
//
// Project : Multi-Agent Control in a Simulink block
// File    : Server java class
// Package : macsim.internal
//
// Version : 1.0
// Date    : 16th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

import java.io.*;
import macsim.MACSimServerInterface;

public abstract class Server {

	// Native methods implement server functionality
	private native void serverMain(byte[] inBuffer, byte[] outBuffer);
	private native void terminateServer();
	
	// Not implemented in the native libarary loaded by this class,
	// these are pipe dependent
	protected native void setNameVariables();
	protected native int getInBufferSize();
	protected native int getOutBufferSize();
	protected native void serverFunc(byte[] inBuffer, byte[] outBuffer);
	
	static {
        loadLibrary("MACSimServer");
    }
    
    // Identification details
    protected String name;
    protected String pipeName;
    
    // Call back interface class
    protected MACSimServerInterface callback;
    
    // Required by the native code for sychonisation
    private int terminateEventHandle;
    private int synchEventHandle;
    
    // Input and output buffers
    private byte inBuffer[];
    private byte outBuffer[];
    
    // The server thread
    private ServerThread serverThread = new ServerThread();

    public Server(MACSimServerInterface callback) {
    
    	int inBuffSize;
    	int outBuffSize;
    	
    	// Initialise callback
		this.callback = callback;
	
		// Initialise the name and pipe name members
		setNameVariables();
		
		// Find the required sizes for input and output buffers
		inBuffSize = getInBufferSize();
		outBuffSize = getOutBufferSize();
		
		// Initialise buffers
		inBuffer = new byte[inBuffSize];
		outBuffer = new byte[outBuffSize];
	}
	
	public String getName() {
	
		return name;
	}
	
	public MACSimServerInterface getInterface() {
	
		return callback;
	}

	public void run() {
		
		// Run the thread
		serverThread.start();
	}
	
	public void terminate() {
	
		// Call the native method to terminate the server
		terminateServer();
	}
	
	private class ServerThread extends Thread {
	
        public void run() {
        
        	// Call the main server native method
        	serverMain(inBuffer, outBuffer);
        }
	}
	
	private static boolean loadLibrary(String libraryName)
	{
		try	{
		
			// Finds a stream to the dll. Change path/class if necessary
			InputStream inputStream = Server.class.getResource("/" + libraryName + ".dll").openStream();

			// Change name if necessary
			File temporaryDll = File.createTempFile(libraryName, ".dll");
			
			// Copy library file out of jar
			FileOutputStream outputStream = new FileOutputStream(temporaryDll);
			byte[] array = new byte[8192];
			for (int i = inputStream.read(array); i != -1; i = inputStream.read(array)) {
				outputStream.write(array, 0, i);
			}
			outputStream.close();

			// Make sure the file gets removed
			temporaryDll.deleteOnExit();

			// Load the library
			System.load(temporaryDll.getPath());
			
			return true;
			
		} catch(Throwable e) {
		
			e.printStackTrace();
			return false;
		}
    }
}