package macsim;

//----------------------------------------------------------------------------
// MACSimServerInterface.java
//
// Project : Multi-Agent Control in a Simulink block
// File    : MACSimServerInterface java interface
// Package : macsim
//
// Version : 1.0
// Date    : 16th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

public interface MACSimServerInterface {

	public int getNumInputs();
	
	public int getNumOutputs();
	
	public int getSampleInterval();
	
	public void getSimOutputs(double[] in, double[] out);
}