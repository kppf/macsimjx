#ifndef __SIM_VECTOR_H__
#define __SIM_VECTOR_H__

#include "../../../MatrixClassLib/code/include/matrix.h"
#include "../../../MatrixClassLib/code/include/matrix_container.h"

#include <iostream>

// Forward Defince some classes
class Interface;
class ContinuousInterface;
class DiscreteInterface;
class InterfaceContainer;
class SimVectorConstant;
class SimVector;



//! \brief Read access for the SimVectorConstant and SimVector classes
//! \author Lee Netherton
//!
//! The SimvectorReadAccess class provides a means of ensuring that
//! the SimVector's data pointer is up-to-date. Validity is maintained
//! automatically using the getDataPointer() function. To in validate
//! the data pointer the invalidate() function can be used. The pointer
//! will then be automatically updated upon the next getDataPointer()
//! call. Manual updating of the pointer can be forced using the
//! updateDataPointer() function.
//!
class SimVectorReadAccess : public MatrixReadAccess
{
	protected:

		//! Poiner to the owner class
		SimVectorConstant * m_simVectorConstant;

		//! Data pointer valid flag
		bool m_dataPointerOk;

	public:

		//! \brief Constructor
		//!
		//! Constructs the SimVectorReadAccess class.
		//! This is the only constructor.
		//! \param SVC Pointer to owner vector
		SimVectorReadAccess(SimVectorConstant * SVC) :
			MatrixReadAccess((MatrixAliasConstant *)SVC),
			m_simVectorConstant(SVC),
			m_dataPointerOk(false)
			{
				#ifdef DEBUG_CONSTRUCT
					printf("Constructor: SimVectorReadAccess(SimVectorConstant * SVC)\n");
				#endif
			}

		//! Invalidates the data pointer
		void invalidate() {m_dataPointerOk = false;}

		//! Returns the a pointer to the data array
		virtual const double * getDataPointer();

		//! Updates the data pointer
		void updateDataPointer();
};


//! \brief Read access for the SimInputVector class
//! \author Lee Netherton
//!
//! The SimInputVectorReadAccess class provides virtual
//! overloaded functions for the readElement() member of
//! MatrixReadAccess. This is needed as Simulink input vectors
//! are stored as double** rather than double*. The extra
//! indirection is provided with these functions.
//!
class SimInputVectorReadAccess : public SimVectorReadAccess
{
	private:

		//! Poiner to the owner class
		//SimVectorConstant * m_simVectorConstant;

		//! Data pointer valid flag
		//bool m_dataPointerOk;

	public:

		//! \brief Constructor
		//!
		//! Constructs the SimInputVectorReadAccess class.
		//! This is the only constructor.
		//! \param SVC Pointer to owner vector
		SimInputVectorReadAccess(SimVectorConstant * SVC) :
			SimVectorReadAccess(SVC)
			{
				#ifdef DEBUG_CONSTRUCT
					printf("Constructor: SimInputVectorReadAccess(SimVectorConstant * SVC)\n");
				#endif
			}

		//! Returns a read-only reference to the data member at specified position
		//! \param row Row position of desired element (zero indexed)
		//! \param column Column position of desired element (zero indexed)
		virtual const double& readElement(const unsigned int row, const unsigned int column);

		//! Returns a read-only reference to the data member at specified position
		//! \param index Row-wise position of element (zero-indexed)
		virtual const double& readElement(const unsigned int index);
};

//! \brief Write access for the SimVector classes
//! \author Lee Netherton
//!
//! The SimvectorWriteAccess class provides a means of ensuring that
//! the SimVector's data pointer is up-to-date. Validity is maintained
//! automatically using the getDataPointer() function. To in validate
//! the data pointer the invalidate() function can be used. The pointer
//! will then be automatically updated upon the next getDataPointer()
//! call. Manual updating of the pointer can be forced using the
//! updateDataPointer() function.
//!
class SimVectorWriteAccess : public MatrixWriteAccess
{
	private:
		//! Poiner to the owner class
		SimVector * m_simVector;

		//! Data pointer valid flag
		bool m_dataPointerOk;

	public:
		//! \brief Constructor
		//!
		//! Constructs the SimVectorWriteAccess class.
		//! This is the only constructor.
		//! \param SV Pointer to owner vector
		SimVectorWriteAccess(SimVector * SV) :
			MatrixWriteAccess((MatrixAlias *)SV),
			m_simVector(SV),
			m_dataPointerOk(false)
			{
				#ifdef DEBUG_CONSTRUCT
					printf("Constructor: SimVectorWriteAccess(SimVector * SV)\n");
				#endif
		}

		//! Invalidates the data pointer
		void invalidate() {m_dataPointerOk = false;}

		//! Returns the a pointer to the data array
		virtual double * getDataPointer();

		//! Updates the data pointer
		void updateDataPointer();
};

//! \brief Base class for SimVectorConstant descendants
//! \author Lee Netherton
//!
//! This is an abstract class which provides a base for read only
//! SimVector's like SimInputVector. The main functionality that
//! it provides is the ability to obtain its own data pointer from
//! the simulation structure. This is provided via getSimIoPointer().
//! To aid the retreval of this pointer, the class is equiped with
//! a pointer to the InterfaceContainer class (m_interfaceContainer)
//! and the id number of the Interface (m_interfaceId).
//!
class SimVectorConstant : virtual public ColumnVectorAliasConstant
{
	protected:
		//------------------------------------------------------------
		//         Members
		//------------------------------------------------------------

		//! Pointer to the InterfaceContainer class
		InterfaceContainer * m_interfaceContainer;

		//! Pointer to Interface class in which this vector exists
		Interface * m_pInterface;

		//! Pointer to the ReadAccess object
		SimVectorReadAccess * m_simVectorReadAccess;

	public:
		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Sized Constructor
		//!
		//! To construct the full class.
		//! \param parentInterface Pointer to the owner class
		//! \param size Size of the vector
		SimVectorConstant(Interface * parentInterface, const unsigned int size) :
			MatrixAliasConstant(m_simVectorReadAccess = new SimVectorReadAccess(this), 0, size, 1),
			ColumnVectorAliasConstant(0, size)
			{_constructSimVectorConstant(parentInterface);}

	protected:
		//------------------------------------------------------------
		//         Constructor Functions
		//------------------------------------------------------------

		//! \brief Sized Constructor
		//!
		//! To construct the full class manually.
		//! \param parentInterface Pointer to the owner class
		void _constructSimVectorConstant(Interface * parentInterface);

	public:
		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief SimVectorConstant Destructor
		//!
		//! Virtual - the lowest derived class will always need to be called, as they
		//! all allocate memory in ther own ways.
		virtual ~SimVectorConstant();

		//------------------------------------------------------------
		//         Other members
		//------------------------------------------------------------

		//! Invalidate the data pointer
		virtual void invalidate() {m_simVectorReadAccess->invalidate();}

		//! Get an up-to-date version of the data pointer
		virtual const double * getSimIoPointer() const=0;
};


//! \brief Base class for SimVector descendants
//! \author Lee Netherton
//!
//! This is an abstract class which provides a base for read/write
//! SimVector's like SimStateDerivativeVector.
//!
class SimVector : public SimVectorConstant, public ColumnVectorAlias
{
	protected:
		//------------------------------------------------------------
		//         Members
		//------------------------------------------------------------

		//! Pointer to the WriteAccess object
		SimVectorWriteAccess * m_simVectorWriteAccess;

	public:
		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Sized Constructor
		//!
		//! To construct the full class.
		//! \param parentInterface Pointer to the owner class
		//! \param size Size of the vector
		SimVector(Interface * parentInterface, const unsigned int size) :
			MatrixAliasConstant(m_simVectorReadAccess = new SimVectorReadAccess(this), 0, size, 1),
			MatrixAlias(0, 0, m_simVectorWriteAccess = new SimVectorWriteAccess(this)),
			ColumnVectorAliasConstant(0, size),
			ColumnVectorAlias(0, size),
			SimVectorConstant(parentInterface, size)
			{_constructSimVector(parentInterface);}

	protected:
		//------------------------------------------------------------
		//         Constructor Functions
		//------------------------------------------------------------

		//! \brief Sized Constructor
		//!
		//! To construct the full class manually.
		//! \param parentInterface Pointer to the owner class
		void _constructSimVector(Interface * parentInterface);

	public:
		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief SimVector Destructor
		//!
		//! Virtual - the lowest derived class will always need to be called, as they
		//! all allocate memory in ther own ways.
		virtual ~SimVector();

		//------------------------------------------------------------
		//         Other members
		//------------------------------------------------------------

		//! Invalidate the data pointer
		virtual void invalidate() {m_simVectorReadAccess->invalidate();m_simVectorWriteAccess->invalidate();}

};


//! \brief Simulation input vector
//! \author Lee Netherton
//!
//! Derived from SimVectorConstant, this class is used soley for defining how
//! the data pointer is retrieved via getSimIoPointer().
//!
class SimInputVector : public SimVectorConstant
{
	public:
		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Sized Constructor
		//!
		//! To construct the full class.
		//! \param parentInterface Pointer to the owner class
		//! \param size Size of the vector
		SimInputVector(Interface * parentInterface, const unsigned int size) :
			MatrixAliasConstant(m_simVectorReadAccess = new SimInputVectorReadAccess(this), 0, size, 1),
			ColumnVectorAliasConstant(0, size),
			SimVectorConstant(parentInterface, size)
			{}

		//------------------------------------------------------------
		//         Other members
		//------------------------------------------------------------

		//! Get an up-to-date version of the data pointer
		virtual const double * getSimIoPointer() const;
};

//! \brief Simulation parameters vector
//! \author Lee Netherton
//!
//! Derived from SimVectorConstant, this class is used soley for defining how
//! the data pointer is retrieved via getSimIoPointer().
//!
class SimParamVector : public SimVectorConstant
{
	public:
		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Sized Constructor
		//!
		//! To construct the full class.
		//! \param parentInterface Pointer to the owner class
		//! \param size Size of the vector
		SimParamVector(Interface * parentInterface, const unsigned int size) :
			MatrixAliasConstant(m_simVectorReadAccess = new SimVectorReadAccess(this), 0, size, 1),
			ColumnVectorAliasConstant(0, size),
			SimVectorConstant(parentInterface, size)
			{}

		//------------------------------------------------------------
		//         Other members
		//------------------------------------------------------------

		//! Get an up-to-date version of the data pointer
		virtual const double * getSimIoPointer() const;
};

//! \brief Simulation output vector
//! \author Lee Netherton
//!
//! Derived from SimVector, this class is used soley for defining how
//! the data pointer is retrieved via getSimIoPointer().
//!
class SimOutputVector : public SimVector
{
	public:
		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Sized Constructor
		//!
		//! To construct the full class.
		//! \param parentInterface Pointer to the owner class
		//! \param size Size of the vector
		SimOutputVector(Interface * parentInterface, const unsigned int size) :
			MatrixAliasConstant(m_simVectorReadAccess = new SimVectorReadAccess(this), 0, size, 1),
			MatrixAlias(0, 0, m_simVectorWriteAccess = new SimVectorWriteAccess(this)),
			ColumnVectorAliasConstant(0, size),
			SimVector(parentInterface, size)
			{}

		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		SimOutputVector& operator=(const MatrixAliasConstant& copy) {equals(copy);return *this;}

		//! Assignment operator
		SimOutputVector& operator=(const SimOutputVector& copy) {return operator=((MatrixAliasConstant&)copy);}

		//------------------------------------------------------------
		//         Other members
		//------------------------------------------------------------

		//! Get an up-to-date version of the data pointer
		virtual const double * getSimIoPointer() const;
};

//! \brief Simulation continuous state vector
//! \author Lee Netherton
//!
//! Derived from SimVector, this class is used soley for defining how
//! the data pointer is retrieved via getSimIoPointer().
//!
class SimContinuousStateVector : public SimVector
{
	public:
		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Sized Constructor
		//!
		//! To construct the full class.
		//! \param parentInterface Pointer to the owner class
		//! \param size Size of the vector
		SimContinuousStateVector(ContinuousInterface * parentInterface, const unsigned int size);

		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		SimContinuousStateVector& operator=(const MatrixAliasConstant& copy) {equals(copy);return *this;}

		//! Assignment operator
		SimContinuousStateVector& operator=(const SimContinuousStateVector& copy) {return operator=((MatrixAliasConstant&)copy);}

		//------------------------------------------------------------
		//         Other members
		//------------------------------------------------------------

		//! Get an up-to-date version of the data pointer
		virtual const double * getSimIoPointer() const;

};

//! \brief Simulation discrete state vector
//! \author Lee Netherton
//!
//! Derived from SimVector, this class is used soley for defining how
//! the data pointer is retrieved via getSimIoPointer().
//!
class SimDiscreteStateVector : public SimVector
{
	public:
		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Sized Constructor
		//!
		//! To construct the full class.
		//! \param parentInterface Pointer to the owner class
		//! \param size Size of the vector
		SimDiscreteStateVector(DiscreteInterface * parentInterface, const unsigned int size);

		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		SimDiscreteStateVector& operator=(const MatrixAliasConstant& copy) {equals(copy);return *this;}

		//! Assignment operator
		SimDiscreteStateVector& operator=(const SimDiscreteStateVector& copy) {return operator=((MatrixAliasConstant&)copy);}

		//------------------------------------------------------------
		//         Other members
		//------------------------------------------------------------

		//! Get an up-to-date version of the data pointer
		virtual const double * getSimIoPointer() const;

};

//! \brief Simulation state derivative vector
//! \author Lee Netherton
//!
//! Derived from SimVector, this class is used soley for defining how
//! the data pointer is retrieved via getSimIoPointer().
//!
class SimStateDerivativeVector : public SimVector
{
	public:
		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Sized Constructor
		//!
		//! To construct the full class.
		//! \param parentInterface Pointer to the owner class
		//! \param size Size of the vector
		SimStateDerivativeVector(ContinuousInterface * parentInterface, const unsigned int size);

		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		SimStateDerivativeVector& operator=(const MatrixAliasConstant& copy) {equals(copy);return *this;}

		//! Assignment operator
		SimStateDerivativeVector& operator=(const SimStateDerivativeVector& copy) {return operator=((MatrixAliasConstant&)copy);}

		//------------------------------------------------------------
		//         Other members
		//------------------------------------------------------------

		//! Get an up-to-date version of the data pointer
		virtual const double * getSimIoPointer() const;
};


#endif //__SIM_VECTOR_H__