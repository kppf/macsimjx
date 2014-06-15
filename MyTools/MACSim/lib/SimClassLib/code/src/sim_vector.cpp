#include "../include/sim_vector.h"
#include "../include/sim_interface_container.h"
#include "../include/sim_interface.h"

//-----------------------------------------
//
//          SimVectorReadAccess
//
//-----------------------------------------

//---------------------------
//   Get valid data pointer
//---------------------------
const double * SimVectorReadAccess::getDataPointer()
{
	// Check to see if its not valid
	if(!m_dataPointerOk)
	{
		updateDataPointer();
	}

	// Return now valid pointer
	return MatrixReadAccess::getDataPointer();
}

//---------------------------
//   Update the data pointer
//---------------------------
void SimVectorReadAccess::updateDataPointer()
{
	// Update the pointer
	setDataPointer(m_simVectorConstant->getSimIoPointer());

	// Set flag to true
	m_dataPointerOk = true;
}

//-----------------------------------------
//
//          SimInputVectorReadAccess
//
//-----------------------------------------

//-----------------------------------------
//          Element Functions
//-----------------------------------------

const double& SimInputVectorReadAccess::readElement(const unsigned int row, const unsigned int column)
{

	// Cast data pointer
	const double * const * dataPointer = (const double * const *)getDataPointer();

	if (row >= getRows() || column >= getColumns()) {
		error("MatrixAlias::element : Subscript out of range\n");
		return *dataPointer[0];
	}



	return *(dataPointer[row*(getColumns()) + column]);
}

const double& SimInputVectorReadAccess::readElement(const unsigned int index)
{

	// Cast data pointer
	const double * const * dataPointer = (const double * const *)getDataPointer();

	if (index >= (getRows()*getColumns())) {
		error("MatrixAlias::element : Subscript out of range\n");
		return *dataPointer[0];
	}

	return *(dataPointer[index]);

}

//-----------------------------------------
//
//          SimVectorWriteAccess
//
//-----------------------------------------

//---------------------------
//   Get valid data pointer
//---------------------------
double * SimVectorWriteAccess::getDataPointer()
{
	// Check to see if its not valid
	if(!m_dataPointerOk)
	{
		updateDataPointer();
	}

	// Return now valid pointer
	return MatrixWriteAccess::getDataPointer();
}

//---------------------------
//   Update the data pointer
//---------------------------
void SimVectorWriteAccess::updateDataPointer()
{
	// Update the pointer
	setDataPointer(m_simVector->getSimIoPointer());

	// Set flag to true
	m_dataPointerOk = true;
}

//-----------------------------------------
//
//          SimVectorConstant
//
//-----------------------------------------

//-----------------------------------------
//          Constructor Functions
//-----------------------------------------

//---------------------------
//   Sized Constructor
//---------------------------
void SimVectorConstant::_constructSimVectorConstant(Interface * parentInterface)
{
	// Construct this class
	m_interfaceContainer = parentInterface->getInterfaceContainer();
	m_pInterface = parentInterface;

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructor: SimVectorConstant(Interface * parentInterface)\n");
	#endif
}

//------------------------
//   Destructor
//------------------------
SimVectorConstant::~SimVectorConstant()
{
	// ReadAccess will be deleted by MatrixAliasConstant

	#ifdef DEBUG_DESTRUCTOR
		printf("Destructor: ~SimVectorConstant()\n");
	#endif
}

//-----------------------------------------
//
//          SimVector
//
//-----------------------------------------

//-----------------------------------------
//          Constructor Functions
//-----------------------------------------

//---------------------------
//   Sized Constructor
//---------------------------
void SimVector::_constructSimVector(Interface * parentInterface)
{
	// Construct this class
	m_interfaceContainer = parentInterface->getInterfaceContainer();
	m_pInterface = parentInterface;

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructor: SimVector(Interface * parentInterface)\n");
	#endif
}

//------------------------
//   Destructor
//------------------------
SimVector::~SimVector()
{
	// ReadAccess will be deleted by MatrixAliasConstant
	// WriteAccess will be deleted by MatrixAlias

	#ifdef DEBUG_DESTRUCTOR
		printf("Destructor: ~SimVector()\n");
	#endif
}


//-----------------------------------------
//
//          SimInputVector
//
//-----------------------------------------

//---------------------------
//   Get correct data pointer
//---------------------------
const double * SimInputVector::getSimIoPointer() const
{
	return m_interfaceContainer->getU(m_pInterface);
}

//-----------------------------------------
//
//          SimOutputVector
//
//-----------------------------------------

//---------------------------
//   Get correct data pointer
//---------------------------
const double * SimOutputVector::getSimIoPointer() const
{
	return m_interfaceContainer->getY(m_pInterface);
}

//-----------------------------------------
//
//          SimContinuousStateVector
//
//-----------------------------------------

//---------------------------
// Constructor
//---------------------------
SimContinuousStateVector::SimContinuousStateVector(ContinuousInterface * parentInterface, const unsigned int size) :
	MatrixAliasConstant(m_simVectorReadAccess = new SimVectorReadAccess(this), 0, size, 1),
	MatrixAlias(0, 0, m_simVectorWriteAccess = new SimVectorWriteAccess(this)),
	ColumnVectorAliasConstant(0, size),
	SimVector(parentInterface, size)
{}

//---------------------------
//   Get correct data pointer
//---------------------------
const double * SimContinuousStateVector::getSimIoPointer() const
{
	return m_interfaceContainer->getContinuousX((ContinuousInterface*)m_pInterface);
}

//-----------------------------------------
//
//          SimDiscreteStateVector
//
//-----------------------------------------

//---------------------------
// Constructor
//---------------------------
SimDiscreteStateVector::SimDiscreteStateVector(DiscreteInterface * parentInterface, const unsigned int size) :
	MatrixAliasConstant(m_simVectorReadAccess = new SimVectorReadAccess(this), 0, size, 1),
	MatrixAlias(0, 0, m_simVectorWriteAccess = new SimVectorWriteAccess(this)),
	ColumnVectorAliasConstant(0, size),
	SimVector(parentInterface, size)
{}

//---------------------------
//   Get correct data pointer
//---------------------------
const double * SimDiscreteStateVector::getSimIoPointer() const
{
	return m_interfaceContainer->getDiscreteX((DiscreteInterface*)m_pInterface);
}

//-----------------------------------------
//
//          SimStateDerivativeVector
//
//-----------------------------------------

//---------------------------
// Constructor
//---------------------------
SimStateDerivativeVector::SimStateDerivativeVector(ContinuousInterface * parentInterface, const unsigned int size) :
	MatrixAliasConstant(m_simVectorReadAccess = new SimVectorReadAccess(this), 0, size, 1),
	MatrixAlias(0, 0, m_simVectorWriteAccess = new SimVectorWriteAccess(this)),
	ColumnVectorAliasConstant(0, size),
	SimVector(parentInterface, size)
{}

//---------------------------
//   Get correct data pointer
//---------------------------
const double * SimStateDerivativeVector::getSimIoPointer() const
{
	return m_interfaceContainer->getDx((ContinuousInterface*)m_pInterface);
}

//-----------------------------------------
//
//          SimParamVector
//
//-----------------------------------------

//---------------------------
//   Get correct data pointer
//---------------------------
const double * SimParamVector::getSimIoPointer() const
{
	return m_interfaceContainer->getParam(m_pInterface);
}