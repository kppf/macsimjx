package macsim.internal;

//----------------------------------------------------------------------------
// ConfigServer.java
//
// Project : Multi-Agent Control in a Simulink block
// File    : ConfigServer java class
// Package : macsim.internal
//
// Version : 1.0
// Date    : 16th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

import macsim.MACSimServerInterface;

public class ConfigServer extends Server {

	// Implemented to give config pipe specific operations
	protected native void setNameVariables();
	protected native int getInBufferSize();
	protected native int getOutBufferSize();
	protected native void serverFunc(byte[] inBuffer, byte[] outBuffer);
	
    public ConfigServer(MACSimServerInterface callback) {
    
    	// Initialise superclass
    	super(callback);
	}
}