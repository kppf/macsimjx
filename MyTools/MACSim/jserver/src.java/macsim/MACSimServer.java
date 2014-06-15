package macsim;

//----------------------------------------------------------------------------
// MACSimServer.java
//
// Project : Multi-Agent Control in a Simulink block
// File    : MACSimServer java class
// Package : macsim
//
// Version : 1.0
// Date    : 16th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

import java.io.IOException;
import macsim.internal.*;

public class MACSimServer {

	protected String name;
	protected ConfigServer configServer;
	protected SimServer simServer;
	protected boolean isRunning;

	public MACSimServer(String name, MACSimServerInterface callback) {

		// Copy name across
		this.name = name;

		// Create system pipes
                System.out.println("Create system pipes");
		configServer = new ConfigServer(callback);
		simServer = new SimServer(callback);

		// Not running yet
		isRunning = false;
	}

	public void run() {

		run(true, true);
	}

	public void run(boolean showMessage, boolean waitForKey) {

		// Create system pipes
		configServer.run();
		simServer.run();

		// We're now running
		isRunning = true;

		if (showMessage) {

			// Display server launch message
			System.out.println("MACSim Server: Running system \"" + name + "\"");
			System.out.print("Press enter to end service....");
		}

		// ONly wait for key and terminate if asked
		if (waitForKey) {

			try {

				// Wait for key press
				System.in.read();

			} catch (IOException e) {

				if (showMessage) {

					// Caught an exception thrown by System.in.read()
					System.out.println("Exception caught when handling key input");
					e.printStackTrace(System.out);
				}
			}

			// Terminate the server
			terminate();

			if (showMessage) {

				// Display final message
				System.out.println("done.");
			}
		}
	}

	public void terminate() {

		// Only terminate if we're actually running
		if (isRunning) {

			// Signal the system to terminate
			configServer.terminate();
			simServer.terminate();

			// Not running any more
			isRunning = false;
		}
	}
}
