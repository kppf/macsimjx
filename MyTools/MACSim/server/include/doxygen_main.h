//----------------------------------------------------------------------------
// doxygen_main.h
//
// Project : Multi-Agent Control in a Simulink block
// File    : Server main page documentation for Doxygen
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
//!		\mainpage MACSim Library: %Server Section 
//! \endif
//! \if complete_doc
//!		\page server_index MACSim Library: Server Section
//! \endif
//!
//! \section server_intro Introduction
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
//! \section server_usage Server Usage
//! No changes need be made to the server code in order to use it.  To create
//! an operating server a class must be created which inherits from
//! MACSimServerInterface.  MACSimServerInterface defines four pure virual
//! member functions which return key information for configuring the server
//! and operating the simulation.  To create a server, the server class
//! (MACSimServer) must be instantiated, passing an instance of the
//! MACSimServerInterface to the constructor.
//!
//! The Simple class defined in simple.cpp provides an example of the use of
//! MACSimServerInterface and the MACSimServer server class.
//!
//! \section server_structure Server Structure
//! The primary server class is MACSimServer. This utilises two other classes,
//! one for each of the two asynchronous named pipes the server provides.
//! ConfigServer defines the configuration pipe and SimServer defines the
//! simulation pipe.  Each of these classes inherit their basic functionality
//! from the Server class, which defines basic asynchronous named pipe
//! behaviour.  asynchronicity comes from the Thread class which provides a
//! class-encapsulated windows thread.
//!
//! The data sent down the pipe is all gathered from the class which defines
//! MACSimServerInterface.
//!
//! \section server_doc This Documentation
//! This documentation is primarily intended for those wanting to implement a
//! MACSim server.  It should also provide a starting point for maintainers of
//! the MACSim server library and for those interested in its operation.

#endif // __DOXYGEN_MAIN_H__