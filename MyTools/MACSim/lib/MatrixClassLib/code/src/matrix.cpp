#include "../include/matrix.h"
#include "../include/matrix_container.h"
#include "../include/matrix_access.h"
#include "../include/matrix_operator.h"

//-----------------------------------------
//
//          MatrixAliasConstant
//
//-----------------------------------------

//-----------------------------------------
//          Constructor Functions
//-----------------------------------------


//------------------------
//   Pointer Constructor
//------------------------
void MatrixAliasConstant::_constructMatrixAliasConstant(const double * data, const unsigned int rows, const unsigned int columns)
{
	// Create new container
	m_matrixContainer = new MatrixContainer(data, rows, columns);

	// Create new read access object
	m_matrixReadAccess = new MatrixReadAccess(this);

	// Construct operators
	_constructMatrixReadOperators();


	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: MatrixAliasConstant::Pointer Constructor\n");
	#endif
}

//------------------------
//   Member Constructor
//------------------------
void MatrixAliasConstant::_constructMatrixAliasConstant(MatrixContainer * container, MatrixReadAccess * access)
{
	// Set container class pointer
	m_matrixContainer = container;

	// Set read access class pointer
	m_matrixReadAccess = access;

	// Construct operators
	_constructMatrixReadOperators();

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: MatrixAliasConstant::Member Constructor\n");
	#endif
}

//------------------------
//   Member Constructor - just container
//------------------------
void MatrixAliasConstant::_constructMatrixAliasConstant(MatrixContainer * container)
{
	// Set container class pointer
	m_matrixContainer = container;

	// Create new read access object
	m_matrixReadAccess = new MatrixReadAccess(this);

	// Construct operators
	_constructMatrixReadOperators();

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: MatrixAliasConstant::Member Constructor - just container\n");
	#endif
}

//------------------------
//   Member Constructor - just access
//------------------------
void MatrixAliasConstant::_constructMatrixAliasConstant(MatrixReadAccess * access, const double * data, const unsigned int rows, const unsigned int columns)
{
	// Create new container
	m_matrixContainer = new MatrixContainer(data, rows, columns);

	// Set read access class pointer
	m_matrixReadAccess = access;

	// Construct operators
	_constructMatrixReadOperators();

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: MatrixAliasConstant::Member Constructor - just access\n");
	#endif
}

//------------------------
//   Operator Constructor
//------------------------
void MatrixAliasConstant::_constructMatrixReadOperators()
{
	// Construct operators
	element._constructMatrixReadOperator(this);
	add._constructMatrixReadOperator(this);
	subtract._constructMatrixReadOperator(this);
	negative._constructMatrixReadOperator(this);
	multiply._constructMatrixReadOperator(this);
	divide._constructMatrixReadOperator(this);
	print._constructMatrixReadOperator(this);
	printM._constructMatrixReadOperator(this);
	subMatrix._constructMatrixReadOperator(this);
	sizeEqual._constructMatrixReadOperator(this);
	isSquareMatrix._constructMatrixReadOperator(this);
	isRowVector._constructMatrixReadOperator(this);
	isColumnVector._constructMatrixReadOperator(this);
	transpose._constructMatrixReadOperator(this);
	absolute._constructMatrixReadOperator(this);
	rowSum._constructMatrixReadOperator(this);
	columnSum._constructMatrixReadOperator(this);
	maximum._constructMatrixReadOperator(this);
	minimum._constructMatrixReadOperator(this);
	infinityNorm._constructMatrixReadOperator(this);
	frobeniusNorm._constructMatrixReadOperator(this);
	squaredElements._constructMatrixReadOperator(this);
}

//------------------------
//   Destructor
//------------------------
MatrixAliasConstant::~MatrixAliasConstant()
{
	// Delete container
	delete m_matrixContainer;

	// Delete read access object
	delete m_matrixReadAccess;

	#ifdef DEBUG_DESTRUCTOR
		printf("Destructor: ~MatrixAliasConstant()\n");
	#endif
}




//-----------------------------------------
//
//          MatrixAlias
//
//-----------------------------------------

//-----------------------------------------
//          Constructor Functions
//-----------------------------------------

//------------------------
//   Pointer Constructor
//------------------------
void MatrixAlias::_constructMatrixAlias()
{
	// Create new wrire access class
	m_matrixWriteAccess = new MatrixWriteAccess(this);

	// Construct operators
	_constructMatrixWriteOperators();

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: MatrixAlias::Pointer Constructor\n");
	#endif
}


//------------------------
//   Member Constructor
//------------------------
void MatrixAlias::_constructMatrixAlias(MatrixWriteAccess * w_access)
{
	// Set write access class pointer
	m_matrixWriteAccess = w_access;

	// Construct operators
	_constructMatrixWriteOperators();

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: MatrixAlias::Member Constructor\n");
	#endif

}


//------------------------
//   Operator Constructor
//------------------------
void MatrixAlias::_constructMatrixWriteOperators()
{
	// Construct operators
	element._constructMatrixWriteOperator(this);
	equals._constructMatrixWriteOperator(this);
	zero._constructMatrixWriteOperator(this);
	set._constructMatrixWriteOperator(this);
	normalise._constructMatrixWriteOperator(this);
	rand._constructMatrixWriteOperator(this);
	subMatrix._constructMatrixWriteOperator(this);
}

//------------------------
//   Destructor
//------------------------
MatrixAlias::~MatrixAlias()
{
	// Delete write access object
	delete m_matrixWriteAccess;

	#ifdef DEBUG_DESTRUCTOR
		printf("Destructor: ~MatrixAlias()\n");
	#endif
}

MatrixAlias& MatrixAlias::operator+=(const MatrixAliasConstant& operand)
{
	equals(add(operand));
	return *this;
}

MatrixAlias& MatrixAlias::operator-=(const MatrixAliasConstant& operand)
{
	equals(subtract(operand));
	return *this;
}

MatrixAlias& MatrixAlias::operator*=(const MatrixAliasConstant& operand)
{
	equals(multiply(operand));
	return *this;
}

MatrixAlias& MatrixAlias::operator*=(const double& operand)
{
	equals(multiply(operand));
	return *this;
}

MatrixAlias& MatrixAlias::operator/=(const double& operand)
{
	equals(divide(operand));
	return *this;
}

//-----------------------------------------
//
//          Matrix
//
//-----------------------------------------

//-----------------------------------------
//          Constructor Functions
//-----------------------------------------

//------------------------
//   Sized Constructor
//------------------------
void Matrix::_constructMatrix()
{
	// Construct operators
	_constructMatrixWriteOperators();

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: Matrix::Sized Constructor\n");
	#endif
}

//------------------------
//   Copy Constructor
//------------------------
void Matrix::_constructMatrix(const MatrixAliasConstant& copy)
{
	// Construct this matrix
	_constructMatrix();

	// Use equals operator to copy data in
	equals(copy);

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: Matrix::Copy Constructor\n");
	#endif
}

//------------------------
//   Operator Constructor
//------------------------
void Matrix::_constructMatrixWriteOperators()
{
	// Construct operator
	equals._constructMatrixWriteOperator(this);
	resize._constructMatrixWriteOperator(this);
}

//------------------------
//   Destructor
//------------------------
Matrix::~Matrix()
{
	// Delete data array
	delete[] m_matrixContainer->getDataPointer();

	#ifdef DEBUG_DESTRUCTOR
		printf("Destructor: ~Matrix()\n");
	#endif
}



//-----------------------------------------
//
//          SubMatrixAliasConstant
//
//-----------------------------------------

//-----------------------------------------
//          Constructor Functions
//-----------------------------------------

//---------------------------
//   Blank Constructor
//---------------------------
void SubMatrixAliasConstant::_constructSubMatrixAliasConstant()
{
	// Create new SubMatrixContainer
	//m_subMatrixContainer = new SubMatrixContainer(original_container, rowStart, rowEnd, columnStart, columnEnd);

	// Pass container to MatrixAliasConstant
	//_constructMatrixAliasConstant(m_subMatrixContainer, new SubMatrixReadAccess(this));

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: SubMatrixAliasConstant::Container Constructor\n");
	#endif
}


/*//---------------------------
//   Container Constructor
//---------------------------
void SubMatrixAliasConstant::_constructSubMatrixAliasConstant(const MatrixContainer * original_container, const unsigned int rowStart, const unsigned int rowEnd, const unsigned int columnStart, const unsigned int columnEnd)
{
	// Create new SubMatrixContainer
	//m_subMatrixContainer = new SubMatrixContainer(original_container, rowStart, rowEnd, columnStart, columnEnd);

	// Pass container to MatrixAliasConstant
	//_constructMatrixAliasConstant(m_subMatrixContainer, new SubMatrixReadAccess(this));

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: SubMatrixAliasConstant::Container Constructor\n");
	#endif
}

//---------------------------
//   SubContainer Constructor
//---------------------------
void SubMatrixAliasConstant::_constructSubMatrixAliasConstant(const SubMatrixContainer * original_subContainer)
{
	// Create new SubMatrixContainer
	m_subMatrixContainer = new SubMatrixContainer(*original_subContainer);

	// Pass container to MatrixAliasConstant
	_constructMatrixAliasConstant(m_subMatrixContainer, new SubMatrixReadAccess(this));

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: SubMatrixAliasConstant::SubContainer Constructor\n");
	#endif
}*/

//------------------------
//   Destructor
//------------------------
SubMatrixAliasConstant::~SubMatrixAliasConstant()
{
	// SubMatrixContainer will be deleted by MatrixAliasConstant
	// SubMatrixReadAccess will be deleted by MatrixAliasConstant

	#ifdef DEBUG_DESTRUCTOR
		printf("Destructor: ~SubMatrixAliasConstant()\n");
	#endif
}



//-----------------------------------------
//
//          SubMatrixAlias
//
//-----------------------------------------

//-----------------------------------------
//          Constructor Functions
//-----------------------------------------

//---------------------------
//   Blank Constructor
//---------------------------
void SubMatrixAlias::_constructSubMatrixAlias()
{
	// Create new SubMatrixContainer
	//m_subMatrixContainer = new SubMatrixContainer(original_container, rowStart, rowEnd, columnStart, columnEnd);

	// Pass container to MatrixAlias
	//_constructMatrixAlias(m_subMatrixContainer, new SubMatrixReadAccess(this), new SubMatrixWriteAccess(this));

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: SubMatrixAlias::Container Constructor\n");
	#endif
}

/*//---------------------------
//   Container Constructor
//---------------------------
void SubMatrixAlias::_constructSubMatrixAlias(const MatrixContainer * original_container, const unsigned int rowStart, const unsigned int rowEnd, const unsigned int columnStart, const unsigned int columnEnd)
{
	// Create new SubMatrixContainer
	m_subMatrixContainer = new SubMatrixContainer(original_container, rowStart, rowEnd, columnStart, columnEnd);

	// Pass container to MatrixAlias
	_constructMatrixAlias(m_subMatrixContainer, new SubMatrixReadAccess(this), new SubMatrixWriteAccess(this));

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: SubMatrixAlias::Container Constructor\n");
	#endif
}

//---------------------------
//   SubContainer Constructor
//---------------------------
void SubMatrixAlias::_constructSubMatrixAlias(const SubMatrixContainer * original_subContainer)
{
	// Create new SubMatrixContainer
	m_subMatrixContainer = new SubMatrixContainer(*original_subContainer);

	// Pass container to MatrixAlias
	_constructMatrixAlias(m_subMatrixContainer, new SubMatrixReadAccess(this), new SubMatrixWriteAccess(this));

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: SubMatrixAlias::SubContainer Constructor\n");
	#endif
}*/

//------------------------
//   Destructor
//------------------------
SubMatrixAlias::~SubMatrixAlias()
{
	// SubMatrixContainer will be deleted by MatrixAliasConstant
	// SubMatrixReadAccess will be deleted by MatrixAliasConstant
	// SubMatrixWriteAccess will be deleted by MatrixAlias

	#ifdef DEBUG_DESTRUCTOR
		printf("Destructor: ~SubMatrixAlias()\n");
	#endif
}


//-----------------------------------------
//
//          SquareMatrixAliasConsatnt
//
//-----------------------------------------

//-----------------------------------------
//          Constructor Functions
//-----------------------------------------


//------------------------
//   Blank Constructor
//------------------------
void SquareMatrixAliasConstant::_constructSquareMatrixAliasConstant()
{
	// Construct operators
	_constructSquareMatrixAliasConstantOperators();

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: SquareMatrixAliasConstant::Blank Constructor\n");
	#endif
}

//------------------------
//   Operator Constructor
//------------------------
void SquareMatrixAliasConstant::_constructSquareMatrixAliasConstantOperators()
{
	// Construct operators
	//sizeCompatable._constructSquareMatrixReadOperator(this);
	determinant._constructSquareMatrixReadOperator(this);
	determinant2._constructSquareMatrixReadOperator(this);
	cofactor._constructSquareMatrixReadOperator(this);
	inverse._constructSquareMatrixReadOperator(this);
	inverse2._constructSquareMatrixReadOperator(this);
	exponential._constructSquareMatrixReadOperator(this);
	luDecomposition._constructSquareMatrixReadOperator(this);
	luBackSubstitution._constructSquareMatrixReadOperator(this);
}

//------------------------
//   Destructor
//------------------------
SquareMatrixAliasConstant::~SquareMatrixAliasConstant()
{
	#ifdef DEBUG_DESTRUCTOR
		printf("Destructor: ~SquareMatrixAliasConstant()\n");
	#endif
}




//-----------------------------------------
//
//          SquareMatrixAlias
//
//-----------------------------------------

//-----------------------------------------
//          Constructor Functions
//-----------------------------------------


//------------------------
//   Blank Constructor
//------------------------
void SquareMatrixAlias::_constructSquareMatrixAlias()
{
	// Construct operators
	_constructSquareMatrixAliasOperators();

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: SquareMatrixAlias::Blank Constructor\n");
	#endif
}

//------------------------
//   Operator Constructor
//------------------------
void SquareMatrixAlias::_constructSquareMatrixAliasOperators()
{
	// Construct operators
	identity._constructSquareMatrixWriteOperator(this);
	directionCosine._constructSquareMatrixWriteOperator(this);
}

//------------------------
//   Destructor
//------------------------
SquareMatrixAlias::~SquareMatrixAlias()
{
	#ifdef DEBUG_DESTRUCTOR
		printf("Destructor: ~SquareMatrixAlias()\n");
	#endif
}



//-----------------------------------------
//
//          SquareMatrix
//
//-----------------------------------------

//-----------------------------------------
//          Constructor Functions
//-----------------------------------------

//---------------------------
//   Sized Constructor
//---------------------------
void SquareMatrix::_constructSquareMatrix()
{
	// Construct operators
	_constructSquareMatrixOperators();

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: SquareMatrix::Sized Constructor\n");
	#endif
}

//------------------------
//   Copy Constructor
//------------------------
void SquareMatrix::_constructSquareMatrix(const MatrixAliasConstant& copy)
{
	// Construct this class
	_constructSquareMatrix();

	// Copy information to this matrix
	equals(copy);

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: SquareMatrix::Copy Constructor\n");
	#endif
}

//------------------------
//   Operator Constructor
//------------------------
void SquareMatrix::_constructSquareMatrixOperators()
{
	// Construct operators
	equals._constructSquareMatrixWriteOperator(this);
	resize._constructSquareMatrixWriteOperator(this);
}


//------------------------
//   Destructor
//------------------------
SquareMatrix::~SquareMatrix()
{
	#ifdef DEBUG_DESTRUCTOR
		printf("Destructor: ~SquareMatrix()\n");
	#endif
}



//-----------------------------------------
//
//          RowVectorAliasConstant
//
//-----------------------------------------

//-----------------------------------------
//          Constructor Functions
//-----------------------------------------

//---------------------------
//   Blank Constructor
//---------------------------
void RowVectorAliasConstant::_constructRowVectorAliasConstant()
{
	// Construct operators
	_constructRowVectorAliasConstantOperators();

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: RowVectorAliasConstant::Blank Constructor\n");
	#endif
}

//------------------------
//   Operator Constructor
//------------------------
void RowVectorAliasConstant::_constructRowVectorAliasConstantOperators()
{
	//sizeCompatable._constructRowVectorReadOperator(this);
	cross._constructRowVectorReadOperator(this);
	dot._constructRowVectorReadOperator(this);
	direction._constructRowVectorReadOperator(this);
	getSize._constructRowVectorReadOperator(this);
}

//------------------------
//   Destructor
//------------------------
RowVectorAliasConstant::~RowVectorAliasConstant()
{
	#ifdef DEBUG_DESTRUCTOR
		printf("Destructor: ~RowVectorAliasConstant()\n");
	#endif
}

//-----------------------------------------
//
//          RowVectorAlias
//
//-----------------------------------------

//-----------------------------------------
//          Constructor Functions
//-----------------------------------------

//---------------------------
//   Blank Constructor
//---------------------------
void RowVectorAlias::_constructRowVectorAlias()
{
	// Construct operators
	_constructRowVectorAliasOperators();

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: RowVectorAlias::Blank Constructor\n");
	#endif
}

//------------------------
//   Operator Constructor
//------------------------
void RowVectorAlias::_constructRowVectorAliasOperators()
{
}

//------------------------
//   Destructor
//------------------------
RowVectorAlias::~RowVectorAlias()
{
	#ifdef DEBUG_DESTRUCTOR
		printf("Destructor: ~RowVectorAlias()\n");
	#endif
}


//-----------------------------------------
//
//          RowVector
//
//-----------------------------------------

//-----------------------------------------
//          Constructor Functions
//-----------------------------------------

//---------------------------
//   Blank Constructor
//---------------------------
void RowVector::_constructRowVector()
{
	// Construct operators
	_constructRowVectorOperators();

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: RowVector::Sized Constructor\n");
	#endif
}

//---------------------------
//   Copy Constructor
//---------------------------
void RowVector::_constructRowVector(const MatrixAliasConstant& copy)
{
	// Construct this class
	_constructRowVector();

	// Copy the information to this vector
	equals(copy);

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: RowVector::Copy Constructor\n");
	#endif
}

//------------------------
//   Operator Constructor
//------------------------
void RowVector::_constructRowVectorOperators()
{
	equals._constructRowVectorWriteOperator(this);
	resize._constructRowVectorWriteOperator(this);
}

//------------------------
//   Destructor
//------------------------
RowVector::~RowVector()
{
	#ifdef DEBUG_DESTRUCTOR
		printf("Destructor: ~RowVector()\n");
	#endif
}




//-----------------------------------------
//
//          ColumnVectorAliasConstant
//
//-----------------------------------------

//-----------------------------------------
//          Constructor Functions
//-----------------------------------------

//---------------------------
//   Blank Constructor
//---------------------------
void ColumnVectorAliasConstant::_constructColumnVectorAliasConstant()
{
	// Construct operators
	_constructColumnVectorAliasConstantOperators();

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: ColumnVectorAliasConstant::Blank Constructor\n");
	#endif
}

//------------------------
//   Operator Constructor
//------------------------
void ColumnVectorAliasConstant::_constructColumnVectorAliasConstantOperators()
{
	//sizeCompatable._constructColumnVectorReadOperator(this);
	cross._constructColumnVectorReadOperator(this);
	dot._constructColumnVectorReadOperator(this);
	direction._constructColumnVectorReadOperator(this);
	getSize._constructColumnVectorReadOperator(this);
}

//------------------------
//   Destructor
//------------------------
ColumnVectorAliasConstant::~ColumnVectorAliasConstant()
{
	#ifdef DEBUG_DESTRUCTOR
		printf("Destructor: ~ColumnVectorAliasConstant()\n");
	#endif
}





//-----------------------------------------
//
//          ColumnVectorAlias
//
//-----------------------------------------

//-----------------------------------------
//          Constructor Functions
//-----------------------------------------

//---------------------------
//   Blank Constructor
//---------------------------
void ColumnVectorAlias::_constructColumnVectorAlias()
{
	// Construct operators
	_constructColumnVectorAliasOperators();

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: ColumnVectorAlias::Blank Constructor\n");
	#endif
}

//------------------------
//   Operator Constructor
//------------------------
void ColumnVectorAlias::_constructColumnVectorAliasOperators()
{
}

//------------------------
//   Destructor
//------------------------
ColumnVectorAlias::~ColumnVectorAlias()
{
	#ifdef DEBUG_DESTRUCTOR
		printf("Destructor: ~ColumnVectorAlias()\n");
	#endif
}


//-----------------------------------------
//
//          ColumnVector
//
//-----------------------------------------

//-----------------------------------------
//          Constructor Functions
//-----------------------------------------

//---------------------------
//   Sized Constructor
//---------------------------
void ColumnVector::_constructColumnVector()
{
	// Construct operators
	_constructColumnVectorOperators();

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: ColumnVector::Sized Constructor\n");
	#endif
}

//---------------------------
//   Copy Constructor
//---------------------------
void ColumnVector::_constructColumnVector(const MatrixAliasConstant& copy)
{
	// Construct this class
	_constructColumnVector();

	// Copy the information to this vector
	equals(copy);

	#ifdef DEBUG_CONSTRUCTOR
		printf("Constructed: ColumnVector::Copy Constructor\n");
	#endif
}

//------------------------
//   Operator Constructor
//------------------------
void ColumnVector::_constructColumnVectorOperators()
{
	equals._constructColumnVectorWriteOperator(this);
	resize._constructColumnVectorWriteOperator(this);
}

//------------------------
//   Destructor
//------------------------
ColumnVector::~ColumnVector()
{
	#ifdef DEBUG_DESTRUCTOR
		printf("Destructor: ~ColumnVector()\n");
	#endif
}