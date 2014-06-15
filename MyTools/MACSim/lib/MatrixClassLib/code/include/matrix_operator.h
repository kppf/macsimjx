#ifndef __MATRIX_OPERATOR_H__
#define __MATRIX_OPERATOR_H__

#include "matrix_access.h"

#include <iostream>

// Forward define a few classes
class MatrixAliasConstant;
class MatrixAlias;
class Matrix;

class SubMatrixAliasConstant;
class SubMatrixAlias;

class SquareMatrixAliasConstant;
class SquareMatrixAlias;
class SquareMatrix;

class RowVectorAliasConstant;
class RowVectorAlias;
class RowVector;

class ColumnVectorAliasConstant;
class ColumnVectorAlias;
class ColumnVector;

//--------------------------------------------------------------
//				Base classes
//--------------------------------------------------------------

//! \brief Base class for MatrixReadOperators.
//! \author Lee Netherton
//!
//! A MatrixReadOperator is a class which will perform a read operation on a
//! matrix. The MatrixReadOperator class is never instantiated directly, but
//! serves as a base for derived operator classes. It provides basic read operatons
//! for its derivatives.
//!
class MatrixReadOperator
{
	protected:

		//! Pointer to owner matrix
		MatrixAliasConstant * m_thisMatrix;


	public:

		//! \brief Default Constructor
		//!
		//! Creates an empty operator class which can then be more full constructed
		//! using _constructMatrixReadOperator()
		MatrixReadOperator() {}

		//! \brief Full Constructor
		//!
		//! Creates an operator class which takes and stores a pointer to an owner matrix
		//! \param matrixAliasConstant Pointer to owner matrix
		MatrixReadOperator(MatrixAliasConstant * matrixAliasConstant) : m_thisMatrix(matrixAliasConstant) {}

		//! \brief Manual Constructor
		//!
		//! Constructs the class manually by setting the owner pointer
		//! \param matrixAliasConstant Pointer to owner matrix
		void _constructMatrixReadOperator(MatrixAliasConstant * matrixAliasConstant) {m_thisMatrix = matrixAliasConstant;}

		//! Returns the number of rows the matrix has
		const unsigned int getRows() const;

		//! Returns the number of columns the matrix has
		const unsigned int getColumns() const;

		//! Returns the a pointer to the matrix data array
		const double * getDataPointer() const;

		//! Returns a read-only reference to the data member at specified position
		//! \param row Row position of desired element (zero indexed)
		//! \param column Column position of desired element (zero indexed)
		const double& element(const unsigned int row, const unsigned int column) const;

		//! Returns a read-only reference to the data member at specified position
		//! \param index Row-wise position of element (zero-indexed)
		const double& element(const unsigned int index) const;

		//! For flagging errors - to be depreciated.
		void error(const char* str) const;

};


//! \brief Base class for MatrixWriteOperators.
//! \author Lee Netherton
//!
//! A MatrixWriteOperator is a class which will perform a write operation on a
//! matrix. The MatrixWriteOperator class is never instantiated directly, but
//! serves as a base for derived operator classes. It provides basic write operatons
//! for its derivatives.
//!
class MatrixWriteOperator
{
	protected:

		//! Pointer to owner matrix
		MatrixAlias * m_thisMatrix;

	public:

		//! \brief Default Constructor
		//!
		//! Creates an empty operator class which can then be more full constructed
		//! using _constructMatrixWriteOperator()
		MatrixWriteOperator() {}

		//! \brief Full Constructor
		//!
		//! Creates an operator class which takes and stores a pointer to an owner matrix
		//! \param matrixAlias Pointer to owner matrix
		MatrixWriteOperator(MatrixAlias * matrixAlias) : m_thisMatrix(matrixAlias) {}

		//! \brief Manual Constructor
		//!
		//! Constructs the class manually by setting the owner pointer
		//! \param matrixAlias Pointer to owner matrix
		void _constructMatrixWriteOperator(MatrixAlias * matrixAlias) {m_thisMatrix = matrixAlias;}

		//! Returns the number of rows the matrix has
		const unsigned int getRows() const;

		//! Returns the number of columns the matrix has
		const unsigned int getColumns() const;

		//! Returns the a pointer to the matrix data array
		double * getDataPointer() const;

		//! \brief Sets the data pointer
		void setDataPointer(double * data) const;

		//! \brief Sets the number of rows
		void setRows(const unsigned int num) const;

		//! \brief Sets the number of columns
		void setColumns(const unsigned int num) const;

		//! Returns a writable reference to the data member at specified position
		//! \param row Row position of desired element (zero indexed)
		//! \param column Column position of desired element (zero indexed)
		double& element(const unsigned int row, const unsigned int column) const;

		//! Returns a writable reference to the data member at specified position
		//! \param index Row-wise position of element (zero-indexed)
		double& element(const unsigned int index) const;

		//! For flagging errors - to be depreciated.
		void error(const char* str) const;

};

//! \brief Base class for SquareMatrixReadOperators.
//! \author Lee Netherton
//!
//! Most importantly provides m_thisMatrix with the right
//! kind of pointer.
//!
class SquareMatrixReadOperator : public MatrixReadOperator
{
	protected:

		//! Pointer to owner matrix
		SquareMatrixAliasConstant * m_thisMatrix;

	public:
		//! \brief Default Constructor
		//!
		//! Creates an empty operator class which can then be more full constructed
		//! using _constructSquareMatrixReadOperator()
		SquareMatrixReadOperator() {}

		//! \brief Full Constructor
		//!
		//! Creates an operator class which takes and stores a pointer to an owner matrix
		//! \param squareMatrixAliasConstant Pointer to owner matrix
		SquareMatrixReadOperator(SquareMatrixAliasConstant * squareMatrixAliasConstant) :
			MatrixReadOperator((MatrixAliasConstant *)squareMatrixAliasConstant),
			m_thisMatrix(squareMatrixAliasConstant)
			{}

		//! \brief Manual Constructor
		//!
		//! Constructs the class manually by setting the owner pointer
		//! \param squareMatrixAliasConstant Pointer to owner matrix
		void _constructSquareMatrixReadOperator(SquareMatrixAliasConstant * squareMatrixAliasConstant)
		{
			_constructMatrixReadOperator((MatrixAliasConstant *)squareMatrixAliasConstant);

			m_thisMatrix = squareMatrixAliasConstant;
		}
};

//! \brief Base class for SquareMatrixWriteOperators.
//! \author Lee Netherton
//!
//! Most importantly provides m_thisMatrix with the right
//! kind of pointer.
//!
class SquareMatrixWriteOperator : public MatrixWriteOperator
{
	protected:

		//! Pointer to owner matrix
		SquareMatrixAlias * m_thisMatrix;

	public:
		//! \brief Default Constructor
		//!
		//! Creates an empty operator class which can then be more full constructed
		//! using _constructSquareMatrixWriteOperator()
		SquareMatrixWriteOperator() {}

		//! \brief Full Constructor
		//!
		//! Creates an operator class which takes and stores a pointer to an owner matrix
		//! \param squareMatrixAlias Pointer to owner matrix
		SquareMatrixWriteOperator(SquareMatrixAlias * squareMatrixAlias) :
			MatrixWriteOperator((MatrixAlias *)squareMatrixAlias),
			m_thisMatrix(squareMatrixAlias)
			{}

		//! \brief Manual Constructor
		//!
		//! Constructs the class manually by setting the owner pointer
		//! \param squareMatrixAlias Pointer to owner matrix
		void _constructSquareMatrixWriteOperator(SquareMatrixAlias * squareMatrixAlias)
		{
			_constructMatrixWriteOperator((MatrixAlias *)squareMatrixAlias);

			m_thisMatrix = squareMatrixAlias;
		}
};

//! \brief Base class for RowVectorReadOperators.
//! \author Lee Netherton
//!
//! Most importantly provides m_thisMatrix with the right
//! kind of pointer.
//!
class RowVectorReadOperator : public MatrixReadOperator
{
	protected:

		//! Pointer to owner matrix
		RowVectorAliasConstant * m_thisMatrix;

	public:
		//! \brief Default Constructor
		//!
		//! Creates an empty operator class which can then be more full constructed
		//! using _constructRowVectorReadOperator()
		RowVectorReadOperator() {}

		//! \brief Full Constructor
		//!
		//! Creates an operator class which takes and stores a pointer to an owner matrix
		//! \param rowVectorAliasConstant Pointer to owner matrix
		RowVectorReadOperator(RowVectorAliasConstant * rowVectorAliasConstant) :
			MatrixReadOperator((MatrixAliasConstant *)rowVectorAliasConstant),
			m_thisMatrix(rowVectorAliasConstant)
			{}

		//! \brief Manual Constructor
		//!
		//! Constructs the class manually by setting the owner pointer
		//! \param rowVectorAliasConstant Pointer to owner matrix
		void _constructRowVectorReadOperator(RowVectorAliasConstant * rowVectorAliasConstant)
		{
			_constructMatrixReadOperator((MatrixAliasConstant *)rowVectorAliasConstant);

			m_thisMatrix = rowVectorAliasConstant;
		}
};

//! \brief Base class for RowVectorWriteOperators.
//! \author Lee Netherton
//!
//! Most importantly provides m_thisMatrix with the right
//! kind of pointer.
//!
class RowVectorWriteOperator : public MatrixWriteOperator
{
	protected:

		//! Pointer to owner matrix
		RowVectorAlias * m_thisMatrix;

	public:
		//! \brief Default Constructor
		//!
		//! Creates an empty operator class which can then be more full constructed
		//! using _constructRowVectorWriteOperator()
		RowVectorWriteOperator() {}

		//! \brief Full Constructor
		//!
		//! Creates an operator class which takes and stores a pointer to an owner matrix
		//! \param rowVectorAlias Pointer to owner matrix
		RowVectorWriteOperator(RowVectorAlias * rowVectorAlias) :
			MatrixWriteOperator((MatrixAlias *)rowVectorAlias),
			m_thisMatrix(rowVectorAlias)
			{}

		//! \brief Manual Constructor
		//!
		//! Constructs the class manually by setting the owner pointer
		//! \param rowVectorAlias Pointer to owner matrix
		void _constructRowVectorWriteOperator(RowVectorAlias * rowVectorAlias)
		{
			_constructMatrixWriteOperator((MatrixAlias *)rowVectorAlias);

			m_thisMatrix = rowVectorAlias;
		}
};

//! \brief Base class for ColumnVectorReadOperators.
//! \author Lee Netherton
//!
//! Most importantly provides m_thisMatrix with the right
//! kind of pointer.
//!
class ColumnVectorReadOperator : public MatrixReadOperator
{
	protected:

		//! Pointer to owner matrix
		ColumnVectorAliasConstant * m_thisMatrix;

	public:
		//! \brief Default Constructor
		//!
		//! Creates an empty operator class which can then be more full constructed
		//! using _constructColumnVectorReadOperator()
		ColumnVectorReadOperator() {}

		//! \brief Full Constructor
		//!
		//! Creates an operator class which takes and stores a pointer to an owner matrix
		//! \param columnVectorAliasConstant Pointer to owner matrix
		ColumnVectorReadOperator(ColumnVectorAliasConstant * columnVectorAliasConstant) :
			MatrixReadOperator((MatrixAliasConstant *)columnVectorAliasConstant),
			m_thisMatrix(columnVectorAliasConstant)
			{}

		//! \brief Manual Constructor
		//!
		//! Constructs the class manually by setting the owner pointer
		//! \param columnVectorAliasConstant Pointer to owner matrix
		void _constructColumnVectorReadOperator(ColumnVectorAliasConstant * columnVectorAliasConstant)
		{
			_constructMatrixReadOperator((MatrixAliasConstant *)columnVectorAliasConstant);

			m_thisMatrix = columnVectorAliasConstant;
		}
};

//! \brief Base class for ColumnVectorWriteOperators.
//! \author Lee Netherton
//!
//! Most importantly provides m_thisMatrix with the right
//! kind of pointer.
//!
class ColumnVectorWriteOperator : public MatrixWriteOperator
{
	protected:

		//! Pointer to owner matrix
		ColumnVectorAlias * m_thisMatrix;

	public:
		//! \brief Default Constructor
		//!
		//! Creates an empty operator class which can then be more full constructed
		//! using _constructColumnVectorWriteOperator()
		ColumnVectorWriteOperator() {}

		//! \brief Full Constructor
		//!
		//! Creates an operator class which takes and stores a pointer to an owner matrix
		//! \param columnVectorAlias Pointer to owner matrix
		ColumnVectorWriteOperator(ColumnVectorAlias * columnVectorAlias) :
			MatrixWriteOperator((MatrixAlias *)columnVectorAlias),
			m_thisMatrix(columnVectorAlias)
			{}

		//! \brief Manual Constructor
		//!
		//! Constructs the class manually by setting the owner pointer
		//! \param columnVectorAlias Pointer to owner matrix
		void _constructColumnVectorWriteOperator(ColumnVectorAlias * columnVectorAlias)
		{
			_constructMatrixWriteOperator((MatrixAlias *)columnVectorAlias);

			m_thisMatrix = columnVectorAlias;
		}
};

//--------------------------------------------------------------
//				Matrix Read Operators
//--------------------------------------------------------------

//! \brief Read matrix element.
//! \author Lee Netherton
//!
class MRO_Element : public MatrixReadOperator
{
	public:
		//! \brief Read element given row, column position
		//! \param row Row position (zero-indexed)
		//! \param column Column position (zero-indexed)
		const double& operator()(const unsigned int row, const unsigned int column) const {return element(row,column);}

		//! \brief Read element given row-wise index position
		//! \param index Index of element (zero-indexed)
		const double& operator()(const unsigned int index) const {return element(index);}

};

//! \brief Multiply matrix.
//! \author Lee Netherton and Peter Mendham
//!
class MRO_Multiply : public MatrixReadOperator
{
	public:
		//! \brief Multiply matatix by a matrix
		//! \param operand Matrix to multiply by
		Matrix operator()(const MatrixAliasConstant& operand) const;

		//! \brief Multiply matrix by a scalar
		//! \param operand Scalar to multiply by
		Matrix operator()(const double& operand) const;

};

//! \brief Perform element by element multiplication.
//! \author Lee Netherton and Peter Mendham
//!
class MRO_ElementMultiply : public MatrixReadOperator
{
	public:
		//! \brief Multiply matatix by a matrix
		//! \param operand Matrix to multiply by
		Matrix operator()(const MatrixAliasConstant& operand) const;

};

//! \brief Add matrix.
//! \author Lee Netherton and Peter Mendham
//!
class MRO_Add : public MatrixReadOperator
{
	public:
		//! \brief Add matrix to another matrix
		//! \param operand Matrix to add to
		Matrix operator()(const MatrixAliasConstant& operand) const;

};

//! \brief Subtract matrix.
//! \author Lee Netherton and Peter Mendham
//!
class MRO_Subtract : public MatrixReadOperator
{
	public:
		//! \brief Subtract another matrix
		//! \param operand Matrix to subtract
		Matrix operator()(const MatrixAliasConstant& operand) const;

};

//! \brief Negative.
//! \author Lee Netherton and Peter Mendham
//!
class MRO_Negative : public MatrixReadOperator
{
	public:
		//! \brief Returns the negative of this matrix
		Matrix operator()() const;

};

//! \brief Divide matrix.
//! \author Lee Netherton and Peter Mendham
//!
class MRO_Divide : public MatrixReadOperator
{
	public:
		//! \brief Divide matrix by a scalar
		//! \param operand Scalar to divide by
		Matrix operator()(const double& operand) const;

};

//! \brief Print matrix to screen.
//! \author Lee Netherton and Peter Mendham
//!
class MRO_Print : public MatrixReadOperator
{
	public:
		//! \brief Prints the matrix to the screen
		void operator()() const;

};

//! \brief Print matrix to screen (MATLAB Friendly).
//! \author Lee Netherton
//!
class MRO_PrintMatlabFriendly : public MatrixReadOperator
{
	public:
		//! \brief Prints the matrix to the screen in a form that can be pasted into MATLAB
		void operator()() const;

};

//! \brief Get a SubMatrix.
//! \author Lee Netherton
//!
class MRO_SubMatrixAliasConstant : public MatrixReadOperator
{
	public:
		//! \brief Returns a SubMatrix of this matrix give row/column start/end positions.
		//! \param rowStart Starting row (zero-indexed)
		//! \param rowEnd Finishing row (inclusive, zero-indexed)
		//! \param columnStart Starting column (zero-indexed)
		//! \param columnEnd Finishing column (inclusive, zero-indexed)
		SubMatrixAliasConstant operator()(const unsigned int rowStart, const unsigned int rowEnd, const unsigned int columnStart, const unsigned int columnEnd) const;

};

//! \brief Comapre sizes.
//! \author Lee Netherton
//!
class MRO_SizeEqual : public MatrixReadOperator
{
	public:
		//! \brief Returns 1 if the sizes of the matrices are equal, 0 if not.
		//! \param operand Matrix with which to compare sizes
		int operator()(const MatrixAliasConstant& operand) const;
};

//! \brief Is this a square matrix?.
//! \author Lee Netherton
//!
class MRO_IsSquareMatrix : public MatrixReadOperator
{
	public:
		//! \brief Returns 1 if this matrix's rows = columns.
		int operator()() const;
};

//! \brief Is this a row vector?.
//! \author Lee Netherton
//!
class MRO_IsRowVector : public MatrixReadOperator
{
	public:
		//! \brief Returns 1 if this matrix's number of rows = 1.
		int operator()() const;
};

//! \brief Is this a column vector?.
//! \author Lee Netherton
//!
class MRO_IsColumnVector : public MatrixReadOperator
{
	public:
		//! \brief Returns 1 if this matrix's number of columns = 1.
		int operator()() const;
};


//! \brief Returns a transposed matrix.
//! \author Lee Netherton and Peter Mendham
//!
class MRO_Transpose : public MatrixReadOperator
{
	public:
		//! \brief Return the transpose of this matrix
		Matrix operator()() const;

};

//! \brief Returns an absolute matrix.
//! \author Lee Netherton and Peter Mendham
//!
class MRO_Absolute : public MatrixReadOperator
{
	public:
		//! \brief Return a matrix containing the absolute values of this matrix.
		Matrix operator()() const;

};

//! \brief Returns a column vector which is the sum of all the rows.
//! \author Lee Netherton and Peter Mendham
//!
class MRO_RowSum : public MatrixReadOperator
{
	public:
		//! \brief Adds rows to produce a column vector.
		ColumnVector operator()() const;

};

//! \brief Returns a row vector which is the sum of all the columns.
//! \author Lee Netherton and Peter Mendham
//!
class MRO_ColumnSum : public MatrixReadOperator
{
	public:
		//! \brief Adds columns to produce a row vector.
		RowVector operator()() const;

};

//! \brief Returns the largest element.
//! \author Lee Netherton and Peter Mendham
//!
class MRO_Maximum : public MatrixReadOperator
{
	public:
		//! \brief Returns maximum value in matrix.
		double operator()() const;

};

//! \brief Returns the smallest element.
//! \author Lee Netherton and Peter Mendham
//!
class MRO_Minimum : public MatrixReadOperator
{
	public:
		//! \brief Returns minumum value in matrix.
		double operator()() const;

};

//! \brief Returns the infinity norm of this matrix.
//! \author Lee Netherton and Peter Mendham
//!
class MRO_InfinityNorm : public MatrixReadOperator
{
	public:
		//! \brief Returns the infinity norm of this matrix
		double operator()() const;

};

//! \brief Returns the frobenius norm of this matrix.
//! \author Peter Mendham
//!
class MRO_FrobeniusNorm : public MatrixReadOperator
{
	public:
		//! \brief Returns the frobenius norm of this matrix
		double operator()() const;

};

//! \brief Returns a matrix with all the elements the square of this one's.
//! \author Lee Netherton and Peter Mendham
//!
class MRO_SquaredElements : public MatrixReadOperator
{
	public:
		//! \brief Returns a matrix with all the elements the square of this one's.
		Matrix operator()() const;

};


//--------------------------------------------------------------
//				Matrix Write Operators
//--------------------------------------------------------------

//! \brief Writable matrix element.
//! \author Lee Netherton
//!
class MWO_Element : public MatrixWriteOperator
{
	public:
		//! \brief Return writable element given row, column position
		//! \param row Row position (zero-indexed)
		//! \param column Column position (zero-indexed)
		double& operator()(const unsigned int row, const unsigned int column) const {return element(row,column);}

		//! \brief Return writable given row-wise index position
		//! \param index Index of element (zero-indexed)
		double& operator()(const unsigned int index) const {return element(index);}

};

//! \brief Copy elements (From matrix of same size).
//! \author Lee Netherton
//!
class MWO_EqualsElementCopy : public MatrixWriteOperator
{
	public:
		//! \brief Copy element-by-element from \c copy into this matrix.
		//!
		//! Matrices must be of same dimentions as there is no resize capabilities.
		//! \param copy Matrix to copy
		void operator()(const MatrixAliasConstant& copy) const;

};

//! \brief Copy memory directly (From matrix of same size).
//! \author Lee Netherton
//!
class MWO_EqualsMemCopy : public MatrixWriteOperator
{
	public:
		//! \brief Copy memory directly from \c copy into this matrix.
		//!
		//! Matrices must be of same dimentions as there is no resize capabilities.
		//! \param copy Matrix to copy
		void operator()(const MatrixAliasConstant& copy) const;

};

//! \brief Copy elements (Resize if necessesary).
//! \author Lee Netherton
//!
class MWO_EqualsElementCopyResize : public MatrixWriteOperator
{
	public:
		//! \brief Copy element-by-element from \c copy into this matrix.
		//!
		//! Matrix will be resized if there is a difference in dimentions.
		//! \param copy Matrix to copy
		void operator()(const MatrixAliasConstant& copy) const;

};

//! \brief Copy memory directly (Resize if necessesary).
//! \author Lee Netherton
//!
class MWO_EqualsMemCopyResize : public MatrixWriteOperator
{
	public:
		//! \brief Copy memory directly from \c copy into this matrix.
		//!
		//! Matrix will be resized if there is a difference in dimentions.
		//! \param copy Matrix to copy
		void operator()(const MatrixAliasConstant& copy) const;

};

//! \brief Reshape matrix (number of elements has to remain the same).
//! \author Lee Netherton
//!
class MWO_Reshape : public MatrixWriteOperator
{
	public:
		//! \brief Reshape matrix (number of elements has to remain the same)
		//! \param rows Desired number of rows
		//! \param columns Desired number of columns
		void operator()(const unsigned int rows, const unsigned int columns) const;

};

//! \brief Resize matrix (allocate new memory if number of elements changes).
//! \author Lee Netherton
//!
class MWO_Resize : public MatrixWriteOperator
{
	public:
		//! \brief Resize matrix (allocate new memory if number of elements changes)
		//! \param rows Desired number of rows
		//! \param columns Desired number of columns
		void operator()(const unsigned int rows, const unsigned int columns) const;

};

//! \brief Zero matrix.
//! \author Lee Netherton and Peter Mendham
//!
class MWO_Zero : public MatrixWriteOperator
{
	public:
		//! \brief Make all the elements in this matrix equal zero
		void operator()() const;

};

//! \brief Set all matrix values.
//! \author Lee Netherton
//!
class MWO_Set : public MatrixWriteOperator
{
	public:
		//! \brief Make all the elements in this matrix equal some value
		//! \param val Value to make all elements equal
		void operator()(const double val) const;

		//! \brief Make all the elements in this matrix equal unity
		void operator()() const;

};

//! \brief Normalise the matrix
//! \author Peter Mendham
//!
class MWO_Normalise : public MatrixWriteOperator
{
	public:
		//! \brief Scale all the elements in this matrix such that the
		//! Frobenius norm of the matrix is 1
		void operator()() const;
};

//! \brief Randomise matrix.
//! \author Lee Netherton
//!
class MWO_Randomise : public MatrixWriteOperator
{
	public:
		//! \brief Make all the elements in this matrix equal some random value
		//! \param val Max value
		void operator()(const double val) const;

		//! \brief Make all the elements in this matrix equal some random value (between 0 and 1)
		void operator()() const;

};

//! \brief Get a SubMatrix.
//! \author Lee Netherton
//!
class MWO_SubMatrixAlias : public MatrixWriteOperator
{
	public:
		//! \brief Returns a SubMatrix of this matrix give row/column start/end positions.
		//! \param rowStart Starting row (zero-indexed)
		//! \param rowEnd Finishing row (inclusive, zero-indexed)
		//! \param columnStart Starting column (zero-indexed)
		//! \param columnEnd Finishing column (inclusive, zero-indexed)
		SubMatrixAlias operator()(const unsigned int rowStart, const unsigned int rowEnd, const unsigned int columnStart, const unsigned int columnEnd) const;

};

//--------------------------------------------------------------
//				SquareMatrix Read Operators
//--------------------------------------------------------------

//! \brief Assess matrix compataibility (is matrix square?).
//! \author Lee Netherton
//!
/*class SqMRO_SizeCompatable : public SquareMatrixReadOperator
{
	public:

		int operator()(const MatrixAliasConstant& operand) const;
};*/

//! \brief Calculate determinant of matrix.
//! \author Lee Netherton and Peter Mendham
//!
class SqMRO_DeterminantBasic : public SquareMatrixReadOperator
{
	public:
		//! Calculates the determinant of this matrix. Uses basic method.
		double operator()() const;
};

//! \brief Calculate determinant of matrix.
//! \author Lee Netherton and Peter Mendham
//!
class SqMRO_DeterminantLUDecomp : public SquareMatrixReadOperator
{
	public:
		//! Calculates the determinant of this matrix. Uses LU decomposition method.
		double operator()() const;
};

//! \brief Calculate the cofactor of an element.
//! \author Lee Netherton and Peter Mendham
//!
class SqMRO_Cofactor : public SquareMatrixReadOperator
{
	public:
		//! \brief Calculates the cofactor for an element.
		//! \param row Row of element (zero-indexed)
		//! \param column Column of element (zero-indexed)
		double operator()(const unsigned int row, const unsigned int column) const;
};

//! \brief Matrix inverse.
//! \author Lee Netherton and Peter Mendham
//!
class SqMRO_InverseBasic : public SquareMatrixReadOperator
{
	public:
		//! Returns the inverse of this matrix. Uses basic method.
		SquareMatrix operator()() const;
};

//! \brief Matrix exponential.
//! \author Lee Netherton and Peter Mendham
//!
class SqMRO_Exponential : public SquareMatrixReadOperator
{
	public:
		//! Return the matrix exponential using irreducible Pade approximation.
		SquareMatrix operator()(double time) const;
};


//! \brief Matrix inverse.
//! \author Lee Netherton and Peter Mendham
//!
class SqMRO_InverseLUDecomp : public SquareMatrixReadOperator
{
	public:
		//! Returns the inverse of this matrix. Uses LU decomposition method.
		SquareMatrix operator()() const;
};

//! \brief Performs LU decomposition of this matrix.
//! \author Lee Netherton and Peter Mendham
//!
class SqMRO_LUDecomposition : public SquareMatrixReadOperator
{
	public:
		//! Returns the LU decomposition ofthis matrix.
		SquareMatrix operator()(RowVector &indx, double *d) const;
};

//! \brief Performs LU back substitution of matrix.
//! \author Lee Netherton and Peter Mendham
//!
class SqMRO_LUBackSubstitution : public SquareMatrixReadOperator
{
	public:
		//! Returns the LU back substitution of this matrix.
		SquareMatrix operator()(RowVector &indx, RowVector &b) const;
};


//--------------------------------------------------------------
//				SquareMatrix Write Operators
//--------------------------------------------------------------

//! \brief Copy elements (Resize if necessesary).
//! \author Lee Netherton
//!
class SqMWO_EqualsElementCopyResize : public SquareMatrixWriteOperator
{
	public:
		//! \brief Checks to see if copy is a square matrix, if so copies element in.
		//! \param copy Matrix to copy (must be square)
		void operator()(const MatrixAliasConstant& copy) const;
};

//! \brief Resize matrix
//! \author Lee Netherton
//!
class SqMWO_Resize : public SquareMatrixWriteOperator
{
	public:
		//! \brief Resizes matrix
		//! \param size New size of matrix
		void operator()(const unsigned int size) const;
};


//! \brief Makes this matrix the identity matrix.
//! \author Lee Netherton and Peter Mendham
//!
class SqMWO_Identity : public SquareMatrixWriteOperator
{
	public:
		//! \brief Make this matrix the identity matrix.
		void operator()() const;
};

//! \brief Makes this matrix a direction cosine matrix.
//! \author Lee Netherton and Peter Mendham
//!
class SqMWO_DirectionCosine : public SquareMatrixWriteOperator
{
	public:
		//! \brief Use Column vector of angles.
		void operator()(ColumnVectorAlias attitude);

		//! \brief Use direct angles.
		void operator()(double phi, double theta, double psi);
};



//--------------------------------------------------------------
//				RowVector Read Operators
//--------------------------------------------------------------

/*class RVRO_SizeCompatable : public RowVectorReadOperator
{
	public:

		int operator()(const MatrixAliasConstant& operand) const;
};*/

//! \brief Returns the cross product of the vector and its operand
//! \author Lee Netherton and Peter Mendham
//!
class RVRO_CrossProduct : public RowVectorReadOperator
{
	public:
		//! \brief Returns the cross product of the vector and its operand
		//! \param operand Operand to cross with.
		RowVector operator()(const RowVectorAliasConstant& operand) const;
};

//! \brief Returns the dot product of the vector and its operand
//! \author Lee Netherton and Peter Mendham
//!
class RVRO_DotProduct : public RowVectorReadOperator
{
	public:
		//! \brief Returns the dot product of the vector and its operand
		//! \param operand Operand to dot with.
		double operator()(const RowVectorAliasConstant& operand) const;
};

//! \brief Returns a normalised version of this vector
//! \author Peter Mendham
//!
class RVRO_Direction : public RowVectorReadOperator
{
	public:
		//! \brief Returns a normalised version of this vector
		RowVector operator()() const;
};


//! \brief Returns the size of this vector
//! \author Lee Netherton
//!
class RVRO_GetSize : public RowVectorReadOperator
{
	public:
		//! \brief Returns the size of this vector
		const unsigned int operator()() const {return getColumns();}
};

//--------------------------------------------------------------
//				RowVector Write Operators
//--------------------------------------------------------------

//! \brief Copy elements (Resize if necessesary).
//! \author Lee Netherton
//!
class RVWO_EqualsElementCopyResize : public RowVectorWriteOperator
{
	public:
		//! \brief Checks to see if copy is a row vector, if so copies element in.
		//! \param copy Matrix to copy (must be row vector)
		void operator()(const MatrixAliasConstant& copy) const;
};

//! \brief Resize vector
//! \author Lee Netherton
//!
class RVWO_Resize : public RowVectorWriteOperator
{
	public:
		//! \brief Resizes vector
		//! \param size New size of vector
		void operator()(const unsigned int size) const;
};

//--------------------------------------------------------------
//				ColumnVector Read Operators
//--------------------------------------------------------------

/*class CVRO_SizeCompatable : public ColumnVectorReadOperator
{
	public:

		int operator()(const MatrixAliasConstant& operand) const;
};*/

//! \brief Returns the cross product of the vector and its operand
//! \author Lee Netherton and Peter Mendham
//!
class CVRO_CrossProduct : public ColumnVectorReadOperator
{
	public:
		//! \brief Returns the cross product of the vector and its operand
		//! \param operand Operand to cross with.
		ColumnVector operator()(const ColumnVectorAliasConstant& operand) const;
};

//! \brief Returns the dot product of the vector and its operand
//! \author Lee Netherton and Peter Mendham
//!
class CVRO_DotProduct : public ColumnVectorReadOperator
{
	public:
		//! \brief Returns the dot product of the vector and its operand
		//! \param operand Operand to dot with.
		double operator()(const ColumnVectorAliasConstant& operand) const;
};

//! \brief Returns a normalised version of this vector
//! \author Peter Mendham
//!
class CVRO_Direction : public ColumnVectorReadOperator
{
	public:
		//! \brief Returns a normalised version of this vector
		ColumnVector operator()() const;
};

//! \brief Returns the size of this vector
//! \author Lee Netherton
//!
class CVRO_GetSize : public ColumnVectorReadOperator
{
	public:
		//! \brief Returns the size of this vector
		const unsigned int operator()() const {return getRows();}
};

//--------------------------------------------------------------
//				ColumnVector Write Operators
//--------------------------------------------------------------

//! \brief Copy elements (Resize if necessesary).
//! \author Lee Netherton
//!
class CVWO_EqualsElementCopyResize : public ColumnVectorWriteOperator
{
	public:
		//! \brief Checks to see if copy is a column vector, if so copies element in.
		//! \param copy Matrix to copy (must be column vector)
		void operator()(const MatrixAliasConstant& copy) const;
};

//! \brief Resize vector
//! \author Lee Netherton
//!
class CVWO_Resize : public ColumnVectorWriteOperator
{
	public:
		//! \brief Resizes vector
		//! \param size New size of vector
		void operator()(const unsigned int size) const;
};

#endif // __MATRIX_OPERATOR_H__
