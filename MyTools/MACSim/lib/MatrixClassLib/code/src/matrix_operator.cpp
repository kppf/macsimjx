#include "../include/matrix_operator.h"
#include "../include/matrix.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


//--------------------------------------------------------------
//				Base Class Read Operator
//--------------------------------------------------------------


const unsigned int MatrixReadOperator::getRows() const {return m_thisMatrix->getRows();}
const unsigned int MatrixReadOperator::getColumns() const {return m_thisMatrix->getColumns();}
const double * MatrixReadOperator::getDataPointer() const {return m_thisMatrix->m_matrixReadAccess->getDataPointer();}
const double& MatrixReadOperator::element(const unsigned int row, const unsigned int column) const {return m_thisMatrix->m_matrixReadAccess->readElement(row, column);}
const double& MatrixReadOperator::element(const unsigned int index) const {return m_thisMatrix->m_matrixReadAccess->readElement(index);}
void MatrixReadOperator::error(const char* str) const {m_thisMatrix->m_matrixReadAccess->error(str);}


//--------------------------------------------------------------
//				Base Class Write Operator
//--------------------------------------------------------------

const unsigned int MatrixWriteOperator::getRows() const {return m_thisMatrix->getRows();}
const unsigned int MatrixWriteOperator::getColumns() const {return m_thisMatrix->getColumns();}
double * MatrixWriteOperator::getDataPointer() const {return m_thisMatrix->m_matrixWriteAccess->getDataPointer();}
void MatrixWriteOperator::setDataPointer(double * data) const {m_thisMatrix->m_matrixWriteAccess->setDataPointer(data);}
void MatrixWriteOperator::setRows(const unsigned int num) const {m_thisMatrix->m_matrixWriteAccess->setRows(num);}
void MatrixWriteOperator::setColumns(const unsigned int num) const {m_thisMatrix->m_matrixWriteAccess->setColumns(num);}
double& MatrixWriteOperator::element(const unsigned int row, const unsigned int column) const {return m_thisMatrix->m_matrixWriteAccess->writeElement(row, column);}
double& MatrixWriteOperator::element(const unsigned int index) const {return m_thisMatrix->m_matrixWriteAccess->writeElement(index);}
void MatrixWriteOperator::error(const char* str) const {m_thisMatrix->m_matrixWriteAccess->error(str);}



//--------------------------------------------------------------
//				Matrix Read Operators
//--------------------------------------------------------------

Matrix MRO_Multiply::operator()(const MatrixAliasConstant& operand) const
{
	Matrix result(getRows(), operand.getColumns());
	double thisElement;
	unsigned int i, j, k;


	if (operand.getRows() != getColumns()) {
		error("MatrixAlias::operator* : Dimensions are not consistent\n");
		return result; // Return empty matrix
	}

	for (i = 0; i < getRows(); i++) {

		for (j = 0; j < operand.getColumns(); j++) {

			thisElement = 0;

			for (k = 0; k < getColumns(); k++) {
				thisElement += element(i, k) * operand.element(k, j);
			}

			result.element(i, j) = thisElement;
		}
	}

	return result;
}

Matrix MRO_ElementMultiply::operator()(const MatrixAliasConstant& operand) const
{
	Matrix result(getRows(), getColumns());
	unsigned int i, j;

	if (operand.getRows() != getRows() || operand.getColumns() != getColumns()) {
		error("MatrixAlias::elementMultiply : Dimensions are not consistent\n");
		return result; // Return empty matrix
	}

	for (i = 0; i < getRows(); i++) {
		for (j = 0; j < getColumns(); j++) {
			result.element(i, j) = operand.element(i,j) * element(i, j);
		}
	}

	return result;
}


Matrix MRO_Multiply::operator()(const double& operand) const
{
	Matrix result(getRows(), getColumns());
	unsigned int i, j;

	for (i = 0; i < getRows(); i++) {
		for (j = 0; j < getColumns(); j++) {
			result.element(i, j) = element(i, j) * operand;
		}
	}

	return result;
}

Matrix MRO_Divide::operator()(const double& operand) const
{
	Matrix result(getRows(), getColumns());
	unsigned int i, j;

	for (i = 0; i < getRows(); i++) {
		for (j = 0; j < getColumns(); j++) {
			result.element(i, j) = element(i, j) / operand;
		}
	}

	return result;
}

Matrix MRO_Add::operator()(const MatrixAliasConstant& operand) const
{
	Matrix result(getRows(), getColumns());
	unsigned int i;

	if (operand.getRows() != getRows() || operand.getColumns() != getColumns()) {
		error("MRO_Add : Dimensions are not consistent\n");
		return result; // Return empty matrix
	}

	for (i = 0; i < getRows()*getColumns(); i++) {
		result.element(i) = element(i) + operand.element(i);
	}

	return result;
}

Matrix MRO_Subtract::operator()(const MatrixAliasConstant& operand) const
{
	Matrix result(getRows(), getColumns());
	unsigned int i;

	if (operand.getRows() != getRows() || operand.getColumns() != getColumns()) {
		error("MRO_Subtract : Dimensions are not consistent\n");
		return result; // Return empty matrix
	}

	for (i = 0; i < getRows()*getColumns(); i++) {
		result.element(i) = element(i) - operand.element(i);
	}

	return result;
}

Matrix MRO_Negative::operator()() const
{
	Matrix result(getRows(), getColumns());

	unsigned int i, j;

	for (i = 0; i < getRows(); i++) {

		for (j = 0; j < getColumns(); j++) {

			result.element(i, j) = -1 * element(i, j);
		}
	}

	return result;
}

void MRO_Print::operator()() const
{

	unsigned int i, j;

	for (i = 0; i < getRows(); i++) {
		printf("[");
		for (j = 0; j < (getColumns()-1); j++) {
			printf("%.2lf  ", element(i, j));
		}
		printf("%.2lf", element(i, getColumns()-1));
		printf("]\n");
	}
	printf("\n");
}

void MRO_PrintMatlabFriendly::operator()() const
{

	unsigned int i, j;
	printf("[\n");
	for (i = 0; i < getRows(); i++) {
		for (j = 0; j < (getColumns()-1); j++) {
			printf("%.2lf  ", element(i, j));
		}
		printf("%.2lf;", element(i, getColumns()-1));
		printf("\n");
	}
	printf("]\n");
}

SubMatrixAliasConstant MRO_SubMatrixAliasConstant::operator()(const unsigned int rowStart, const unsigned int rowEnd, const unsigned int columnStart, const unsigned int columnEnd) const
{
	SubMatrixAliasConstant subMatrixAliasConstant(m_thisMatrix, rowStart, rowEnd, columnStart, columnEnd);

	return subMatrixAliasConstant;
}

int MRO_SizeEqual::operator()(const MatrixAliasConstant& operand) const
{
	if(operand.getRows() == getRows() && operand.getColumns() == getColumns())
		return 1; // Size is equal

	return 0; // Size is NOT equal
}

int MRO_IsSquareMatrix::operator()() const
{
	if(getRows() == getColumns())
		return 1; // Matrix is square

	return 0; //  Matrix is NOT square
}

int MRO_IsRowVector::operator()() const
{
	if(getRows() == 1)
		return 1; // Matrix is row vector

	return 0; //  Matrix is NOT row vector
}

int MRO_IsColumnVector::operator()() const
{
	if(getColumns() == 1)
		return 1; // Matrix is column vector

	return 0; //  Matrix is NOT column vector
}



//----------------------------------------------------------------------------
// Return a matrix which is the transpose of this one
//----------------------------------------------------------------------------

Matrix MRO_Transpose::operator()() const {

	Matrix newMatrix(getColumns(), getRows());
	unsigned int i, j;

	for (i = 0; i < getRows(); i++) {
		for (j = 0; j < getColumns(); j++) {
			newMatrix.element(j, i) = element(i, j);
		}
	}

	return newMatrix;
}

//----------------------------------------------------------------------------
// Return a matrix containing the absolute elements of this matrix
//----------------------------------------------------------------------------

Matrix MRO_Absolute::operator()() const {

	Matrix newMatrix(getColumns(), getRows());
	unsigned int i, j;

	for (i = 0; i < getRows(); i++) {
		for (j = 0; j < getColumns(); j++) {
			newMatrix.element(i, j) = fabs(element(i, j));
		}
	}

	return newMatrix;
}

//----------------------------------------------------------------------------
// Return a column vector containing the sums of each of the rows
//----------------------------------------------------------------------------

ColumnVector MRO_RowSum::operator()() const {

	ColumnVector newVector(getRows());
	unsigned int i, j;

	for (i = 0; i < getRows(); i++) {
		newVector.element(i) = 0;
		for (j = 0; j < getColumns(); j++) {
			newVector.element(i) += element(i, j);
		}
	}

	return newVector;
}

//----------------------------------------------------------------------------
// Return a row vector containing the sums of each of the columns
//----------------------------------------------------------------------------

RowVector MRO_ColumnSum::operator()() const {

	RowVector newVector(getColumns());
	unsigned int i, j;

	for (j = 0; j < getColumns(); j++) {
		newVector.element(j) = 0;
		for (i = 0; i < getRows(); i++) {
			newVector.element(j) += element(i, j);
		}
	}

	return newVector;
}

//----------------------------------------------------------------------------
// Return the maximum value in this matrix
//----------------------------------------------------------------------------

double MRO_Maximum::operator()() const {

	unsigned int i, j;
	double maxVal;

	maxVal = element(0);

	for (i = 0; i < getRows(); i++) {
		for (j = 0; j < getColumns(); j++) {
			maxVal = (element(i, j) > maxVal) ? element(i, j) : maxVal;
		}
	}

	return maxVal;
}

//----------------------------------------------------------------------------
// Return the minimum value in this matrix
//----------------------------------------------------------------------------

double MRO_Minimum::operator()() const {

	unsigned int i, j;
	double minVal;

	minVal = element(0);

	for (i = 0; i < getRows(); i++) {
		for (j = 0; j < getColumns(); j++) {
			minVal = (element(i, j) < minVal) ? element(i, j) : minVal;
		}
	}

	return minVal;
}

//----------------------------------------------------------------------------
// Return the infinity norm of this matrix
//----------------------------------------------------------------------------

double MRO_InfinityNorm::operator()() const {

	ColumnVector newVector(getRows());
	unsigned int i, j;

	for (i = 0; i < getRows(); i++) {
		newVector.element(i) = 0;
		for (j = 0; j < getColumns(); j++) {
			newVector.element(i) += fabs(element(i, j));
		}
	}

	return newVector.maximum();
}

//----------------------------------------------------------------------------
// Return the frobenius norm of this matrix
//----------------------------------------------------------------------------

double MRO_FrobeniusNorm::operator()() const {

	unsigned int i;
	double normSquared = 0;

	for (i = 0; i < (getRows() * getColumns()); i++) {
		normSquared += element(i) * element(i);
	}

	return sqrt(normSquared);
}


//----------------------------------------------------------------------------
// Square the elements of this matrix
//----------------------------------------------------------------------------

Matrix MRO_SquaredElements::operator()() const {

	Matrix newMatrix(m_thisMatrix);
	unsigned int i, j;

	for (i = 0; i < getRows(); i++) {
		for (j = 0; j < getColumns(); j++) {
			newMatrix.element(i, j) *= element(i, j);
		}
	}

	return newMatrix;
}




//--------------------------------------------------------------
//				Matrix Write Operators
//--------------------------------------------------------------


void MWO_EqualsElementCopy::operator()(const MatrixAliasConstant& copy) const
{
		unsigned int i, j;

		//printf("MWO_EqualsElementCopy called\n");

		if(m_thisMatrix->sizeEqual(copy) == 0)
		{
			error("MWO_EqualsElementCopy : Dimensions are not consistent\n");
			return;
		}

		/*if(copy.getRows() != getRows() || copy.getColumns() != getColumns()) {
			error("MWO_EqualsElementCopy : Dimensions are not consistent\n");
			return;
		}*/

		for (i = 0; i < getRows(); i++) {
			for (j = 0; j < getColumns(); j++) {

				element(i, j) = copy.element(i, j);
			}
		}
}

void MWO_EqualsElementCopyResize::operator()(const MatrixAliasConstant& copy) const
{
		unsigned int i, j;

		//printf("MWO_EqualsElementCopyResize called\n");

		//printf("copy.getRows():%d\ngetRows():%d\ncopy.getColumns():%d\ncopy.getColumns():%d\n",copy.getRows(),getRows(),copy.getColumns(),copy.getColumns());

		if(copy.getRows() != getRows() || copy.getColumns() != getColumns()) {
			// Resize!!

			// Change values
			setRows(copy.getRows());
			setColumns(copy.getColumns());

			// Delete old memory
			delete[] getDataPointer();

			// Allocate new memory
			setDataPointer(new double[getRows()*getColumns()]);
		}


		for (i = 0; i < getRows(); i++) {
			for (j = 0; j < getColumns(); j++) {
				element(i, j) = copy.element(i, j);
			}
		}

}

void MWO_EqualsMemCopy::operator()(const MatrixAliasConstant& copy) const
{
		if(copy.getRows() != getRows() || copy.getColumns() != getColumns()) {
			error("MWO_EqualsMemCopy : Dimensions are not consistent\n");
			return;
		}

		// Perform a direct memory copy
		memcpy(getDataPointer(), copy.getDataPointer(), sizeof(double)*getRows()*getColumns());

}

void MWO_EqualsMemCopyResize::operator()(const MatrixAliasConstant& copy) const
{
		if(copy.getRows() != getRows() || copy.getColumns() != getColumns()) {
			// Resize!!

			// Change values
			setRows(copy.getRows());
			setColumns(copy.getColumns());

			// Delete old memory
			delete[] getDataPointer();

			// Allocate new memory
			setDataPointer(new double[getRows()*getColumns()]);
		}

		// Perform a direct memory copy
		memcpy(getDataPointer(), copy.getDataPointer(), sizeof(double)*getRows()*getColumns());

}

void MWO_Reshape::operator()(const unsigned int rows, const unsigned int columns) const
{
	if((rows * columns) != (getRows() * getColumns())) {
		error("MWO_Reshape : Dimensions are not consistent\n");
		return;
	}

	// Change values
	setRows(rows);
	setColumns(columns);
}

void MWO_Resize::operator()(const unsigned int rows, const unsigned int columns) const
{
	// Change values
	setRows(rows);
	setColumns(columns);

	// Delete old memory
	delete[] getDataPointer();

	// Allocate new memory
	setDataPointer(new double[rows*columns]);
}

void MWO_Zero::operator()() const
{
	unsigned int i;

	for (i = 0; i < getRows()*getColumns(); i++) {
		element(i) = 0;
	}
}

void MWO_Set::operator()(const double val) const
{
	unsigned int i;

	for (i = 0; i < getRows()*getColumns(); i++) {
		element(i) = val;
	}
}

void MWO_Set::operator()() const
{
	unsigned int i;

	for (i = 0; i < getRows()*getColumns(); i++) {
		element(i) = 1;
	}
}

void MWO_Normalise::operator()() const
{
	unsigned int i;
	double norm = m_thisMatrix->frobeniusNorm();

	for (i = 0; i < getRows()*getColumns(); i++) {
		element(i) = element(i) / norm;
	}
}


double _rand()
{
	int big_num=100000;

	return (double)random(big_num) / (double)big_num;
}

void MWO_Randomise::operator()(const double val) const
{
	unsigned int i;

	for (i = 0; i < getRows()*getColumns(); i++) {
		element(i) = _rand()*val;
	}
}

void MWO_Randomise::operator()() const
{
	unsigned int i;

	for (i = 0; i < getRows()*getColumns(); i++) {
		element(i) = _rand();
	}
}

SubMatrixAlias MWO_SubMatrixAlias::operator()(const unsigned int rowStart, const unsigned int rowEnd, const unsigned int columnStart, const unsigned int columnEnd) const
{
	SubMatrixAlias subMatrixAlias(m_thisMatrix, rowStart, rowEnd, columnStart, columnEnd);

	return subMatrixAlias;
}


//--------------------------------------------------------------
//				SquareMatrix Read Operators
//--------------------------------------------------------------

//----------------------------------------------------------------------------
// Size Compatable
//----------------------------------------------------------------------------

/*int SqMRO_SizeCompatable::operator()(const MatrixAliasConstant& operand) const
{
	if(operand.getColumns() == operand.getRows())
		return 1;  // Operand is a square matrix

	return 0;  // Operand is NOT a square matrix
}*/

//----------------------------------------------------------------------------
// Determinant
//----------------------------------------------------------------------------

double SqMRO_DeterminantBasic::operator()() const {

	unsigned int i;
	double det;

	if (getRows() == 1) {

		det = element(0);

	} else if (getRows() == 2) {

		det = element(0,0)*element(1,1) - element(0,1)*element(1,0);

	} else {

		det = 0;

		for (i = 0; i < getColumns(); i++) {
			det	+= element(i) * m_thisMatrix->cofactor(0, i);
		}
	}

	return det;
}


//----------------------------------------------------------------------------
// Determinant
//----------------------------------------------------------------------------

double SqMRO_DeterminantLUDecomp::operator()() const {

	double det;

	if (getRows() == 1) {

		det = element(0);

	} else if (getRows() == 2) {

		det = element(0,0)*element(1,1) - element(0,1)*element(1,0);

	} else {

		SquareMatrix temp(*m_thisMatrix);
		RowVector indices(getRows());
		unsigned int j;

		temp.luDecomposition(indices, &det);
		for (j = 0; j < getRows(); j++) {
			det *= temp(j, j);
		}
	}

	return det;
}

//----------------------------------------------------------------------------
// Cofactor
//----------------------------------------------------------------------------

double SqMRO_Cofactor::operator()(const unsigned int row, const unsigned int column) const {

	SquareMatrix newSquareMatrix(getRows() - 1);
	double sign;

	if (row >= getRows() || column >= getColumns()) {
		error("SquareMatrixAlias::cofactor : Subscript out of range\n");
		return 0;
	}

	sign = (row + column) % 2 ? -1 : 1;

	// Top left quadrant
	if (row > 0 && column > 0) {
		newSquareMatrix.subMatrix(0, row-1, 0, column-1) = m_thisMatrix->subMatrix(0, row-1, 0, column-1);
	}
	// Top right quadrant
	if (row > 0 && column < (getColumns() - 1)) {
		newSquareMatrix.subMatrix(0, row-1, column, getColumns()-2) = m_thisMatrix->subMatrix(0, row-1, column+1, getColumns()-1);
	}
	// Bottom left quadrant
	if (row < (getRows() - 1) && column > 0) {
		newSquareMatrix.subMatrix(row, getRows()-2, 0, column-1) = m_thisMatrix->subMatrix(row+1, getRows()-1, 0, column-1);
	}
	// Bottom right quadrant
	if (row < (getRows() - 1) && column < (getColumns() - 1)) {
		newSquareMatrix.subMatrix(row, getRows()-2, column, getColumns()-2) = m_thisMatrix->subMatrix(row+1, getRows()-1, column+1, getColumns()-1);
	}

	return sign * newSquareMatrix.determinant();
}

//----------------------------------------------------------------------------
// Inverse
//----------------------------------------------------------------------------

SquareMatrix SqMRO_InverseBasic::operator()() const {

	SquareMatrix inv(getRows());
	unsigned int i, j;
	double det;

	det = m_thisMatrix->determinant();

	if (det == 0) {
		error("SquareMatrixAlias::inverse : MatrixAlias is rank defficient\n");
		return inv; // return blank matrix
	}

	for (i = 0; i < getRows(); i++) {
		for(j = 0; j < getColumns(); j++) {
			inv.element(j, i) = m_thisMatrix->cofactor(i, j) / det;
		}
	}

	return inv;
}

//----------------------------------------------------------------------------
// Inverse
//----------------------------------------------------------------------------

SquareMatrix SqMRO_InverseLUDecomp::operator()() const {

	SquareMatrix inv(*m_thisMatrix);
	RowVector indices(getRows()), column(getRows());
	unsigned int i, j;
	double sign;

	inv.luDecomposition(indices, &sign);

	for (j = 0; j < getColumns(); j++) {
		column.zero();
		column(j) = 1;
		inv.luBackSubstitution(indices, column);
		for (i = 0; i < getRows(); i++) {
			inv(i,j) = column(i);
		}
	}

	return inv;
}

//----------------------------------------------------------------------------
// Return the matrix exponential using irreducible Pade approximation
//----------------------------------------------------------------------------

SquareMatrix SqMRO_Exponential::operator()(double time) const {

	SquareMatrix localCopy(getRows()), squaredCopy(getRows());
	SquareMatrix I(getRows()), Q(getRows()), P(getRows()), result(getRows());
	unsigned int nCoefs = 6;
	RowVector padeCoef(nCoefs + 1);
	unsigned int i, odd;
	double k, scaleFactor;

	// Multiply intime factor
	//localCopy = (*this) * time;
	localCopy.multiply(time);

	// Setup Pade coefficients
	padeCoef.element(0) = 1;
	for (i = 1; i <= nCoefs; i++) {
		k = i;
		padeCoef.element(i) = padeCoef.element(i-1) * ((nCoefs+1-k)/(k*(2*nCoefs+1-k)));
	}

	// Scale the matrix if necessary
	scaleFactor = m_thisMatrix->infinityNorm();
	if (scaleFactor > 0.5) {

		scaleFactor = log(scaleFactor)/log((double)2);
		scaleFactor = (scaleFactor > 0) ? floor(scaleFactor) : ceil(scaleFactor);
		scaleFactor += 2;
		scaleFactor = (scaleFactor > 0) ? scaleFactor : 0;

		localCopy = pow((double)2,-scaleFactor) * localCopy;
	}

	// Horner evaluation of the irreducible fraction
	I.identity();
	squaredCopy = localCopy * localCopy;
	Q = padeCoef.element(nCoefs) * I;
	P = padeCoef.element(nCoefs-1) * I;
	odd = 1;

	for (i = (nCoefs - 1); i > 0; i--) {

		if (odd == 1) {
			Q = Q*squaredCopy + padeCoef.element(i-1)*I;
		} else {
			P = P*squaredCopy + padeCoef.element(i-1)*I;
		}

		odd = 1 - odd;
	}

	if (odd == 1) {
		Q = Q*localCopy;
		Q = Q - P;
		result = -1*(I + 2 * (Q.inverse() * P));
	} else {
		P = P*localCopy;
		Q = Q - P;
		result = I + 2 * (Q.inverse() * P);
	}

	// Squaring
	for (i = 0; i < (unsigned int)scaleFactor; i++) {

		result = result * result;
	}

	return result;
}


//----------------------------------------------------------------------------
// LU decomposition
//----------------------------------------------------------------------------

SquareMatrix SqMRO_LUDecomposition::operator()(RowVector &indx, double *d) const {

	SquareMatrix a(*m_thisMatrix);
	int n, i, imax, j, k;
	double big, dum, sum, temp;
	RowVector vv(a.getRows());

	n = a.getRows();

	// No row interchanges yet
	*d = 1.0;

	// Loop over rows to get implicit scaling information
	for (i = 0; i < n; i++) {
		big = 0.0;
		for (j = 0; j < n; j++) {
			temp = fabs(a.element(i,j));
			if (temp > big) {
				big = temp;
			}
		}
		if (big == 0.0) {
			error("SquareMatrixAlias::luDecomp : MatrixAlias is rank defficient\n\n");
			return a;
		}
		vv(i) = 1 / big;
	}

	// Loop over columns (Crout's method)
	for (j = 0; j < n; j++) {
		for (i = 0; i < j; i++) {
			sum = a.element(i,j);
			for (k = 0; k < i; k++) {
				sum -= a.element(i,k) * a.element(k,j);
			}
			a.element(i,j) = sum;
		}
		big = 0;
		for (i = j; i < n; i++) {
			sum = a.element(i,j);
			for (k = 0; k < j; k++) {
				sum -= a.element(i,k) * a.element(k,j);
			}
			a.element(i,j) = sum;

			dum = vv(i) * fabs(sum);
			if (dum >= big) {
				big = dum;
				imax = i;
			}
		}
		if (j != imax) {
			for (k = 0; k < n; k++) {
				dum = a.element(imax,k);
				a.element(imax,k) = a.element(j,k);
				a.element(j,k) = dum;
			}
			*d = -(*d);
			vv(imax) = vv(j);
		}
		indx.element(j) = imax;
		// Singularity may arise as aresult of rounding errors
		// Substitute in small values for zeros
		if (a.element(j,j) == 0) {
			error("SquareMatrixAlias::luDecomp : MatrixAlias is rank defficient\n\n");
			a.element(j,j) = 1e-100;
		}
		if (j != n) {
			dum = 1 / a.element(j,j);
			for (i = j+1; i < n; i++) {
				a.element(i,j) *= dum;
			}
		}
	}

	return a;
}

//----------------------------------------------------------------------------
// LU back substitution
//----------------------------------------------------------------------------

SquareMatrix SqMRO_LUBackSubstitution::operator()(RowVector &indx, RowVector &b) const {

	SquareMatrix a(*m_thisMatrix);
	int n, i, j, ip, ii = -1;
	double sum;

	n = a.getRows();

	for (i = 0; i < n; i++) {
		ip = (int)indx(i);
		sum = b.element(ip);
		b.element(ip) = b.element(i);
		if (ii != -1) {
			for (j = ii; j < i; j++) {
				sum -= a.element(i,j) * b.element(j);
			}
		} else if (sum) {
			ii = i;
		}
		b.element(i) = sum;
	}
	for (i = (n - 1); i >= 0; i--) {
		sum = b.element(i);
		for (j = (i + 1); j < n; j++) {
			sum -= a.element(i,j) * b.element(j);
		}
		b.element(i) = sum / a.element(i,i);
	}

	return a;
}



//--------------------------------------------------------------
//				SquareMatrix Write Operators
//--------------------------------------------------------------

void SqMWO_EqualsElementCopyResize::operator()(const MatrixAliasConstant& copy) const
{
		unsigned int i, j;

		if(copy.isSquareMatrix() == 0)
		{
			error("SqMWO_EqualsElementCopyResize: Matrix to copy is not a square matrix\n");
			return;
		}


		if(copy.getColumns() != getColumns()) {
			// Resize!!

			// Change values
			setRows(copy.getRows());
			setColumns(copy.getColumns());

			// Delete old memory
			delete[] getDataPointer();

			// Allocate new memory
			setDataPointer(new double[getRows()*getColumns()]);
		}


		for (i = 0; i < getRows(); i++) {
			for (j = 0; j < getColumns(); j++) {
				element(i, j) = copy.element(i, j);
			}
		}
}

void SqMWO_Resize::operator()(const unsigned int size) const
{
	// Change values
	setRows(size);
	setColumns(size);

	// Delete old memory
	delete[] getDataPointer();

	// Allocate new memory
	setDataPointer(new double[size*size]);
}

void SqMWO_Identity::operator()() const
{
	unsigned int i;

	m_thisMatrix->zero();

	for (i = 0; i < getRows(); i++) {
		element(i,i) = 1;
	}

}


//----------------------------------------------------------------------------
// Make this a direction cosine matrix 1
//----------------------------------------------------------------------------

void SqMWO_DirectionCosine::operator()(ColumnVectorAlias attitude) {
	if (attitude.getRows() != 3) {
		error("Cannot compute direction cosine matrix for an attitude vector without 3 rows\n");
		m_thisMatrix->zero();
		//return *this;
	}
	m_thisMatrix->directionCosine(attitude.element(0), attitude.element(1), attitude.element(2));
}

//----------------------------------------------------------------------------
// Make this a direction cosine matrix 2
//----------------------------------------------------------------------------

void SqMWO_DirectionCosine::operator()(double phi, double theta, double psi) {

	double sx, sy, sz;
	double cx, cy, cz;

	// Check size of square matrix is valid
	if (getRows() != 3) {
		error("Cannot compute direction cosine matrix for a matrix without 3 rows and columns\n");
		m_thisMatrix->zero();
		//return *this;
	}

	// Calculate sines and cosines
	sx = sin(phi);
	sy = sin(theta);
	sz = sin(psi);
	cx = cos(phi);
	cy = cos(theta);
	cz = cos(psi);

	// Set the elements of the matrix
	element(0,0) = cy*cz;
	element(0,1) = cy*sz;
	element(0,2) = -sy;

	element(1,0) = sx*sy*cz-cx*sz;
	element(1,1) = sx*sy*sz+cx*cz;
	element(1,2) = sx*cy;

	element(2,0) = cx*sy*cz+sx*sz;
	element(2,1) = cx*sy*sz-sx*cz;
	element(2,2) = cx*cy;

	// Return a reference to ourselves
	//return *this;
}


//--------------------------------------------------------------
//				RowVector Read Operators
//--------------------------------------------------------------

/*int RVRO_SizeCompatable::operator()(const MatrixAliasConstant& operand) const
{
	if(operand.getRows() == 1)
		return 1;  // Operand is a row vector

	return 0;  // Operand is NOT a row vector
}*/


//----------------------------------------------------------------------------
// Cross product
//----------------------------------------------------------------------------

RowVector RVRO_CrossProduct::operator()(const RowVectorAliasConstant &operand) const {

	RowVector result(getColumns());

	if (operand.getColumns() != getColumns()) {

		error("RowVectorAlias::cross : Dimensions are not consistent\n");

	} else if (operand.getRows() != 3) {

		error("RowVectorAlias::cross : Only vectors of length 3 are valid at this time\n");

	} else {

		result(0) = element(1) * operand(2) - element(2) * operand(1);
		result(1) = element(2) * operand(0) - element(0) * operand(2);
		result(2) = element(0) * operand(1) - element(1) * operand(0);
	}

	return result;
}

//----------------------------------------------------------------------------
// Dot product
//----------------------------------------------------------------------------

double RVRO_DotProduct::operator()(const RowVectorAliasConstant &operand) const {

	double result = 0;
	unsigned int i;

	if (operand.getColumns() != getColumns()) {

		error("RowVectorAlias::dot : Dimensions are not consistent\n");

	} else {

		for (i = 0; i < getColumns(); i++) {
			result += element(i) * operand.element(i);
		}
	}

	return result;
}

//----------------------------------------------------------------------------
// Direction of this vector
//----------------------------------------------------------------------------

RowVector RVRO_Direction::operator()() const
{
	RowVector result(m_thisMatrix);

	result.normalise();
	return result;
}

//--------------------------------------------------------------
//				RowVector Write Operators
//--------------------------------------------------------------

void RVWO_EqualsElementCopyResize::operator()(const MatrixAliasConstant& copy) const
{
		unsigned int i;

		if(copy.isRowVector() == 0)
		{
			error("RVWO_EqualsElementCopyResize: Matrix to copy is not a row vector\n");
			return;
		}


		if(copy.getColumns() != getColumns()) {
			// Resize!!

			// Change values
			setColumns(copy.getColumns());

			// Delete old memory
			delete[] getDataPointer();

			// Allocate new memory
			setDataPointer(new double[getColumns()]);
		}


		for (i = 0; i < getColumns(); i++) {
			element(0, i) = copy.element(0, i);
		}

}

void RVWO_Resize::operator()(const unsigned int size) const
{
	// Change values
	setRows(1);
	setColumns(size);

	// Delete old memory
	delete[] getDataPointer();

	// Allocate new memory
	setDataPointer(new double[size]);
}

//--------------------------------------------------------------
//				ColumnVector Read Operators
//--------------------------------------------------------------

/*int CVRO_SizeCompatable::operator()(const MatrixAliasConstant& operand) const
{
	if(operand.getColumns() == 1)
		return 1;  // Operand is a column vector

	return 0;  // Operand is NOT a column vector
}*/


//----------------------------------------------------------------------------
// Cross product
//----------------------------------------------------------------------------

ColumnVector CVRO_CrossProduct::operator()(const ColumnVectorAliasConstant &operand) const {

	ColumnVector result(getRows());

	if (operand.getRows() != getRows()) {

		error("ColumnVectorAlias::cross : Dimensions are not consistent\n");

	} else if (operand.getRows() != 3) {

		error("ColumnVectorAlias::cross : Only vectors of length 3 are valid at this time\n");

	} else {

		result(0) = element(1) * operand(2) - element(2) * operand(1);
		result(1) = element(2) * operand(0) - element(0) * operand(2);
		result(2) = element(0) * operand(1) - element(1) * operand(0);
	}

	return result;
}

//----------------------------------------------------------------------------
// Dot product
//----------------------------------------------------------------------------

double CVRO_DotProduct::operator()(const ColumnVectorAliasConstant &operand) const {

	double result = 0;
	unsigned int i;

	if (operand.getRows() != getRows()) {

		error("ColumnVectorAlias::dot : Dimensions are not consistent\n");

	} else {

		for (i = 0; i < getRows(); i++) {
			result += element(i) * operand.element(i);
		}
	}

	return result;
}

//----------------------------------------------------------------------------
// Direction of this vector
//----------------------------------------------------------------------------

ColumnVector CVRO_Direction::operator()() const
{
	ColumnVector result(m_thisMatrix);

	result.normalise();
	return result;
}

//--------------------------------------------------------------
//				ColumnVector Write Operators
//--------------------------------------------------------------

void CVWO_EqualsElementCopyResize::operator()(const MatrixAliasConstant& copy) const
{
		unsigned int i;

		if(copy.isColumnVector() == 0)
		{
			error("CVWO_EqualsElementCopyResize: Matrix to copy is not a column vector\n");
			return;
		}


		if(copy.getRows() != getRows()) {
			// Resize!!

			// Change values
			setRows(copy.getRows());

			// Delete old memory
			delete[] getDataPointer();

			// Allocate new memory
			setDataPointer(new double[getRows()]);
		}


		for (i = 0; i < getRows(); i++) {
			element(i, 0) = copy.element(i, 0);
		}

}

void CVWO_Resize::operator()(const unsigned int size) const
{
	// Change values
	setRows(size);
	setColumns(1);

	// Delete old memory
	delete[] getDataPointer();

	// Allocate new memory
	setDataPointer(new double[size]);
}
