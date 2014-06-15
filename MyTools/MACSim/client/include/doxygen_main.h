//----------------------------------------------------------------------------
// doxygen_main.h
//
// Project : Multi-Agent Control in a Simulink block
// File    : Client main page documentation for Doxygen
//
// Version : 1.0
// Date    : 6th February 2005
// Author  : Peter Mendham
//
// (c) University of York
//----------------------------------------------------------------------------

#ifndef __DOXYGEN_MAIN_H__
#define __DOXYGEN_MAIN_H__

//----------------------------------------------------------------------------
// This file contains nothing except main page Doxygen documentation.
// It is placed separately as it doesn't really belong anywhere else and
// helps keep other files nice and clean.
//----------------------------------------------------------------------------

//! \ifnot complete_doc
//!		\mainpage MACSim Library: %Client Section 
//! \endif
//! \if complete_doc
//!		\page client_index MACSim Library: Client Section
//! \endif
//!
//! \section client_intro Introduction
//! This is a sub-project of the MACSim library, which is intended to aid
//! programmers in creating multi-agent simulations for direct interfacing to
//! Matlab and Simulink, both created by 
//! <a href="http://www.mathworks.com/">The MathWorks</a>.
//! Simulink does not seem to support multi-threading in Simulink blocks
//! written in C or C++.  This problem has been identified though painful
//! experimentation.
//!
//! MACSim exists in two parts:
//! \li a client which appears as a Simulink s-function block called MACSim;
//! \li a server, written as a library which a programmer may incorporate into
//! their own code.
//!
//! The server runs as a separate process from the client, communicating via
//! named pipes.  Communication is asynchronous to other server processes
//! allowing the server to be multi-threaded.
//!
//! Two servers are currently provided as part of the full MACSim package: a
//! C++ server and a Java server, known as server and jserver respectively.
//! An agent library is also provided allowing easy construction of a
//! multi-agent system in C++.  It assumed that users of the jserver can
//! utilise any one of the large number of existing agent frameworks for Java.
//!
//! The MACSim client uses Lee Netherton's SimClassLib and both the client and
//! server use his MatrixClassLib as well.
//!
//! \section client_usage Client Usage
//! No changes need be made to the client code in order to use it.  All
//! configuration data required by Simulink is obtained from the server.
//! A precompiled binary file (a DLL) is present in the client/bin directory.
//! To use the client, ensure that this directory is on your Matlab path and
//! then add an S-function block to your Simulink model with the name \c
//! MACSim.  No parameters are necessary.  The server sub-projects contain
//! examples Simulink models and associated servers.
//!
//! \section client_doc This Documentation
//! This documentation is intended for maintainers of the client sub-project
//! and for those who are interested in how the client works.  There are two
//! important classes in the client:
//! \li The MACSimClient class inherits from the Sim class which is part of
//!		SimClassLib.  This class creates the Simulink block with one set of
//!		inputs and outputs using fixed-period discrete timing.
//! \li	The Client class implements a pipe client for the two MACSim pipes.
//!		It caches configuration data for more efficient operation.

#endif // __DOXYGEN_MAIN_H__