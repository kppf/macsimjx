#ifndef __MATRIX_CONTAINER_H__
#define __MATRIX_CONTAINER_H__

#include <iostream>

//! \brief Store for primative matrix information.
//! \author Lee Netherton
//!
//! The MatrixContainer class is used to store the matrix data. It holds
//! a pointer to the data array, and also the size of the matrix. Each
//! matrix will have a pointer to a matrix container within it.
//!
class MatrixContainer
{
	private:

		//! Number of rows
		unsigned int m_rows;

		//! Number of columns
		unsigned int m_columns;

		//! Pointer to data array
		double *m_data;

	public:

		//! \brief Sized constructor
		//!
		//! To create a MatrixContainer with appropriate values.
		//! \param data Pointer to data array. Assigned to \a m_data.
		//! \param rows Number of rows. Assigned to \a m_rows.
		//! \param columns Number of columns. Assigned to \a m_columns.
		MatrixContainer(const double * data, const unsigned int rows, const unsigned int columns) : m_data((double *)data), m_rows(rows), m_columns(columns)
		{
			#ifdef DEBUG_CONSTRUCTOR
				printf("Constructor: MatrixContainer(const double * data, const unsigned int rows, const unsigned int columns)\n");
			#endif
		}

		//! \brief Copy constructor
		//!
		//! To create a MatrixContainer from a copy of another
		//! \param copy Reference to container to copy
		MatrixContainer(const MatrixContainer& copy) : m_data(copy.getDataPointer()), m_rows(copy.getRows()), m_columns(copy.getColumns())
		{
			#ifdef DEBUG_CONSTRUCTOR
				printf("Constructor: MatrixContainer(const MatrixContainer& copy)\n");
			#endif
		}

		// --------- Get/Set functions --------------------

		//! \brief Returns the number of rows
		unsigned int getRows() const {return m_rows;}

		//! \brief Retuens the number of columns
		unsigned int getColumns() const {return m_columns;}

		//! \brief Returns the data pointer
		virtual double * getDataPointer() const {return m_data;}

		//! \brief Sets the number of rows
		void setRows(unsigned int num) {m_rows = num;}

		//! \brief Sets the number of columns
		void setColumns(unsigned int num) {m_columns = num;}

		//! \brief Sets the data pointer
		void setDataPointer(const double * ptr) {m_data = (double *)ptr;}
};

//! \brief Store for SubMatrix information.
//! \author Lee Netherton
//!
//! The SubMatrixContainer class is used to store the sub matrix data
//! as well as the usual matrix data. It holds
//! a pointer to the original matrix's container, and also the
//! start and end positions for the sub matrix with respect to
//! the original.
//!
class SubMatrixContainer : public MatrixContainer
{
	private:

		// --------- Sub matrix members ----------------

		//! Pointer to the original matrix's container
		const MatrixContainer * m_originalContainer;

		//! Start position for rows
		unsigned int m_rowStart;

		//! End position for rows
		unsigned int m_rowEnd;

		//! Start position for columns
		unsigned int m_columnStart;

		//! End position for columns
		unsigned int m_columnEnd;

	public:
		//! \brief Basic constructor
		//!
		//! To create a SubMatrixContainer from an original MatrixContainer
		//! and start and end values for the rows and columns.
		//! \param original Pointer to the original matrix's container
		//! \param rowStart The starting row for the submatrix
		//! \param rowEnd The finishing row for the submatrix
		//! \param columnStart The starting column for the submatrix
		//! \param columnEnd The finishing column for the submatrix
		SubMatrixContainer(const MatrixContainer * original, unsigned int rowStart, unsigned int rowEnd, unsigned int columnStart, unsigned int columnEnd) :
			MatrixContainer(original->getDataPointer(), (rowEnd-rowStart)+1, (columnEnd-columnStart)+1),
			m_rowStart(rowStart), m_rowEnd(rowEnd), m_columnStart(columnStart), m_columnEnd(columnEnd),
			m_originalContainer(original)
			{
				#ifdef DEBUG_CONSTRUCTOR
					printf("Constructor: SubMatrixContainer(MatrixContainer * original, int rowStart, int rowEnd, int columnStart, int columnEnd)\n");
				#endif
			}

		//! \brief Copy constructor
		//!
		//! To create a SubMatrixContainer from a copy of another
		//! \param copy Reference to SubMatrixContainer to copy
		SubMatrixContainer(const SubMatrixContainer& copy) :
			MatrixContainer(copy.m_originalContainer->getDataPointer(), copy.getRows(), copy.getColumns()),
			m_rowStart(copy.getRowStart()), m_rowEnd(copy.getRowEnd()), m_columnStart(copy.getColumnStart()), m_columnEnd(copy.getColumnEnd()),
			m_originalContainer(copy.m_originalContainer)
			{
				#ifdef DEBUG_CONSTRUCTOR
					printf("Constructor: SubMatrixContainer(SubMatrixContainer& copy)\n");
				#endif
			}


		// -------- SubMatrix functions ----------------------------

		//! Resurns a pointer to the original matrix's MatrixContainer
		const MatrixContainer * getOrigPointer() const {return m_originalContainer;}

		//! \brief Returns the number of rows in the original container
		unsigned int getRowsOrig() const {return m_originalContainer->getRows();}

		//! \brief Returns the number of rows in the original container
		unsigned int getColumnsOrig() const {return m_originalContainer->getColumns();}

		//! \brief Returns the row start position
		unsigned int getRowStart() const {return m_rowStart;}

		//! \brief Returns the row end position
		unsigned int getRowEnd() const {return m_rowEnd;}

		//! \brief Returns the column start position
		unsigned int getColumnStart() const {return m_columnStart;}

		//! \brief Returns the column end position
		unsigned int getColumnEnd() const {return m_columnEnd;}

		//! \brief Sets the row start position
		void setRowStart(const unsigned int num) {m_rowStart = num;}

		//! \brief Sets the row end position
		void setRowEnd(const unsigned int num) {m_rowEnd = num;}

		//! \brief Sets the column start position
		void setColumnStart(const unsigned int num) {m_columnStart = num;}

		//! \brief Sets the column end position
		void setColumnEnd(const unsigned int num) {m_columnEnd = num;}

};


#endif // __MATRIX_CONTAINER_H__