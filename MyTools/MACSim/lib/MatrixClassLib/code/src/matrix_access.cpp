#include "../include/matrix_access.h"
#include "../include/matrix_container.h"
#include "../include/matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//-----------------------------------------
//
//          MatrixReadAccess
//
//-----------------------------------------

//-----------------------------------------
//          Element Functions
//-----------------------------------------

const double& MatrixReadAccess::readElement(const unsigned int row, const unsigned int column)
{
	if (row >= getRows() || column >= getColumns()) {
		error("MatrixAlias::element : Subscript out of range\n");
		return getDataPointer()[0];
	}

	return getDataPointer()[row*(getColumns()) + column];

}

const double& MatrixReadAccess::readElement(const unsigned int index)
{
	if (index >= (getRows()*getColumns())) {
		error("MatrixAlias::element : Subscript out of range\n");
		return getDataPointer()[0];
	}

	return getDataPointer()[index];

}

//-----------------------------------------
//          Get/Set Functions
//-----------------------------------------

const unsigned int MatrixReadAccess::getRows() const {return m_matrixAliasConstant->getRows();}
const unsigned int MatrixReadAccess::getColumns() const {return m_matrixAliasConstant->getColumns();}
const double * MatrixReadAccess::getDataPointer() {return m_matrixAliasConstant->m_matrixContainer->getDataPointer();}

void MatrixReadAccess::setDataPointer(const double * data) const {m_matrixAliasConstant->m_matrixContainer->setDataPointer(data);}

//-----------------------------------------
//          Error Functions
//-----------------------------------------

void MatrixReadAccess::error(const char* str) const {

	// Just a printf for now
	printf(str);
}

//-----------------------------------------
//
//          MatrixWriteAccess
//
//-----------------------------------------

//-----------------------------------------
//          Element Functions
//-----------------------------------------
double& MatrixWriteAccess::writeElement(const unsigned int row, const unsigned int column)
{
	if (row >= getRows() || column >= getColumns()) {
		error("MatrixAlias::element : Subscript out of range\n");
		return getDataPointer()[0];
	}

	return getDataPointer()[row*(getColumns()) + column];

}

double& MatrixWriteAccess::writeElement(const unsigned int index)
{
	if (index >= (getRows()*getColumns())) {
		error("MatrixAlias::element : Subscript out of range\n");
		return getDataPointer()[0];
	}

	return getDataPointer()[index];

}

//-----------------------------------------
//          Get/Set Functions
//-----------------------------------------

const unsigned int MatrixWriteAccess::getRows() const {return m_matrixAlias->getRows();}
const unsigned int MatrixWriteAccess::getColumns() const {return m_matrixAlias->getColumns();}
double * MatrixWriteAccess::getDataPointer() {return m_matrixAlias->m_matrixContainer->getDataPointer();}

void MatrixWriteAccess::setDataPointer(const double * data) const {m_matrixAlias->m_matrixContainer->setDataPointer(data);}
void MatrixWriteAccess::setRows(const unsigned int num) const {m_matrixAlias->m_matrixContainer->setRows(num);}
void MatrixWriteAccess::setColumns(const unsigned int num) const {m_matrixAlias->m_matrixContainer->setColumns(num);}


//-----------------------------------------
//          Error Functions
//-----------------------------------------

void MatrixWriteAccess::error(const char* str) const {

	// Just a printf for now
	printf(str);
}


//-----------------------------------------
//
//          SubMatrixReadAccess
//
//-----------------------------------------

//-----------------------------------------
//          Element Functions
//-----------------------------------------
const double& SubMatrixReadAccess::readElement(const unsigned int row, const unsigned int column)
{
	if (row >= getRows() || column >= getColumns()) {
		error("Matrix::element : Subscript out of range\n");
		return getDataPointer()[0];
	}

	return getDataPointer()[(row+getRowStart())*(getColumnsOrig()) + (column+getColumnStart())];

}

const double& SubMatrixReadAccess::readElement(const unsigned int index)
{
	if (index >= (getRows()*getColumns())) {
		error("Matrix::element : Subscript out of range\n");
		return getDataPointer()[0];
	}

	return readElement(index / getColumns(), index % getColumns());

}

//-----------------------------------------
//          Get/Set Functions
//-----------------------------------------

const unsigned int SubMatrixReadAccess::getRowsOrig() const {return m_subMatrixAliasConstant->m_subMatrixContainer->getRowsOrig();}
const unsigned int SubMatrixReadAccess::getColumnsOrig() const {return m_subMatrixAliasConstant->m_subMatrixContainer->getColumnsOrig();}
const unsigned int SubMatrixReadAccess::getRowStart() const {return m_subMatrixAliasConstant->m_subMatrixContainer->getRowStart();}
const unsigned int SubMatrixReadAccess::getRowEnd() const {return m_subMatrixAliasConstant->m_subMatrixContainer->getRowEnd();}
const unsigned int SubMatrixReadAccess::getColumnStart() const {return m_subMatrixAliasConstant->m_subMatrixContainer->getColumnStart();}
const unsigned int SubMatrixReadAccess::getColumnEnd() const {return m_subMatrixAliasConstant->m_subMatrixContainer->getColumnEnd();}



//-----------------------------------------
//
//          SubMatrixWriteAccess
//
//-----------------------------------------

//-----------------------------------------
//          Element Functions
//-----------------------------------------
double& SubMatrixWriteAccess::writeElement(const unsigned int row, const unsigned int column)
{
	if (row >= getRows() || column >= getColumns()) {
		error("Matrix::element : Subscript out of range\n");
		return getDataPointer()[0];
	}

	return getDataPointer()[(row+getRowStart())*(getColumnsOrig()) + (column+getColumnStart())];

}

double& SubMatrixWriteAccess::writeElement(const unsigned int index)
{
	if (index >= (getRows()*getColumns())) {
		error("Matrix::element : Subscript out of range\n");
		return getDataPointer()[0];
	}

	return writeElement(index / getColumns(), index % getColumns());

}
//-----------------------------------------
//          Get/Set Functions
//-----------------------------------------

const unsigned int SubMatrixWriteAccess::getRowsOrig() const {return m_subMatrixAlias->m_subMatrixContainer->getRowsOrig();}
const unsigned int SubMatrixWriteAccess::getColumnsOrig() const {return m_subMatrixAlias->m_subMatrixContainer->getColumnsOrig();}
const unsigned int SubMatrixWriteAccess::getRowStart() const {return m_subMatrixAlias->m_subMatrixContainer->getRowStart();}
const unsigned int SubMatrixWriteAccess::getRowEnd() const {return m_subMatrixAlias->m_subMatrixContainer->getRowEnd();}
const unsigned int SubMatrixWriteAccess::getColumnStart() const {return m_subMatrixAlias->m_subMatrixContainer->getColumnStart();}
const unsigned int SubMatrixWriteAccess::getColumnEnd() const {return m_subMatrixAlias->m_subMatrixContainer->getColumnEnd();}

