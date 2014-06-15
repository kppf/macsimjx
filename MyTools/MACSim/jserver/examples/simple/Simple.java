//----------------------------------------------------------------------------
// Simple.java
//
// Project : Multi-Agent Control in a Simulink block
// File    : Simple example java class
//
// Version : 1.0
// Date    : 16th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

import macsim.*;

// Example class implementing MACSimServerInterface
// Takes two inputs and adds them together to produce one output.
public class Simple implements MACSimServerInterface {

	// Return the number of inputs we require
	public int getNumInputs() {
		return 2;
	}

	// Return the number of outputs we require
	public int getNumOutputs() {
		return 1;
	}

	// Return the sample interval we require, in milliseconds
	public int getSampleInterval() {
		return 100;
	}

	// This routine is called every sample period.
	// We should carry out anything that is needed to provide all
	// of the outputs, then return.
	public void getSimOutputs(double[] in, double[] out) {
		out[0] = in[0] + 4*in[1];
	}

	// Just create a server, attaching it to an instance of Simple,
	// then run it.  The server will terminate when the user presses
	// enter.
	public static void main(String args[]) {

		Simple simpleInterface = new Simple();
		MACSimServer simpleServer = new MACSimServer("Simple", simpleInterface);

		simpleServer.run();
	}
}
