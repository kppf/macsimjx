#ifndef __MATRIX_ACCESS_H__
#define __MATRIX_ACCESS_H__

#include <iostream>

// Define Matrix classes for pointers
class MatrixAliasConstant;
class SubMatrixAliasConstant;
class MatrixAlias;
class SubMatrixAlias;

//! \brief Read access for matrix classes
//! \author Lee Netherton
//!
//! The MatrixReadAccess class provides basic read operatons for the MatrixOperator
//! classes, and the matrix class itself. Each matrix class will have a pointer
//! to a MatrixReadAccess, or one if its derivatives.
//!
class MatrixReadAccess
{
	protected:

		//! Pointer to owner matrix
		MatrixAliasConstant * m_matrixAliasConstant;

	public:

		//! \brief Constructor
		//!
		//! Sets pointer to owner matrix
		//! \param mAC Pointer to owner matrix
		MatrixReadAccess(MatrixAliasConstant * mAC) : m_matrixAliasConstant(mAC)
		{
			#ifdef DEBUG_CONSTRUCT
				printf("Constructor: MatrixReadAccess(MatrixAliasConstant * mAC)\n");
			#endif
		}

		//! Returns a read-only reference to the data member at specified position
		//! \param row Row position of desired element (zero indexed)
		//! \param column Column position of desired element (zero indexed)
		virtual const double& readElement(const unsigned int row, const unsigned int column);

		//! Returns a read-only reference to the data member at specified position
		//! \param index Row-wise position of element (zero-indexed)
		virtual const double& readElement(const unsigned int index);

		//! Returns the number of rows the matrix has
		const unsigned int getRows() const;

		//! Returns the number of columns the matrix has
		const unsigned int getColumns() const;

		//! Returns the a pointer to the matrix data array
		virtual const double * getDataPointer();

		//! \brief Sets the data pointer
		void setDataPointer(const double * data) const;

		//! For flagging errors - to be depreciated.
		void error(const char* str) const;
};


//! \brief Read access for sub-matrix classes
//! \author Lee Netherton
//!
//! The SubMatrixReadAccess class provides basic read operatons for the MatrixOperator
//! classes, and the sub matrix class itself. Each sub matrix class will have a pointer
//! to a SubMatrixReadAccess.
//!
class SubMatrixReadAccess : public MatrixReadAccess
{
	private:

		//! Pointer to owner sub matrix
		SubMatrixAliasConstant * m_subMatrixAliasConstant;

	public:

		//! \brief Constructor
		//!
		//! Sets pointer to owner matrix and constructs base class.
		//! \param sMAC Pointer to owner matrix
		SubMatrixReadAccess(SubMatrixAliasConstant * sMAC) :
			MatrixReadAccess((MatrixAliasConstant *)sMAC),
			m_subMatrixAliasConstant(sMAC)
			{
				#ifdef DEBUG_CONSTRUCT
					printf("Constructor: SubMatrixReadAccess(SubMatrixAliasConstant * sMAC)\n");
				#endif
			}

		//! Returns a read-only reference to the data member at specified position
		//! \param row Row position of desired element (zero indexed)
		//! \param column Column position of desired element (zero indexed)
		virtual const double& readElement(const unsigned int row, const unsigned int column);

		//! Returns a read-only reference to the data member at specified position
		//! \param index Row-wise position of element (zero-indexed)
		virtual const double& readElement(const unsigned int index);

		//! \brief Returns the number of rows in the original matrix
		const unsigned int getRowsOrig() const;

		//! \brief Returns the number of columns in the original matrix
		const unsigned int getColumnsOrig() const;

		//! \brief Returns the row start position
		const unsigned int getRowStart() const;

		//! \brief Returns the row end position
		const unsigned int getRowEnd() const;

		//! \brief Returns the column start position
		const unsigned int getColumnStart() const;

		//! \brief Returns the column end position
		const unsigned int getColumnEnd() const;

};


//! \brief Write access for matrix classes
//! \author Lee Netherton
//!
//! The MatrixWriteAccess class provides basic write operatons for the MatrixWriteOperator
//! classes, and the matrix class itself. Each writable matrix class will have a pointer
//! to a MatrixWriteAccess, or one if its derivatives.
//!
class MatrixWriteAccess
{
	protected:

		//! Pointer to owner matrix
		MatrixAlias * m_matrixAlias;

	public:

		//! \brief Constructor
		//!
		//! Sets pointer to owner matrix
		//! \param mA Pointer to owner matrix
		MatrixWriteAccess(MatrixAlias * mA) : m_matrixAlias(mA)
		{
			#ifdef DEBUG_CONSTRUCT
				printf("Constructor: MatrixWriteAccess(MatrixAlias * mA)\n");
			#endif
		}

		//! Returns a writable reference to the data member at specified position
		//! \param row Row position of desired element (zero indexed)
		//! \param column Column position of desired element (zero indexed)
		virtual double& writeElement(const unsigned int row, const unsigned int column);

		//! Returns a writable reference to the data member at specified position
		//! \param index Row-wise position of element (zero-indexed)
		virtual double& writeElement(const unsigned int index);

		//! Returns the number of rows the matrix has
		const unsigned int getRows() const;

		//! Returns the number of columns the matrix has
		const unsigned int getColumns() const;

		//! Returns the a pointer to the matrix data array
		virtual double * getDataPointer();

		//! \brief Sets the data pointer
		void setDataPointer(const double * data) const;

		//! \brief Sets the number of rows
		void setRows(const unsigned int num) const;

		//! \brief Sets the number of columns
		void setColumns(const unsigned int num) const;

		//! For flagging errors - to be depreciated.
		void error(const char* str) const;

};

//! \brief Write access for sub-matrix classes
//! \author Lee Netherton
//!
//! The SubMatrixWriteAccess class provides basic write operatons for the MatrixOperator
//! classes, and the sub matrix class itself. Each writable sub matrix class will have a pointer
//! to a SubMatrixWriteAccess.
//!
class SubMatrixWriteAccess : public MatrixWriteAccess
{
	private:

		//! Pointer to owner matrix
		SubMatrixAlias * m_subMatrixAlias;

	public:

		//! \brief Constructor
		//!
		//! Sets pointer to owner matrix
		//! \param sMA Pointer to owner matrix
		SubMatrixWriteAccess(SubMatrixAlias * sMA) :
			MatrixWriteAccess((MatrixAlias *)sMA),
			m_subMatrixAlias(sMA)
			{
				#ifdef DEBUG_CONSTRUCT
					printf("Constructor: SubMatrixWriteAccess(SubMatrixAlias * sMA)\n");
				#endif
			}

		//! Returns a writable reference to the data member at specified position
		//! \param row Row position of desired element (zero indexed)
		//! \param column Column position of desired element (zero indexed)
		virtual double& writeElement(const unsigned int row, const unsigned int column);

		//! Returns a writable reference to the data member at specified position
		//! \param index Row-wise position of element (zero-indexed)
		virtual double& writeElement(const unsigned int index);

		//! \brief Returns the number of rows in the original matrix
		const unsigned int getRowsOrig() const;

		//! \brief Returns the number of columns in the original matrix
		const unsigned int getColumnsOrig() const;

		//! \brief Returns the row start position
		const unsigned int getRowStart() const;

		//! \brief Returns the row end position
		const unsigned int getRowEnd() const;

		//! \brief Returns the column start position
		const unsigned int getColumnStart() const;

		//! \brief Returns the column end position
		const unsigned int getColumnEnd() const;

};

#endif // __MATRIX_ACCESS_H__