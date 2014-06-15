//! \mainpage The MatrixClass Library
//!
//! \section intro Introduction
//! This class library is designed to make use of matrices and thier associated functions
//! using the C++ programming enviromnent. It is designed to be as flexible as possible in
//! both implementation and usage.
//!
//! \section implementation Implementation
//! The matrix classes and thier derivatives come in three main types:
//!
//! \li <b>Stand-alone</b> (e.g. \a Matrix, \a SquareMatrix, \a RowVector ...)
//! \li <b>Alias</b> (e.g. \a MatrixAlias, \a SquareMartixAlias, \a RowVectorAlias ...)
//! \li <b>Constant alias</b> (e.g. \a MatrixAliasConstant, \a SquareMartixAliasConstant, \a RowVectorAliasConstant ...)
//!
//! \subsection implementation_standalone Stand-Alone Classes
//! The stand-alone classes allocate and free thier own memory. They can be instantiated
//! in many ways:
//!
//! \code
//! Matrix A(2, 2);                 // 2x2 matrix
//! RowVector x(4);                 // 4 element row vector
//! ColumnVector y(ptr_to_data, 5); // 5 element column vector initiated with the values in an array
//! Matrix B(A);                    // New matrix the same size as A, and initiated with the same values
//! Matrix C = A;                   // New matrix the same size as A, and initiated with the same values
//! \endcode
//!
//! \subsection implementation_alias Alias Classes
//! The alias classes can be used to mask or alias another matrix object. This can be useful if you
//! wanted to reference a matrix in a different way, but it can be particularly useful if you
//! already have some data (say in an array), and you want to implement the functionality of
//! the matrix class on that data. For example:
//!
//! \code
//! void foo(double * data, int size)
//! {
//!     ColumnVectorAlias cva(data, size); // Use the data pointer to act as the storage for the new vector
//!
//!     // operations on cva...
//! }
//! \endcode
//!
//! Remember that you will be allocating your own memory for alias classes. In the above example
//! the \c data pointer must point to at least <tt>size*sizeof(double)</tt> bytes of allocated memory.
//!
//! \subsection implementation_constantalias Constant Alias Classes
//! In the situation where you are provided with read only data the constant alias class can be used
//! to provive read only functionality. For example:
//!
//! \code
//! void foo(const double * data, int size)
//! {
//!     RowVectorAliasConstant rvac(data, size); // Use the data pointer to act as read only storage for the new vector
//!
//!     // read operations on rvac...
//! }
//! \endcode
//!
//! \section usage Usage
//! The matrix class library has been designed to be as intuative to use as possible. The matrix classes,
//! and thier derived classes have certain operations available to them. Operatons are inherited or overridden
//! in derived classes (whichever make most sense), so an operation like \c transpose() which is available in
//! the \a Matrix class will also be available in its derived class \a SquareMatrix. However, a function like
//! \c inverse() will be available to the \a SquareMatrix class, but not to the ordinary \a Matrix class.
//!
//!	To use an operator for a matrix, just call the associated function:
//! \code
//!    Matrix A(3,3);
//!    Matrix B(3,3);
//!
//!    A.rand();            // Randomise the values of A
//!
//!    B = A.transpose();   // B becomes the transposed matrix of A
//! \endcode
//!
//! Although the matrix operations look to be member functions of the \a Matrix class, they are in fact
//! member \em objects. They are a special kind of object where each object has has its \c operator()
//! method overloaded. These special member objects are called "Matrix Operators", and they all inherit
//! from just two base classes: MatrixReadOperator and MatrixWriteOperator. The classes derived from
//! MatrixReadOperator provide the read functions for the \a Matrix classes, and (you've guessed it!) the
//! MatrixWriteOperator classes provide the write functions.
//!
//! Further derived classes, for example \a SquareMatrix, inherit the Matrix operations from Matrix,
//! but also include their own set of operator classes derived from \a SquareMatrixReadOperator and
//! \a SquareMatrixWriteOperator. Both of these inherit from MatrixReadOperator and MatrixWriteOperator
//! respectively.
//!
//! Obviously the AliasConstant classes only contain read operators, while the other classes contain
//! both read and write operators.
//!
//! For an exmaple, we can look at using a Matrix class, and a more specific SquareMatrix class. The SquareMatrix
//! class contains both the Matrix read and write operators, and also the SquareMatrix read and write operatiors.
//!
//! \code
//! Matrix m(10,5);                // 10x5 matrix
//! SquareMatrix sm(5);            // 5x5 square matrix
//!
//! m.set(1.0);                    // make all elements in m equal 1.0
//! m = m.multiply(5.34);          // multiply all elements in m by 5.34 and assign that back to m
//! sm = sm.inverse();             // make sm equal to its own inverse
//! sm = m.inverse();              // ERROR! m is not a square matrix
//! \endcode
//!
//! \subsection usage_standardoperators Standard Operators
//! There are many standard operators that have been overloaded to allow for a more readable code when using
//! the matrix class library. These operators include:
//!
//! \li <b>Round brackets () </b> - for accessing matrix elements
//! \li <b>Arithmetic operators +, -, *, / </b> - for performing aritthmetic operations with matricies
//! \li <b>Assignment operator= </b> - for assigning one matrix's values (and size) to another
//!
//! Other operators may be overloaded for more specific (derived) matrix types.
//!
//! Example:
//!
//! \code
//! // Implementing the state-space formula:
//! //
//! //     dx = Ax + Bu
//! //
//! ColumnVector stateEquation(ColumnVector x, ColumnVector u)
//! {
//! 	Matrix A(3,3);            // A matrix
//! 	Matrix B(3,2);            // B matrix
//! 	ColumnVector dx(3);       // state derivative vector
//!
//! 	// Create A & B matrices
//!     A(0,0) = 5; A(0,1) = 17; A(0,2) = 0.034;
//!     A(1,0) = 2.4;  // etc...
//!
//! 	dx = (A * x) + (B * u);   // Perform state equation
//!
//!     return dx;                // Return state vector
//! }
//! \endcode
//!
//! \subsection usage_morestandardoperators More on Standard Operators
//!	To give a little more insight to how the standard operators work it should
//! be explained that they do no more than simply call the relevant Matrix Operator
//! for the matrix to which they belong. Because of this, there are many Matrix Operators
//! that belong to matrix classes that the user might otherwise never know existed.
//! For every Standard Operator there will be a specific Matrix operator that is called,
//! Operators like:
//!
//! \li \c multiply(operand) - Multiplies the matrix (or derivative) by the operand.
//!	\li \c add(oparand) - Adds the matrix (or derivative) by the operand.
//! \li \c negative() - Performs a unary minus on the matrix (or derivative).
//! \li \c equals(operand) - Makes the matrix (or derivative) equal to its operand.
//! \li \c element(index) - Retrives the indexed element of the matrix.
//!
//! These operators are called inline whenever the relevant Standard Operator is called.
//! This means that the following code:
//!
//! \code
//! dx = (A * x) + (B * u);   // Perform state equation
//! \endcode
//!
//! Could equally have been written:
//! \code
//! dx.equals(A.multiply(x).add(B.multiply(u)));   // Perform state equation
//! \endcode
//!
//! From that, hopefully you can see the benefits of using Standard Operators!
//!
//! \todo \b DONE Add rest of operators
//! \todo \b DONE Add specific resize operators that only take one value for vectors and square matrices.
//! \todo Create exception class and replace error() functions.
//! \todo change return type for write operators (to return *this)
//! \todo Test constructors fully
//! \todo Test copy constructors fully.
//! \todo Test assignment operators fully
//! \todo Test SubMatrix class fully
//! \todo Test/fix luDecomp and related functons (and cofactor() )




#ifndef MATRIX_H
#define MATRIX_H

#define DEBUG_CONSTRUCTOR
#define DEBUG_DESTRUCTOR

#include "matrix_container.h"
#include "matrix_operator.h"
#include "matrix_access.h"

#include <iostream>

// Added by C. Robinson - forward definitions missing I believe
// Undefined types are not allowed in Visual Studio.
// Changed preprocessor #ifdef and #ifndef __MATRIX_H__ to MATRIX_H
// (apparently double underscore no longer supported)

//class Matrix;



//! \brief A read-only MatrixAlias class.
//! \author Lee Netherton
//!
//! The MatrixAliasConstant class provides a means to allow matrix functionality to otherwise
//! unaccesible read-only data.
//!
//! For example:
//!
//! \code
//! void foo(const double * readOnlyData, int rows, int columns)
//! {
//!     MatrixAliasConstant readOnlyMatrix(readOnlyData, rows, columns);
//!
//!
//!     // matrix operations on readOnlyMatrix....
//! }
//! \endcode
//!
class MatrixAliasConstant
{
	public:

		//------------------------------------------------------------
		//         Members
		//------------------------------------------------------------

		//! \brief MatrixContainer for this matrix
		//!
		//! The containter holds all the storage information for the matrix.
		MatrixContainer * m_matrixContainer;

		//! \brief Read access handle for the matrix
		//!
		//! Provides basic read funcions for all the operators
		MatrixReadAccess * m_matrixReadAccess;

		//------------------------------------------------------------
		//         MatrixOperator Members
		//------------------------------------------------------------

		//! Element operator
		MRO_Element element;

		//! Addition operator
		MRO_Add add;

		//! Subtration operator
		MRO_Subtract subtract;

		//! Negative operator (reverses sign)
		MRO_Negative negative;

		//! Multiplication operator
		MRO_Multiply multiply;

		//! Division operator
		MRO_Divide divide;

		//! Prints matrix contents to screen
		MRO_Print print;

		//! Prints matrix contents in a form that can be pasted into MATLAB
		MRO_PrintMatlabFriendly printM;

		//! Return a subMatrixAliasConstant of a portion of this matrix
		MRO_SubMatrixAliasConstant subMatrix;

		//! Return true if operand's size is equal to this matrix's size
		MRO_SizeEqual sizeEqual;

		//! Returns true if matrix is square
		MRO_IsSquareMatrix isSquareMatrix;

		//! Returns true if matrix is square
		MRO_IsRowVector isRowVector;

		//! Returns true if matrix is square
		MRO_IsColumnVector isColumnVector;

		//! Returns the transpose of this matrix
		MRO_Transpose transpose;

		//! Returns an absolute version of this matrix
		MRO_Absolute absolute;

		//! Returns a column vector which is the row sum of this matrix
		MRO_RowSum rowSum;

		//! Returns a row vector which is the column sum of this matrix
		MRO_ColumnSum columnSum;

		//! Returns the maximum value in this matrix
		MRO_Maximum maximum;

		//! Returns the minimum value in this matrix
		MRO_Minimum minimum;

		//! Returns the infinity norm value of this matrix
		MRO_InfinityNorm infinityNorm;

		//! Returns the frobenius norm value of this matrix
		MRO_FrobeniusNorm frobeniusNorm;

		//! Returns a matrix of this matrix with its elements squared
		MRO_SquaredElements squaredElements;


		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Default constructor.
		//!
		//! Creates a MatrixAliasConstant shell. The MatrixContainer and MatrixReadAccess
		//! handles can be set later using the constructor function _constructMatrixAliasConstant()
		//MatrixAliasConstant() {_constructMatrixAliasConstant(0, 0, 0);}

		//! \brief Pointer constructor
		//!
		//! To create a read-only matrix that will access a pre-available data array.
		//! \param data Pointer to data array. This will be the data storage for the matrix.
		//! \param rows Number of rows the matrix has.
		//! \param columns Number of columns the matrix has.
		MatrixAliasConstant(const double * data, const unsigned int rows, const unsigned int columns) {_constructMatrixAliasConstant(data, rows, columns);}

		//! \brief Alias constructor
		//!
		//! To create a read-only matrix that will alias another matrix.
		//! \param alias Pointer to a matrix which this matris will alias.
		MatrixAliasConstant(const MatrixAliasConstant* alias) {_constructMatrixAliasConstant(alias->getDataPointer(), alias->getRows(), alias->getColumns());}

		//! \brief Copy constructor
		//!
		//! Used when creating a MatrixAliasConstant matrix from another.
		//! \code MatrixAliasConstant newMAC(oldMAC); \endcode
		//! \param copy Reference to another matrix.
		MatrixAliasConstant(const MatrixAliasConstant& copy) {_constructMatrixAliasConstant(copy.getDataPointer(), copy.getRows(), copy.getColumns());}

		//! \brief External container and access member constructor
		//!
		//! Used when the MatrixContainer and MatrixReadAccess members have been created
		//! externally (for example, in a submatrix). The MatrixAliasConstant shell is
		//! populated with operators and the handles are set.
		//! \param container Pointer to MatrixContainer
		//! \param access Pointer to Matrix ReadAccess
		MatrixAliasConstant(MatrixContainer * container, MatrixReadAccess * access) {_constructMatrixAliasConstant(container, access);}

		//! \brief External container and access member constructor
		//!
		//! Used when the MatrixContainer and MatrixReadAccess members have been created
		//! externally (for example, in a submatrix). The MatrixAliasConstant shell is
		//! populated with operators and the handles are set.
		//! \param access Pointer to Matrix ReadAccess
		//! \param data Ponter to the data array
		//! \param rows Number of rows the matrix has
		//! \param columns Munber od columns the matrix has
		MatrixAliasConstant(MatrixReadAccess * access, const double * data, const unsigned int rows, const unsigned int columns) {_constructMatrixAliasConstant(access, data, rows, columns);}


	protected:
		//------------------------------------------------------------
		//         Constructor Functions
		//------------------------------------------------------------

		//! \brief Pointer constructor
		//!
		//! Sets the pointers to the MatrixContainer and MatrixReadOperator members
		void _constructMatrixAliasConstant(const double * data, const unsigned int rows, const unsigned int columns);

		//! \brief Copy constructor
		//!
		//! Copies the pointers to the MatrixContainer and MatrixReadOperator members
		//void _constructMatrixAliasConstant(const MatrixAliasConstant& copy);

		//! \brief Member constructor (external)
		//!
		//! Sets the pointers to the MatrixContainer and MatrixReadOperator members from an extenal source.
		void _constructMatrixAliasConstant(MatrixContainer * container, MatrixReadAccess * access);

		//! \brief Member constructor (external - just container)
		//!
		//! Sets the pointers to the MatrixContainer from an extenal source and creates a MatrixReadOperator member.
		void _constructMatrixAliasConstant(MatrixContainer * container);

		//! \brief Member constructor (external - just access)
		//!
		//! Sets the pointers to the MatrixReadOperator from an extenal source and creates a MatrixContainer member.
		void _constructMatrixAliasConstant(MatrixReadAccess * access, const double * data, const unsigned int rows, const unsigned int columns);

	private:

		//! \brief Operator constructor
		//!
		//! Constructs all the MatrixAliasConstant operator objects
		void _constructMatrixReadOperators();

	public:

		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief MatrixAliasConstant Destructor
		//!
		//! Virtual - the lowest derived class will always need to be called, as they
		//! all allocate memory in ther own ways.
		virtual ~MatrixAliasConstant();


		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Element operator (two indexes)
		const double& operator()(const unsigned int row, const unsigned int column) const {return element(row,column);}

		//! Element operator (one index)
		const double& operator()(const unsigned int index) const {return element(index);}

		//! Addition operator
		Matrix operator+(const MatrixAliasConstant& operand) const {return add(operand);}

		//! Subtration operator
		Matrix operator-(const MatrixAliasConstant& operand) const {return subtract(operand);}

		//! Negative operator
		Matrix operator-() const {return negative();}

		//! Multiplication of two matrices
		Matrix operator*(const MatrixAliasConstant& operand) const {return multiply(operand);}

		//! Multiplication of matrix by a scalar
		Matrix operator*(const double& operand) const {return multiply(operand);}

		//! Multiplication of scalar by a matrix
		friend Matrix operator*(const double &operand1, const MatrixAliasConstant &operand2) {return operand2.multiply(operand1);}

		//! Division by a scalar
		Matrix operator/(const double &operand) const {return divide(operand);}

		//! Assignment operator
		//!
		//! Overload default assignment operation to stop bad things happening.
		//! Simply return object unchanged.
		MatrixAliasConstant& operator=(const MatrixAliasConstant& copy) {m_matrixReadAccess->error("Tried to assign to a constant matrix\n");return *this;}

		//------------------------------------------------------------
		//         Other members
		//------------------------------------------------------------

		//! Get the number of rows the matrix has
		const unsigned int getRows() const {return m_matrixContainer->getRows();}

		//! Get the number of columns the matrix has
		const unsigned int getColumns() const {return m_matrixContainer->getColumns();}

		//! Return a pointer to the data array
		const double * getDataPointer() const {return m_matrixContainer->getDataPointer();}
};



//! \brief An alias of a Matrix class, or to utilise a pre-available data array.
//! \author Lee Netherton
//!
//! The MatrixAlias class provides a means to allow the aliasing of matrices, and
//! also the flexibility to use external data storage made available be the user.
//!
//! For example:
//!
//! \code
//! MatrixAlias giveMeAMatrix(int rows, int columns)
//! {
//!     double * dataPointer = new double[rows*columns];   // allocate some new memory
//!
//!     MatrixAlias newMA(dataPointer, rows, columns);     // create new MatrixAlias
//!
//!     return newMA
//! }
//! \endcode
//!
class MatrixAlias : virtual public MatrixAliasConstant
{
	public:

		//------------------------------------------------------------
		//         Members
		//------------------------------------------------------------

		//! \brief Write access handle for the matrix
		//!
		//! Provides basic write funcions for all the write operators
		MatrixWriteAccess * m_matrixWriteAccess;


		//------------------------------------------------------------
		//         MatrixOperator Members
		//------------------------------------------------------------

		//! Element operator
		MWO_Element element;

		//! Equals operator (makes the content of this matrix equal the values of another)
		MWO_EqualsElementCopy equals;

		//! Zero all the elements in the matrix
		MWO_Zero zero;

		//! Sets all the values in the matrix equal to a specified value
		MWO_Set set;

		//! Normalises the matrix
		MWO_Normalise normalise;

		//! Randomises all the values in the matrix to a values between 0 and specified value
		MWO_Randomise rand;

		//! Returns a subMatrixAlias of a portion of this matrix
		MWO_SubMatrixAlias subMatrix;


		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Default constructor.
		//!
		//! Creates a MatrixAlias shell. The MatrixContainer, MatrixReadAccess, and MatrixWriteAccess
		//! handles can be set later using the constructor function _constructMatrixAlias()
		//MatrixAlias() {_constructMatrixAlias();}

		//! \brief Pointer constructor
		//!
		//! To create a matrix that will access a pre-available data array.
		//! \param data Pointer to data array. This will be the data storage for the matrix.
		//! \param rows Number of rows the matrix has.
		//! \param columns Number of columns the matrix has.
		MatrixAlias(const double * data, const unsigned int rows, const unsigned int columns) : MatrixAliasConstant(data, rows, columns) {_constructMatrixAlias();}

		//! \brief Alias constructor
		//!
		//! To create a matrix that will alias another matrix.
		//! \param alias Pointer to a matrix which this matris will alias.
		MatrixAlias(const MatrixAliasConstant* alias) : MatrixAliasConstant(alias->getDataPointer(), alias->getRows(), alias->getColumns()) {_constructMatrixAlias();}

		//! \brief Copy constructor
		//!
		//! Used when creating a MatrixAliasConstant matrix from any other matrix.
		//! \param copy Reference to another matrix.
		MatrixAlias(const MatrixAliasConstant& copy) : MatrixAliasConstant(copy.getDataPointer(), copy.getRows(), copy.getColumns()) {_constructMatrixAlias();}

		//! \brief Copy constructor
		//!
		//! Used when creating a MatrixAliasConstant matrix from another.
		//! \code MatrixAliasConstant newMA(oldMA); \endcode
		//! \param copy Reference to another matrix.
		MatrixAlias(const MatrixAlias& copy) : MatrixAliasConstant(copy.getDataPointer(), copy.getRows(), copy.getColumns()) {_constructMatrixAlias();}

		//! \brief External container and access member constructor
		//!
		//! Used when the MatrixContainer and matrix access members have been created
		//! externally (for example, in a submatrix). The MatrixAlias shell is
		//! populated with operators and the handles are set.
		//! \param container Pointer to MatrixContainer
		//! \param r_access Pointer to MatrixReadAccess
		//! \param w_access Pointer to MatrixWriteAccess
		MatrixAlias(MatrixContainer * container, MatrixReadAccess * r_access, MatrixWriteAccess * w_access) : MatrixAliasConstant(container, r_access) {_constructMatrixAlias(w_access);}


	protected:
		//------------------------------------------------------------
		//         Constructor Functions
		//------------------------------------------------------------

		//! \brief Pointer constructor
		//!
		//! Sets the pointers to the MatrixWriteOperator member, and calls
		//! MatrixAliasConstant's constructor function
		void _constructMatrixAlias();

		//! \brief Member constructor (external - just access)
		//!
		//! Sets the pointers to the MatrixWriteOperator from an extenal source and passes rest to _constructMatrixAliasConstant().
		void _constructMatrixAlias(MatrixWriteAccess * w_access);


	private:

		//! \brief Operator constructor
		//!
		//! Constructs all the MatrixAlias operator objects
		void _constructMatrixWriteOperators();

	public:
		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief MatrixAlias Destructor
		//!
		//! Virtual - the lowest derived class will always need to be called, as they
		//! all allocate memory in ther own ways.
		virtual ~MatrixAlias();


		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		MatrixAlias& operator=(const MatrixAliasConstant& copy) {equals(copy);return *this;}

		//! Assignment operator
		MatrixAlias& operator=(const MatrixAlias& copy) {return operator=((MatrixAliasConstant&)copy);}

		//! Element operator (two indexes)
		double& operator()(const unsigned int row, const unsigned int column) const {return element(row,column);}

		//! Element operator (one index)
		double& operator()(const unsigned int index) const {return element(index);}

		//! Addition assignment operator
		MatrixAlias& operator+=(const MatrixAliasConstant& operand);

		//! Subtraction assignment operator
		MatrixAlias& operator-=(const MatrixAliasConstant& operand);

		//! Multiplication assignment operator
		MatrixAlias& operator*=(const MatrixAliasConstant& operand);

		//! Multiplication assignment operator
		MatrixAlias& operator*=(const double& operand);

		//! Division assignment operator
		MatrixAlias& operator/=(const double& operand);
};


//! \brief The standard matrix class.
//! \author Lee Netherton
//!
//! The Matrix class provides the user with a pre made matrix. It will allocate
//! its own memory, and is provided with a full complement of matrix operators.
//!
//! For example:
//!
//! \code
//! Matrix A(3,3);        // Make a matrix called A
//! Matrix B(3,3);        // Make a matrix called B
//!
//! // Fill the matrices with something useful
//!
//! Matrix C = A * B;     // Matrix C is the product of the two matrices
//!
//! \endcode
//!
class Matrix : virtual public MatrixAlias
{
	public:

		//------------------------------------------------------------
		//         MatrixOperator Members
		//------------------------------------------------------------

		//! Equals operator - allows matrix to resize if it is made equal to one of a different size
		MWO_EqualsElementCopyResize equals;

		//! Resize operator Resize matrix (allocate new memory if number of elements changes).
		MWO_Resize resize;


		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Default constructor.
		//!
		//! Creates a MatrixAlias shell. The MatrixContainer, MatrixReadAccess, and MatrixWriteAccess
		//! handles can be set later using the constructor function _constructMatrixAlias()
		Matrix() :
			MatrixAliasConstant(new double[1], 1, 1),
			MatrixAlias(0, 1, 1)
			{_constructMatrix();}

		//! \brief Sized constructor.
		//!
		//! Creates a new matrix of a given size.
		//! \param rows Number of rows matrix has
		//! \param columns Number of columns matrix has
		Matrix(const unsigned int rows, const unsigned int columns) :
			MatrixAliasConstant(new double[rows*columns], rows,columns),
			MatrixAlias(0, rows, columns)
			{_constructMatrix();}

		//! \brief Base class copy constructor
		//!
		//! Makes a copy of any another matrix.
		//! \param copy Reaference to matrix to copy
		Matrix(const MatrixAliasConstant& copy) :
			MatrixAliasConstant(new double[copy.getRows()*copy.getColumns()], copy.getRows(), copy.getColumns()),
			MatrixAlias(0, copy.getRows(), copy.getColumns())
			{_constructMatrix(copy);}

		//! \brief Copy constructor
		//!
		//! Makes a copy of another matrix.
		//! \param copy Reaference to matrix to copy
		Matrix(const Matrix& copy) :
			MatrixAliasConstant(new double[copy.getRows()*copy.getColumns()], copy.getRows(), copy.getColumns()),
			MatrixAlias(0, copy.getRows(), copy.getColumns())
			{_constructMatrix(copy);}


	protected:
		//------------------------------------------------------------
		//         Constructor Functions
		//------------------------------------------------------------

		//! \brief Sized constructor
		//!
		//! Allocates some memory, and then calls MatrixAlias' constructor function
		void _constructMatrix();

		//! \brief Copy constructor
		//!
		//! Allocates some memory, and then calls MatrixAlias' constructor function.
		//! Finally, copys data in from copied matrix
		//! \param copy Matrix to copy
		void _constructMatrix(const MatrixAliasConstant& copy);

	private:

		//! \brief Operator constructor
		//!
		//! Constructs all the Matrix operator objects
		void _constructMatrixWriteOperators();

	public:
		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief Matrix Destructor
		//!
		//! Virtual - the lowest derived class will always need to be called, as they
		//! all allocate memory in ther own ways.
		virtual ~Matrix();


		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		Matrix& operator=(const MatrixAliasConstant& copy) {equals(copy); return *this;}

		//! Assignment operator
		Matrix& operator=(const Matrix& copy) {return operator=((MatrixAliasConstant&)copy);}

};


//! \brief Accesses just a portion of a matrix.
//! \author Lee Netherton
//!
//! The SubMatrixAliasConstant class can be useful for "masking" out, all but
//! the useful parts of a matrix. Suppose you had a large matrix, but you only
//! wanted to see the values in the top left corner of it:
//! \code
//!    void printJustASmallBit(Matrix& large_matrix)
//!    {
//!        SubMatrixAliasConstant small(large_matrix,0,4,0,4); // SubMatrix is a 5x5 matrix aliasing
//!                                                            // the top corner of the large_matrix
//!
//!        small.print();        // print out the small section of the large_matrix
//!    }
//! \endcode
//!
class SubMatrixAliasConstant : virtual public MatrixAliasConstant
{
	public:
		//------------------------------------------------------------
		//         Members
		//------------------------------------------------------------

		//! \brief A pointer to the SubMatrixContainer
		//!
		//! Only used to be able to make a copy of the SubMatrixContainer.
		SubMatrixContainer * m_subMatrixContainer;

		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Default constructor.
		//!
		//! Creates a SubMatrixAliasConstant shell. The SubMatrixContainer and SubMatrixReadAccess
		//! handles can be set later using the constructor function _constructSubMatrixAliasConstant()
		//SubMatrixAliasConstant() {_constructSubMatrixAliasConstant();}


		//! \brief Pointer constructor.
		//!
		//! Creates a SubMatrixAliasConstant from a pointer to another matrix. The other values
		//! are the start and end rows and columns for the submatrix.
		//! For example, supposre you had an 8x8 matrix, and you wanted to make a submatrix alias
		//! the center 2x2 portion of it:
		//!
		//! \code
		//!      Column Start (1)
		//!             |Column End (2)
		//!             |  |
		//!  (0)  [ a | b  c | d ]
		//!       [--------------]
		//!  (1)  [ e | f  g | h ]-- Row Start (1)
		//!       [   |      |   ]
		//!  (2)  [ i | j  k | l ]-- Row End (2)
		//!       [--------------]
		//!  (3)  [ m | n  o | p ]
		//!
		//!        (0) (1)(2) (3)
		//! \endcode
		//!
		//! Remembering that the matricies are zero indexed, the code to prodice such a submatrix
		//! is as follows:
		//! \code
		//! Matrix A(8,8);                          // Create our 8x8 matrix
		//!
		//! SubMatrixAliasConstant subA(A,1,2,1,2); // Create the sub matrix
		//!
		//! subA.print();                           // Will produce: [ f g ]
		//!                                                          [ j k ]
		//! \endcode
		//!
		//! \param original Pointer to the matrix to be aliased
		//! \param rowStart The index of the row to start the submatrix on
		//! \param rowEnd The index of the row to stop the submatrix on
		//! \param columnStart The index of the column to start the submatrix on
		//! \param columnEnd The index of the column to stop the submatrix on
		SubMatrixAliasConstant(const MatrixAliasConstant * original, const unsigned int rowStart, const unsigned int rowEnd, const unsigned int columnStart, const unsigned int columnEnd) :
			MatrixAliasConstant(m_subMatrixContainer = new SubMatrixContainer(original->m_matrixContainer, rowStart, rowEnd, columnStart, columnEnd), new SubMatrixReadAccess(this))
			{_constructSubMatrixAliasConstant();}

		//! \brief Reference constructor.
		//!
		//! Creates a SubMatrixAliasConstant from a reference to another matrix. The other values
		//! are the start and end rows and columns for the submatrix.
		//! \param original Reference to the matrix to be aliased
		//! \param rowStart The index of the row to start the submatrix on
		//! \param rowEnd The index of the row to stop the submatrix on
		//! \param columnStart The index of the column to start the submatrix on
		//! \param columnEnd The index of the column to stop the submatrix on
		SubMatrixAliasConstant(const MatrixAliasConstant& original, const unsigned int rowStart, const unsigned int rowEnd, const unsigned int columnStart, const unsigned int columnEnd) :
			MatrixAliasConstant(m_subMatrixContainer = new SubMatrixContainer(original.m_matrixContainer, rowStart, rowEnd, columnStart, columnEnd), new SubMatrixReadAccess(this))
			{_constructSubMatrixAliasConstant();}

		//! \brief Copy constructor
		//!
		//! Makes a copy of another submatrix.
		//! \param copy Reaference to submatrix to copy
		SubMatrixAliasConstant(const SubMatrixAliasConstant& copy) :
			MatrixAliasConstant(m_subMatrixContainer = new SubMatrixContainer(*copy.m_subMatrixContainer), new SubMatrixReadAccess(this))
			{_constructSubMatrixAliasConstant();}


	protected:
		//------------------------------------------------------------
		//         Constructor Functions
		//------------------------------------------------------------

		//! \brief Container constructor
		//!
		//! Creates a new SubMatrixContainer and SubMatrixReadAccess, and passes the handles
		//! back to MatrixAliasConstant
		void _constructSubMatrixAliasConstant();

		//! \brief SubContainer constructor
		//!
		//! Creates a new SubMatrixContainer from a copy of an existing one, and a
		//! new SubMatrixReadAccess, then passes the handles
		//! back to MatrixAliasConstant
		//! \param original_subContainer Pointer to the subMatrix's container class (to make a copy of)
		//void _constructSubMatrixAliasConstant(const SubMatrixContainer * original_subContainer);

	public:
		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief SubMatrixAliasConstant Destructor
		//!
		//! Virtual - the lowest derived class will always need to be called, as they
		//! all allocate memory in ther own ways.
		virtual ~SubMatrixAliasConstant();

		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		SubMatrixAliasConstant& operator=(const MatrixAliasConstant& copy) {m_matrixReadAccess->error("Tried to assign to a constant sub-matrix\n");return *this;}

		//! Assignment operator
		SubMatrixAliasConstant& operator=(const SubMatrixAliasConstant& copy) {return operator=((MatrixAliasConstant&)copy);}


};


//! \brief Accesses just a portion of a matrix (and provides write access).
//! \author Lee Netherton
//!
//! The SubMatrixAlias class can be useful for "masking" out, all but
//! the useful parts of a matrix. One particulary useful feature of
//! the SubMatrixAlias class comes about when you use them in conjunction
//! with the MatrixAlias::subMatrixAlias() operator function. Suppose you
//! have two matrices, and you wanted to make one portion of one matrix
//! equal to a portion of the other. The two matrices look like this:
//! \code
//!  Matrix 1:           Matrix 2:
//!
//!  [ a  b  c  d ]      [ q  r  s  t ]
//!  [ e  f  g  h ]      [ u  v  w  x ]
//!  [ i  j  k  l ]      [ y  z  1  2 ]
//!  [ m  n  o  p ]      [ 3  4  5  6 ]
//! \endcode
//! If we wanted to make the top right portion of Matrix 1 equal to the top right
//! corner of Matrix 2 we could do:
//! \code
//! mat1.subMatrixAlias(0,1,2,3) = mat2.subMatrixAlias(0,1,2,3);
//! \endcode
//! The matrices would then look like this:
//! \code
//!  Matrix 1:           Matrix 2:
//!
//!  [ a  b  s  t ]      [ q  r  s  t ]
//!  [ e  f  w  x ]      [ u  v  w  x ]
//!  [ i  j  k  l ]      [ y  z  1  2 ]
//!  [ m  n  o  p ]      [ 3  4  5  6 ]
//! \endcode
class SubMatrixAlias : public SubMatrixAliasConstant, public MatrixAlias
{
	public:

		//! \brief Pointer constructor.
		//!
		//! Creates a SubMatrixAlias from a pointer to another matrix. The other values
		//! are the start and end rows and columns for the submatrix.
		//! See SubMatrixAliasConstant() for more details.
		//!
		//! \param original Pointer to the matrix to be aliased
		//! \param rowStart The index of the row to start the submatrix on
		//! \param rowEnd The index of the row to stop the submatrix on
		//! \param columnStart The index of the column to start the submatrix on
		//! \param columnEnd The index of the column to stop the submatrix on
		SubMatrixAlias(const MatrixAliasConstant * original, const unsigned int rowStart, const unsigned int rowEnd, const unsigned int columnStart, const unsigned int columnEnd) :
			MatrixAliasConstant(m_subMatrixContainer = new SubMatrixContainer(original->m_matrixContainer, rowStart, rowEnd, columnStart, columnEnd), new SubMatrixReadAccess(this)),
			MatrixAlias(0, 0, new SubMatrixWriteAccess(this)),
			SubMatrixAliasConstant(original, rowStart, rowEnd, columnStart, columnEnd)
			{_constructSubMatrixAlias();}

		//! \brief Reference constructor.
		//!
		//! Creates a SubMatrixAlias from a reference to another matrix. The other values
		//! are the start and end rows and columns for the submatrix.
		//! \param original Reference to the matrix to be aliased
		//! \param rowStart The index of the row to start the submatrix on
		//! \param rowEnd The index of the row to stop the submatrix on
		//! \param columnStart The index of the column to start the submatrix on
		//! \param columnEnd The index of the column to stop the submatrix on
		SubMatrixAlias(const MatrixAliasConstant& original, const unsigned int rowStart, const unsigned int rowEnd, const unsigned int columnStart, const unsigned int columnEnd) :
			MatrixAliasConstant(m_subMatrixContainer = new SubMatrixContainer(original.m_matrixContainer, rowStart, rowEnd, columnStart, columnEnd), new SubMatrixReadAccess(this)),
			MatrixAlias(0, 0, new SubMatrixWriteAccess(this)),
			SubMatrixAliasConstant(&original, rowStart, rowEnd, columnStart, columnEnd)
			{_constructSubMatrixAlias();}

		//! \brief Copy constructor
		//!
		//! Makes a copy of another submatrix.
		//! \param copy Reaference to submatrix to copy
		SubMatrixAlias(const SubMatrixAlias& copy) :
			MatrixAliasConstant(m_subMatrixContainer = new SubMatrixContainer(*copy.m_subMatrixContainer), new SubMatrixReadAccess(this)),
			MatrixAlias(0, 0, new SubMatrixWriteAccess(this)),
			SubMatrixAliasConstant(copy)
			{_constructSubMatrixAlias();}

	protected:
		//------------------------------------------------------------
		//         Constructor Functions
		//------------------------------------------------------------

		//! \brief Container constructor
		//!
		//! Creates a new SubMatrixContainer and SubMatrixWriteAccess, and passes the handles
		//! back to SubMatrixAliasConstant
		void _constructSubMatrixAlias();

		//! \brief SubContainer constructor
		//!
		//! Creates a new SubMatrixContainer from a copy of an existing one, and a
		//! new SubMatrixWriteAccess, then passes the handles
		//! back to SubMatrixAliasConstant
		//! \param original_subContainer Pointer to the subMatrix's container class (to make a copy of)
		//void _constructSubMatrixAlias(const SubMatrixContainer * original_subContainer);

	public:

		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief SubMatrixAlias Destructor
		//!
		//! Virtual - the lowest derived class will always need to be called, as they
		//! all allocate memory in ther own ways.
		virtual ~SubMatrixAlias();

		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		SubMatrixAlias& operator=(const MatrixAliasConstant& copy) {equals(copy);return *this;}

		//! Assignment operator
		SubMatrixAlias& operator=(const SubMatrixAlias& copy) {return operator=((MatrixAliasConstant&)copy);}

};


//! \brief A read-only SquareMatrixAlias class.
//! \author Lee Netherton
//!
//! The SquareMatrixAliasConstant class provides all the functionality from the MatrixAliasConstant
//! class, but add specific functions intended for square matricies (like inverse(), and determinant()).
//!
class SquareMatrixAliasConstant : virtual public MatrixAliasConstant
{
	public:
		//------------------------------------------------------------
		//         MatrixOperator Members
		//------------------------------------------------------------

		//! Returns the determinant of this matrix (uses LU decomposition)
		SqMRO_DeterminantLUDecomp determinant;

		//! Returns the determinant of this matrix (uses basic algorithm)
		SqMRO_DeterminantBasic determinant2;

		//! Returns the cofactor of an element
		SqMRO_Cofactor cofactor;

		//! Returns the inverse of this matrix (uses LU decomposition)
		SqMRO_InverseLUDecomp inverse;

		//! Returns the inverse of this matrix (uses basic algorithm)
		SqMRO_InverseBasic inverse2;

		//! Returns the matrix exponential using irreducible Pade approximation.
		SqMRO_Exponential exponential;

		//! Returns an LU decomposition of this matrix
		SqMRO_LUDecomposition luDecomposition;

		//! Returns an LU back substitution of this matrix
		SqMRO_LUBackSubstitution luBackSubstitution;


		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Default constructor.
		//!
		//! Creates a SquareMatrixAliasConstant shell. The MatrixContainer and MatrixReadAccess
		//! handles can be set later using the constructor function _constructSquareMatrixAliasConstant()
		//SquareMatrixAliasConstant() {_constructSquareMatrixAliasConstant();}

		//! \brief Pointer constructor
		//!
		//! To create a read-only square matrix that will access a pre-available data array.
		//! \param data Pointer to data array. This will be the data storage for the matrix.
		//! \param size Number of rows and columns the matrix has.
		SquareMatrixAliasConstant(const double * data, const unsigned int size) : MatrixAliasConstant(data, size, size) {_constructSquareMatrixAliasConstant();}

		//! \brief Alias constructor
		//!
		//! To create a read-only square matrix that will alias another matrix.
		//! \param alias Pointer to a matrix which this matris will alias.
		SquareMatrixAliasConstant(const MatrixAliasConstant* alias) : MatrixAliasConstant(alias->getDataPointer(), alias->getRows(), alias->getColumns()) {_constructSquareMatrixAliasConstant();}

		//! \brief Base class copy constructor
		//!
		//! Used when creating a SquareMatrixAliasConstant matrix from another.
		//! \code SquareMatrixAliasConstant newSqMAC(oldSqMAC); \endcode
		//! \param copy Reference to another matrix.
		SquareMatrixAliasConstant(const MatrixAliasConstant& copy) : MatrixAliasConstant(copy.getDataPointer(), copy.getRows(), copy.getColumns()) {_constructSquareMatrixAliasConstant();}

		//! \brief Copy constructor
		//!
		//! Used when creating a MatrixAliasConstant matrix from another. Calls
		//! base class copy constructor
		//! \param copy Reference to another matrix.
		SquareMatrixAliasConstant(const SquareMatrixAliasConstant& copy) : MatrixAliasConstant(copy.getDataPointer(), copy.getRows(), copy.getColumns()) {_constructSquareMatrixAliasConstant();}

	protected:
		//------------------------------------------------------------
		//         Constructor Functions
		//------------------------------------------------------------

		//! \brief Blank constructor
		//!
		//! Just constructs SquareMatrixAliasConstant operators, and goes no further.
		void _constructSquareMatrixAliasConstant();

	private:
		//! \brief Operator constructor
		//!
		//! Constructs all the SquareMatrixAliasConstant operator objects
		void _constructSquareMatrixAliasConstantOperators();

	public:
		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief SquareMatrixAliasConstant Destructor
		//!
		//! Virtual - the lowest derived class will always need to be called, as they
		//! all allocate memory in ther own ways.
		virtual ~SquareMatrixAliasConstant();

		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		SquareMatrixAliasConstant& operator=(const MatrixAliasConstant& copy) {m_matrixReadAccess->error("Tried to assign to a constant square matrix\n");return *this;}

		//! Assignment operator
		SquareMatrixAliasConstant& operator=(const SquareMatrixAliasConstant& copy) {return operator=((MatrixAliasConstant&)copy);}


};


//! \brief A SquareMatrixAlias class.
//! \author Lee Netherton
//!
//! The SquareMatrixAlias class provides all the functionality from the MatrixAlias
//! class, but add specific functions intended for square matricies (like inverse(), and determinant()).
//! It also has specific square matrix write functions like identity().
//!
class SquareMatrixAlias : virtual public MatrixAlias, public SquareMatrixAliasConstant
{
	public:
		//------------------------------------------------------------
		//         MatrixOperator Members
		//------------------------------------------------------------

		//! Makes this matrix an identity matrix
		SqMWO_Identity identity;

		//! Makes this matrix direction cosine matrix
		SqMWO_DirectionCosine directionCosine;

		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Default constructor.
		//!
		//! Creates a SquareMatrixAlias shell. The MatrixContainer, MatrixReadAccess and MatrixWriteAccess
		//! handles can be set later using the constructor function _constructSquareMatrixAlias()
		//SquareMatrixAlias() {_constructSquareMatrixAlias();}

		//! \brief Pointer constructor
		//!
		//! To create a square matrix that will access a pre-available data array.
		//! \param data Pointer to data array. This will be the data storage for the matrix.
		//! \param size Number of rows and columns the matrix has.
		SquareMatrixAlias(const double * data, const unsigned int size) :
			MatrixAliasConstant(data, size, size),
			MatrixAlias(data, size, size),
			SquareMatrixAliasConstant(data, size)
			{_constructSquareMatrixAlias();}

		//! \brief Alias constructor
		//!
		//! To create a square matrix that will alias another matrix.
		//! \param alias Pointer to a matrix which this matrix will alias.
		SquareMatrixAlias(const MatrixAliasConstant* alias) :
			MatrixAliasConstant(alias->getDataPointer(), alias->getRows(), alias->getColumns()),
			MatrixAlias(alias->getDataPointer(), alias->getRows(), alias->getColumns()),
			SquareMatrixAliasConstant(alias->getDataPointer(), alias->getRows())
			{_constructSquareMatrixAlias();}

		//! \brief Base class copy constructor
		//!
		//! Used when creating a SquareMatrixAlias matrix from another matrix.
		//! \code SquareMatrixAlias newSqMA(oldSqMA); \endcode
		//! \param copy Reference to another matrix.
		SquareMatrixAlias(const MatrixAliasConstant& copy) :
			MatrixAliasConstant(copy.getDataPointer(), copy.getRows(), copy.getColumns()),
			MatrixAlias(copy.getDataPointer(), copy.getRows(), copy.getColumns()),
			SquareMatrixAliasConstant(copy.getDataPointer(), copy.getRows())
			{_constructSquareMatrixAlias();}

		//! \brief Copy constructor
		//!
		//! Used when creating a SquareMatrixAlias matrix from another. Calls
		//! base class copy constructor
		//! \param copy Reference to another matrix.
		SquareMatrixAlias(const SquareMatrixAlias& copy) :
			MatrixAliasConstant(copy.getDataPointer(), copy.getRows(), copy.getColumns()),
			MatrixAlias(copy.getDataPointer(), copy.getRows(), copy.getColumns()),
			SquareMatrixAliasConstant(copy.getDataPointer(), copy.getRows())
			{_constructSquareMatrixAlias();}

	protected:
		//------------------------------------------------------------
		//         Constructor Functions
		//------------------------------------------------------------

		//! \brief Blank constructor
		//!
		//! Just constructs SquareMatrixAlias and SquareMatrixAliasConstant operators, and goes no further.
		void _constructSquareMatrixAlias();

	private:
		//! \brief Operator constructor
		//!
		//! Constructs all the SquareMatrixAlias operator objects
		void _constructSquareMatrixAliasOperators();

	public:
		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief SquareMatrixAlias Destructor
		//!
		//! Virtual - the lowest derived class will always need to be called, as they
		//! all allocate memory in ther own ways.
		virtual ~SquareMatrixAlias();

		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		SquareMatrixAlias& operator=(const MatrixAliasConstant& copy) {equals(copy);return *this;}

		//! Assignment operator
		SquareMatrixAlias& operator=(const SquareMatrixAlias& copy) {return operator=((MatrixAliasConstant&)copy);}

};


//! \brief The standard SquareMatrix class.
//! \author Lee Netherton
//!
//! The SquareMatrix class provides the user with a pre made square matrix. It will allocate
//! its own memory, and is provided with a full complement of matrix and square matrix operators.
//!
class SquareMatrix : public Matrix, public SquareMatrixAlias
{
	public:
		//------------------------------------------------------------
		//         MatrixOperator Members
		//------------------------------------------------------------

		//! Checks to see if the operand is compatable (i.e. square) and then copies data in.
		SqMWO_EqualsElementCopyResize equals;

		//! Resize operator Resize matrix (allocate new memory if number of elements changes).
		SqMWO_Resize resize;

		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Default constructor.
		//!
		//! Creates a Matrix shell.
		SquareMatrix() :
			MatrixAliasConstant(new double[1], 1, 1),
			MatrixAlias(0, 1, 1),
			Matrix(1, 1),
			SquareMatrixAlias(0, 1)
			{_constructSquareMatrix();}

		//! \brief Sized constructor.
		//!
		//! Creates a new square matrix of a given size.
		//! \param size Number of rows and columns matrix has
		SquareMatrix(const unsigned int size) :
			MatrixAliasConstant(new double[size*size], size, size),
			MatrixAlias(0, size, size),
			Matrix(size, size),
			SquareMatrixAlias(0, size)
			{_constructSquareMatrix();}

		//! \brief Base class copy constructor
		//!
		//! Makes a copy of any another matrix.
		//! \param copy Reaference to matrix to copy
		SquareMatrix(const MatrixAliasConstant& copy) :
			MatrixAliasConstant(new double[copy.getRows()*copy.getColumns()], copy.getRows(),copy.getColumns()),
			MatrixAlias(0, copy.getRows(),copy.getColumns()),
			Matrix(copy.getRows(),copy.getColumns()),
			SquareMatrixAlias(0, copy.getRows())
			{_constructSquareMatrix(copy);}

		//! \brief Copy constructor
		//!
		//! Makes a copy of another matrix.
		//! \param copy Reaference to matrix to copy
		SquareMatrix(const SquareMatrix& copy) :
			MatrixAliasConstant(new double[copy.getRows()*copy.getColumns()], copy.getRows(),copy.getColumns()),
			MatrixAlias(0, copy.getRows(),copy.getColumns()),
			Matrix(copy.getRows(),copy.getColumns()),
			SquareMatrixAlias(0, copy.getRows())
			{_constructSquareMatrix(copy);}

	protected:
		//------------------------------------------------------------
		//         Constructor Functions
		//------------------------------------------------------------

		//! \brief Sized constructor.
		//!
		//! Allocates some memory, and calls the Matrix constructor function and
		//! the SquareMatrixAlias blank constructor function.
		void _constructSquareMatrix();

		//! \brief Copy constructor
		//!
		//! Allocates some memory, and calls the Matrix constructor function and
		//! the SquareMatrixAlias blank constructor function.
		//! Finally, copys data in from copied matrix
		//! \param copy Matrix to copy
		void _constructSquareMatrix(const MatrixAliasConstant& copy);

	private:
		//! \brief Operator constructor
		//!
		//! Constructs all the SquareMatrix operator objects
		void _constructSquareMatrixOperators();

	public:

		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief SquareMatrix Destructor
		//!
		//! Virtual - the lowest derived class will always need to be called, as they
		//! all allocate memory in ther own ways.
		virtual ~SquareMatrix();

		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		SquareMatrix& operator=(const MatrixAliasConstant& copy) {equals(copy);return *this;}

		//! Assignment operator
		SquareMatrix& operator=(const SquareMatrix& copy) {return operator=((MatrixAliasConstant&)copy);}


};

//! \brief A read-only RowVectorAlias class.
//! \author Lee Netherton
//!
//! The RowVectorAliasConstant class provides all the functionality from the MatrixAliasConstant
//! class, but add specific functions intended for row vectors.
//!
class RowVectorAliasConstant : virtual public MatrixAliasConstant
{
	public:
		//------------------------------------------------------------
		//         MatrixOperator Members
		//------------------------------------------------------------

		//! Returns the cross product of this vector
		RVRO_CrossProduct cross;

		//! Returns the dot product of this vector
		RVRO_DotProduct dot;

		//! Returns a normalised version of this vector
		RVRO_Direction direction;

		//! Returns the size of this vector
		RVRO_GetSize getSize;

		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Default constructor.
		//!
		//! Creates a RowVectorAliasConstant shell. The MatrixContainer and MatrixReadAccess
		//! handles can be set later using the constructor function _constructRowVectorAliasConstant()
		//RowVectorAliasConstant() {_constructRowVectorAliasConstant();}

		//! \brief Pointer constructor
		//!
		//! To create a read-only row vector that will access a pre-available data array.
		//! \param data Pointer to data array. This will be the data storage for the matrix.
		//! \param size Number of columns the matrix has.
		RowVectorAliasConstant(const double * data, const unsigned int size) :
			MatrixAliasConstant(data, 1, size)
			{_constructRowVectorAliasConstant();}

		//! \brief Alias constructor
		//!
		//! To create a read-only row vector that will alias another matrix.
		//! \param alias Pointer to a matrix which this matris will alias.
		RowVectorAliasConstant(const MatrixAliasConstant* alias) :
			MatrixAliasConstant(alias->getDataPointer(), 1, alias->getColumns())
			{_constructRowVectorAliasConstant();}

		//! \brief Base class copy constructor
		//!
		//! Used when creating a RowVectorAliasConstant matrix from another.
		//! \param copy Reference to another matrix.
		RowVectorAliasConstant(const MatrixAliasConstant& copy) :
			MatrixAliasConstant(copy.getDataPointer(), 1, copy.getColumns())
			{_constructRowVectorAliasConstant();}

		//! \brief Copy constructor
		//!
		//! Used when creating a MatrixAliasConstant matrix from another. Calls
		//! base class copy constructor
		//! \param copy Reference to another matrix.
		RowVectorAliasConstant(const RowVectorAliasConstant& copy) :
			MatrixAliasConstant(copy.getDataPointer(), 1, copy.getColumns())
			{_constructRowVectorAliasConstant();}

	protected:
		//------------------------------------------------------------
		//         Constructor Functions
		//------------------------------------------------------------

		//! \brief Blank constructor
		//!
		//! Just constructs RowVectorAliasConstant operators, and goes no further.
		void _constructRowVectorAliasConstant();

	private:
		//! \brief Operator constructor
		//!
		//! Constructs all the RowVectorAliasConstant operator objects
		void _constructRowVectorAliasConstantOperators();

	public:
		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief RowVectorAliasConstant Destructor
		//!
		//! Virtual - the lowest derived class will always need to be called, as they
		//! all allocate memory in ther own ways.
		virtual ~RowVectorAliasConstant();

		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		RowVectorAliasConstant& operator=(const MatrixAliasConstant& copy) {m_matrixReadAccess->error("Tried to assign to a constant vector\n");return *this;}

		//! Assignment operator
		RowVectorAliasConstant& operator=(const RowVectorAliasConstant& copy) {return operator=((MatrixAliasConstant&)copy);}

};

//! \brief A RowVectorAlias class.
//! \author Lee Netherton
//!
//! The RowVectorAlias class provides all the functionality from the MatrixAlias
//! class, but add specific functions intended for row vectors.
//! It also has specific row vector write functions.
//!
class RowVectorAlias : public RowVectorAliasConstant, virtual public MatrixAlias
{
	public:
		//------------------------------------------------------------
		//         MatrixOperator Members
		//------------------------------------------------------------

		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Default constructor.
		//!
		//! Creates a RowVectorAlias shell. The MatrixContainer, MatrixReadAccess and MatrixWriteAccess
		//! handles can be set later using the constructor function _constructRowVectorAlias()
		//RowVectorAlias() {_constructRowVectorAlias();}

		//! \brief Pointer constructor
		//!
		//! To create a row vector that will access a pre-available data array.
		//! \param data Pointer to data array. This will be the data storage for the matrix.
		//! \param size Number of columns the vector has.
		RowVectorAlias(const double * data, const unsigned int size) :
			MatrixAliasConstant(data, 1, size),
			MatrixAlias(data, 1, size),
			RowVectorAliasConstant(data, size)
			{_constructRowVectorAlias();}

		//! \brief Alias constructor
		//!
		//! To create a row vector that will alias another matrix.
		//! \param alias Pointer to a matrix which this vector will alias.
		RowVectorAlias(const MatrixAliasConstant* alias) :
			MatrixAliasConstant(alias->getDataPointer(), 1, alias->getColumns()),
			MatrixAlias(alias->getDataPointer(), 1, alias->getColumns()),
			RowVectorAliasConstant(alias->getDataPointer(), alias->getColumns())
			{_constructRowVectorAlias();}

		//! \brief Base class copy constructor
		//!
		//! Used when creating a RowVectorAlias matrix from another matrix.
		//! \param copy Reference to another matrix.
		RowVectorAlias(const MatrixAliasConstant& copy) :
			MatrixAliasConstant(copy.getDataPointer(), 1, copy.getColumns()),
			MatrixAlias(copy.getDataPointer(), 1, copy.getColumns()),
			RowVectorAliasConstant(copy.getDataPointer(), copy.getColumns())
			{_constructRowVectorAlias();}

		//! \brief Copy constructor
		//!
		//! Used when creating a RowVectorAlias matrix from another. Calls
		//! base class copy constructor
		//! \param copy Reference to another row vector.
		RowVectorAlias(const RowVectorAlias& copy) :
			MatrixAliasConstant(copy.getDataPointer(), 1, copy.getColumns()),
			MatrixAlias(copy.getDataPointer(), 1, copy.getColumns()),
			RowVectorAliasConstant(copy.getDataPointer(), copy.getColumns())
			{_constructRowVectorAlias();}


	protected:
		//------------------------------------------------------------
		//         Constructor Functions
		//------------------------------------------------------------

		//! \brief Blank constructor
		//!
		//! Just constructs RowVectorAlias and RowVectorAliasConstant operators, and goes no further.
		void _constructRowVectorAlias();

	private:
		//! \brief Operator constructor
		//!
		//! Constructs all the RowVectorAlias operator objects
		void _constructRowVectorAliasOperators();

	public:
		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief RowVectorAlias Destructor
		//!
		//! Virtual - the lowest derived class will always need to be called, as they
		//! all allocate memory in ther own ways.
		virtual ~RowVectorAlias();


		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		RowVectorAlias& operator=(const MatrixAliasConstant& copy) {equals(copy);return *this;}

		//! Assignment operator
		RowVectorAlias& operator=(const RowVectorAlias& copy) {return operator=((MatrixAliasConstant&)copy);}
};


//! \brief The standard RowVector class.
//! \author Lee Netherton
//!
//! The RowVector class provides the user with a pre made row vector. It will allocate
//! its own memory, and is provided with a full complement of matrix and row vector operators.
//!
class RowVector : public Matrix, public RowVectorAlias
{
	public:
		//------------------------------------------------------------
		//         MatrixOperator Members
		//------------------------------------------------------------

		//! Checks to see if the operand is compatable (i.e. a row vector) and then copies data in.
		RVWO_EqualsElementCopyResize equals;

		//! Resize operator Resize matrix (allocate new memory if number of elements changes).
		RVWO_Resize resize;

		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Default constructor.
		//!
		//! Creates a Matrix shell.
		RowVector() :
			MatrixAliasConstant(new double[1], 1, 1),
			MatrixAlias(0, 1, 1),
			Matrix(1, 1),
			RowVectorAlias(0, 1)
			{_constructRowVector();}

		//! \brief Sized constructor.
		//!
		//! Creates a new row vector of a given size.
		//! \param size Number of columns matrix has
		RowVector(const unsigned int size) :
			MatrixAliasConstant(new double[size], 1, size),
			MatrixAlias(0, 1, size),
			Matrix(1, size),
			RowVectorAlias(0, size)
			{_constructRowVector();}

		//! \brief Base class copy constructor
		//!
		//! Makes a copy of any another matrix.
		//! \param copy Reaference to matrix to copy
		RowVector(const MatrixAliasConstant& copy) :
			MatrixAliasConstant(new double[copy.getColumns()], 1, copy.getColumns()),
			MatrixAlias(0, 1, copy.getColumns()),
			Matrix(1, copy.getColumns()),
			RowVectorAlias(0, copy.getColumns())
			{_constructRowVector(copy);}

		//! \brief Copy constructor
		//!
		//! Makes a copy of another matrix.
		//! \param copy Reaference to matrix to copy
		RowVector(RowVector& copy) :
			MatrixAliasConstant(new double[copy.getColumns()], 1, copy.getColumns()),
			MatrixAlias(0, 1, copy.getColumns()),
			Matrix(1, copy.getColumns()),
			RowVectorAlias(0, copy.getColumns())
			{_constructRowVector(copy);}

	protected:
		//------------------------------------------------------------
		//         Constructor Functions
		//------------------------------------------------------------

		//! \brief Sized constructor.
		//!
		//! Allocates some memory, and calls the Matrix constructor function and
		//! the RowVectorAlias blank constructor function.
		void _constructRowVector();

		//! \brief Copy constructor
		//!
		//! Allocates some memory, and calls the Matrix constructor function and
		//! the RowVectorAlias blank constructor function.
		//! Finally, copys data in from copied matrix
		//! \param copy Matrix to copy
		void _constructRowVector(const MatrixAliasConstant& copy);

	private:
		//! \brief Operator constructor
		//!
		//! Constructs all the SquareMatrix operator objects
		void _constructRowVectorOperators();

	public:
		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief RowVector Destructor
		//!
		//! Virtual - the lowest derived class will always need to be called, as they
		//! all allocate memory in ther own ways.
		virtual ~RowVector();

		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		RowVector& operator=(const MatrixAliasConstant& copy) {equals(copy);return *this;}

		//! Assignment operator
		RowVector& operator=(const RowVector& copy) {return operator=((MatrixAliasConstant&)copy);}

};


//! \brief A read-only ColumnVectorAlias class.
//! \author Lee Netherton
//!
//! The ColumnVectorAliasConstant class provides all the functionality from the MatrixAliasConstant
//! class, but add specific functions intended for column vectors.
//!
class ColumnVectorAliasConstant : virtual public MatrixAliasConstant
{
	public:
		//------------------------------------------------------------
		//         MatrixOperator Members
		//------------------------------------------------------------

		//! Returns the cross product of this vector
		CVRO_CrossProduct cross;

		//! Returns the dot product of this vector
		CVRO_DotProduct dot;

		//! Returns a normalised version of this vector
		CVRO_Direction direction;

		//! Returns the size of this vector
		CVRO_GetSize getSize;

		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Default constructor.
		//!
		//! Creates a ColumnVectorAliasConstant shell. The MatrixContainer and MatrixReadAccess
		//! handles can be set later using the constructor function _constructColumnVectorAliasConstant()
		//ColumnVectorAliasConstant() {_constructColumnVectorAliasConstant();}

		//! \brief Pointer constructor
		//!
		//! To create a read-only column vector that will access a pre-available data array.
		//! \param data Pointer to data array. This will be the data storage for the matrix.
		//! \param size Number of rows the matrix has.
		ColumnVectorAliasConstant(const double * data, const unsigned int size) :
			MatrixAliasConstant(data, size, 1)
			{_constructColumnVectorAliasConstant();}

		//! \brief Alias constructor
		//!
		//! To create a read-only column vector that will alias another matrix.
		//! \param alias Pointer to a matrix which this matris will alias.
		ColumnVectorAliasConstant(const MatrixAliasConstant* alias) :
			MatrixAliasConstant(alias->getDataPointer(), alias->getRows(), 1)
			{_constructColumnVectorAliasConstant();}

		//! \brief Base class copy constructor
		//!
		//! Used when creating a ColumnVectorAliasConstant matrix from another.
		//! \param copy Reference to another matrix.
		ColumnVectorAliasConstant(const MatrixAliasConstant& copy) :
			MatrixAliasConstant(copy.getDataPointer(), copy.getRows(), 1)
			{_constructColumnVectorAliasConstant();}

		//! \brief Copy constructor
		//!
		//! Used when creating a MatrixAliasConstant matrix from another. Calls
		//! base class copy constructor
		//! \param copy Reference to another matrix.
		ColumnVectorAliasConstant(const ColumnVectorAliasConstant& copy) :
			MatrixAliasConstant(copy.getDataPointer(), copy.getRows(), 1)
			{_constructColumnVectorAliasConstant();}

	protected:
		//------------------------------------------------------------
		//         Constructor Functions
		//------------------------------------------------------------

		//! \brief Blank constructor
		//!
		//! Just constructs ColumnVectorAliasConstant operators, and goes no further.
		void _constructColumnVectorAliasConstant();

	private:
		//! \brief Operator constructor
		//!
		//! Constructs all the ColumnVectorAliasConstant operator objects
		void _constructColumnVectorAliasConstantOperators();

	public:
		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief ColumnVectorAliasConstant Destructor
		//!
		//! Virtual - the lowest derived class will always need to be called, as they
		//! all allocate memory in ther own ways.
		virtual ~ColumnVectorAliasConstant();

		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		ColumnVectorAliasConstant& operator=(const MatrixAliasConstant& copy) {m_matrixReadAccess->error("Tried to assign to a constant vector\n");return *this;}

		//! Assignment operator
		ColumnVectorAliasConstant& operator=(const ColumnVectorAliasConstant& copy) {return operator=((MatrixAliasConstant&)copy);}

};

//! \brief A ColumnVectorAlias class.
//! \author Lee Netherton
//!
//! The ColumnVectorAlias class provides all the functionality from the MatrixAlias
//! class, but add specific functions intended for column vectors.
//! It also has specific column vector write functions.
//!
class ColumnVectorAlias : virtual public ColumnVectorAliasConstant, virtual public MatrixAlias
{
	public:
		//------------------------------------------------------------
		//         MatrixOperator Members
		//------------------------------------------------------------

		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Default constructor.
		//!
		//! Creates a ColumnVectorAlias shell. The MatrixContainer, MatrixReadAccess and MatrixWriteAccess
		//! handles can be set later using the constructor function _constructColumnVectorAlias()
		//ColumnVectorAlias() {_constructColumnVectorAlias();}

		//! \brief Pointer constructor
		//!
		//! To create a column vector that will access a pre-available data array.
		//! \param data Pointer to data array. This will be the data storage for the matrix.
		//! \param size Number of rows the vector has.
		ColumnVectorAlias(const double * data, const unsigned int size) :
			MatrixAliasConstant(data, size, 1),
			MatrixAlias(data, size, 1),
			ColumnVectorAliasConstant(data, size)
			{_constructColumnVectorAlias();}

		//! \brief Alias constructor
		//!
		//! To create a column vector that will alias another matrix.
		//! \param alias Pointer to a matrix which this vector will alias.
		ColumnVectorAlias(const MatrixAliasConstant* alias) :
			MatrixAliasConstant(alias->getDataPointer(), alias->getRows(), 1),
			MatrixAlias(alias->getDataPointer(), alias->getRows(), 1),
			ColumnVectorAliasConstant(alias->getDataPointer(), alias->getRows())
			{_constructColumnVectorAlias();}

		//! \brief Base class copy constructor
		//!
		//! Used when creating a ColumnVectorAlias matrix from another matrix.
		//! \param copy Reference to another matrix.
		ColumnVectorAlias(const MatrixAliasConstant& copy) :
			MatrixAliasConstant(copy.getDataPointer(), copy.getRows(), 1),
			MatrixAlias(copy.getDataPointer(), copy.getRows(), 1),
			ColumnVectorAliasConstant(copy.getDataPointer(), copy.getRows())
			{_constructColumnVectorAlias();}

		//! \brief Copy constructor
		//!
		//! Used when creating a ColumnVectorAlias matrix from another. Calls
		//! base class copy constructor
		//! \param copy Reference to another column vector.
		ColumnVectorAlias(const ColumnVectorAlias& copy) :
			MatrixAliasConstant(copy.getDataPointer(), copy.getRows(), 1),
			MatrixAlias(copy.getDataPointer(), copy.getRows(), 1),
			ColumnVectorAliasConstant(copy.getDataPointer(), copy.getRows())
			{_constructColumnVectorAlias();}

	protected:
		//------------------------------------------------------------
		//         Constructor Functions
		//------------------------------------------------------------

		//! \brief Blank constructor
		//!
		//! Just constructs ColumnVectorAlias and ColumnVectorAliasConstant operators, and goes no further.
		void _constructColumnVectorAlias();

	private:
		//! \brief Operator constructor
		//!
		//! Constructs all the ColumnVectorAlias operator objects
		void _constructColumnVectorAliasOperators();

	public:
		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief ColumnVectorAlias Destructor
		//!
		//! Virtual - the lowest derived class will always need to be called, as they
		//! all allocate memory in ther own ways.
		virtual ~ColumnVectorAlias();


		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		ColumnVectorAlias& operator=(const MatrixAliasConstant& copy) {equals(copy);return *this;}

		//! Assignment operator
		ColumnVectorAlias& operator=(const ColumnVectorAlias& copy) {return operator=((MatrixAliasConstant&)copy);}
};


//! \brief The standard ColumnVector class.
//! \author Lee Netherton
//!
//! The ColumnVector class provides the user with a pre made column vector. It will allocate
//! its own memory, and is provided with a full complement of matrix and column vector operators.
//!
class ColumnVector : public Matrix, public ColumnVectorAlias
{
	public:
		//------------------------------------------------------------
		//         MatrixOperator Members
		//------------------------------------------------------------

		//! Checks to see if the operand is compatable (i.e. a column vector) and then copies data in.
		CVWO_EqualsElementCopyResize equals;

		//! Resize operator Resize matrix (allocate new memory if number of elements changes).
		CVWO_Resize resize;

		//------------------------------------------------------------
		//         Constructors
		//------------------------------------------------------------

		//! \brief Default constructor.
		//!
		//! Creates a Matrix shell.
		ColumnVector() :
			MatrixAliasConstant(new double[1], 1, 1),
			MatrixAlias(0, 1, 1),
			Matrix(1, 1),
			ColumnVectorAliasConstant(0, 1),
			ColumnVectorAlias(0, 1)
			{_constructColumnVector();}

		//! \brief Sized constructor.
		//!
		//! Creates a new column vector of a given size.
		//! \param size Number of rows matrix has
		ColumnVector(const unsigned int size) :
			MatrixAliasConstant(new double[size], size, 1),
			MatrixAlias(0, size, 1),
			Matrix(size, 1),
			ColumnVectorAliasConstant(0, size),
			ColumnVectorAlias(0, size)
			{_constructColumnVector();}

		//! \brief Base class copy constructor
		//!
		//! Makes a copy of any another matrix.
		//! \param copy Reaference to matrix to copy
		ColumnVector(const MatrixAliasConstant& copy) :
			MatrixAliasConstant(new double[copy.getRows()], copy.getRows(), 1),
			MatrixAlias(0, copy.getRows(), 1),
			Matrix(copy.getRows(), 1),
			ColumnVectorAliasConstant(0, copy.getRows()),
			ColumnVectorAlias(0, copy.getRows())
			{_constructColumnVector(copy);}

		//! \brief Copy constructor
		//!
		//! Makes a copy of another matrix.
		//! \param copy Reaference to matrix to copy
		ColumnVector(ColumnVector& copy) :
			MatrixAliasConstant(new double[copy.getRows()], copy.getRows(), 1),
			MatrixAlias(0, copy.getRows(), 1),
			Matrix(copy.getRows(), 1),
			ColumnVectorAliasConstant(0, copy.getRows()),
			ColumnVectorAlias(0, copy.getRows())
			{_constructColumnVector(copy);}

	protected:
		//------------------------------------------------------------
		//         Constructor Functions
		//------------------------------------------------------------

		//! \brief Sized constructor.
		//!
		//! Allocates some memory, and calls the Matrix constructor function and
		//! the ColumnVectorAlias blank constructor function.
		void _constructColumnVector();

		//! \brief Copy constructor
		//!
		//! Allocates some memory, and calls the Matrix constructor function and
		//! the ColumnVectorAlias blank constructor function.
		//! Finally, copys data in from copied matrix
		//! \param copy Matrix to copy
		void _constructColumnVector(const MatrixAliasConstant& copy);

	private:
		//! \brief Operator constructor
		//!
		//! Constructs all the SquareMatrix operator objects
		void _constructColumnVectorOperators();

	public:
		//------------------------------------------------------------
		//         Destructor
		//------------------------------------------------------------

		//! \brief ColumnVector Destructor
		//!
		//! Virtual - the lowest derived class will always need to be called, as they
		//! all allocate memory in ther own ways.
		virtual ~ColumnVector();

		//------------------------------------------------------------
		//         Overloaded Operators
		//------------------------------------------------------------

		//! Base class assignment operator
		ColumnVector& operator=(const MatrixAliasConstant& copy) {equals(copy);return *this;}

		//! Assignment operator
		ColumnVector& operator=(const ColumnVector& copy) {return operator=((MatrixAliasConstant&)copy);}

};


#endif // MATRIX_H