#include "include/matrix.h"

#include <iostream.h>

void main()
{

	// some data
	double * data;
	data = new double[9];

	double * data2;
	data2 = new double[9];

	data[0] = 1;
	data[1] = 2;
	data[2] = 3;
	data[3] = 4;
	data[4] = 5;
	data[5] = 6;
	data[6] = 7;
	data[7] = 8;
	data[8] = 9;

	MatrixAliasConstant mac(data,3,3);
	MatrixAlias ma(data,3,3);
	Matrix m(ma);

	MatrixAliasConstant mac2(data2,3,3);
	MatrixAlias ma2(data2,3,3);
	Matrix m2(3,3);


	/*printf("MAC = MAC\n");
	mac2 = mac;

	printf("MAC = MA\n");
	mac2 = ma;

	printf("MAC = M\n");
	mac2 = m;

	printf("MA = MAC\n");
	ma2 = mac;

	printf("MA = MA\n");
	ma2 = ma;

	printf("MA = M\n");
	ma2 = m;

	printf("M = MAC\n");
	m2 = mac;

	printf("M = MA\n");
	m2 = ma;

	printf("M = M\n");
	m2 = m;*/

	ColumnVectorAliasConstant cvac(data2,9);
	ColumnVectorAlias cva(data2,9);
	ColumnVector cv(9);

	ColumnVectorAliasConstant cvac2(data2,9);
	ColumnVectorAlias cva2(data2,9);
	ColumnVector cv2(9);

	printf("CVAC = MAC\n");
	cvac = mac;

	printf("CVAC = MA\n");
	cvac = ma;

	printf("CVAC = M\n");
	cvac = m;

	printf("CVA = MAC\n");
	cva = mac;

	printf("CVA = MA\n");
	cva = ma;

	printf("CVA = M\n");
	cva = m;

	printf("CV = MAC\n");
	cv = mac;

	printf("CV = MA\n");
	cv = ma;

	printf("CV = M\n");
	cv = m;


	printf("CVAC = MAC\n");
	cvac = cvac2;

	printf("CVAC = MA\n");
	cvac = cva2;

	printf("CVAC = M\n");
	cvac = cv2;

	printf("CVA = MAC\n");
	cva = cvac2;

	printf("CVA = MA\n");
	cva = cva2;

	printf("CVA = M\n");
	cva = cv2;

	printf("CV = MAC\n");
	cv = cvac2;

	printf("CV = MA\n");
	cv = cva2;

	printf("CV = M\n");
	cv = cv2;

	ColumnVector a = mac.subMatrix(0,2,0,0);
	ColumnVector b(3);
	ColumnVector c(3);

	//a = mac.subMatrix(0,2,0,0);
	b = mac.subMatrix(0,2,1,1);
	c = mac.subMatrix(0,2,2,2);

	a.print();
	b.print();
	c.print();

	RowVector ar = mac.subMatrix(0,0,0,2);
	RowVector br(3);
	RowVector cr(3);

	br = mac.subMatrix(1,1,0,2);
	cr = mac.subMatrix(2,2,0,2);

	ar.print();
	br.print();
	cr.print();

	delete data;
	delete data2;

	SquareMatrix A(3);

	A.rand();

	Matrix B(3,2);

	B.rand();

	ColumnVector x(3);

	x.rand();

	ColumnVector u(2);

	u.rand();

	A.printM();
	x.printM();
	B.printM();
	u.printM();

	//ColumnVector y(2);

	ColumnVector y(10);

	printf("here1\n");

	//printf("CVR:%d\n",y.getRows());
	y.print();
	//printf("here1\n");
	y = A*x + B*u;

	y.equals(A.multiply(x).add(B.multiply(u)));

	//printf("CVR:%d\n",y.getRows());
	//printf("here2\n");
	y.print();

	ColumnVector CV(5);
	RowVector RV(5);

	CV.rand();
	RV.rand();

	printf("here2\n");

	CV.print();
	RV.print();

	SquareMatrix M1 = CV * RV;
	SquareMatrix M2 = RV * CV;

	M1.print();
	M2.print();

	printf("%lf\n",M1.maximum());
	printf("%lf\n",M1.minimum());
	printf("%lf\n",M1.infinityNorm());

	Matrix M3(3,4);

	M3.rand();

	M3.print();

	M3.transpose().print();

	M3.rowSum().print();

	M3.columnSum().print();

	M3.squaredElements().print();

	SquareMatrix thing(3);

	thing.rand();

	thing.directionCosine(1,2,3);

	thing.print();

	RowVector name(3);

	name.rand();

	name.print();

	name.transpose().print();

	ColumnVector colvec(3);
	ColumnVector operand(3);

	operand.rand();

	colvec.rand();

	colvec.print();

	//colvec.cross(operand).print();

	printf("%lf\n",colvec.dot(operand));
	printf("%lf\n",colvec.modulus());

	Matrix z;

	z.print();

	z.resize(4,4);

	z.print();

	ColumnVector colvector;

	printf("here\n");

	colvector.print();

	colvector.resize(3);

	colvector.print();


	//M1.exponential(2).print();
/*
	// some data
	double * data;
	data = new double[9];

	data[0] = 1;
	data[1] = 2;
	data[2] = 3;
	data[3] = 4;
	data[4] = 5;
	data[5] = 6;
	data[6] = 7;
	data[7] = 8;
	data[8] = 9;

	MatrixAlias a(data,3,3);



	a(0,0) = 5;

	printf("a:\n");
	a.print();


	MatrixAlias b(data,3,3);


	b(0,0) = 5;

	printf("b:\n");
	b.print();


	SubMatrixAliasConstant c(a,1,2,1,2);

	//c(0,0) = 10;

	printf("c:\n");
	c.print();

	SubMatrixAlias d(a,1,2,1,2);

	d(0,0) = 10;



	printf("d:\n");
	d.print();

	printf("a:\n");
	a.print();

	Matrix A(2,2);

	A(0,0) = 2;
	A(0,1) = 4;
	A(1,0) = 6;
	A(1,1) = 8;

	printf("A:\n");
	A.print();

	A = a;
	A(1,1) = 25;

	printf("A:\n");
	A.print();

	printf("a:\n");
	a.print();


	Matrix B = A;

	printf("B:\n");
	B.print();

	SubMatrixAlias S(B,0,1,0,1);

	S.zero();

	printf("B:\n");
	B.print();

	Matrix Z(6,6);

	SubMatrixAlias i(Z,0,1,0,1);
	SubMatrixAlias ii(Z,0,1,2,3);
	SubMatrixAlias iii(Z,0,1,4,5);
	SubMatrixAlias iv(Z,2,3,0,1);
	SubMatrixAlias v(Z,2,3,2,3);
	SubMatrixAlias vi(Z,2,3,4,5);
	SubMatrixAlias vii(Z,4,5,0,1);
	SubMatrixAlias viii(Z,4,5,2,3);
	SubMatrixAlias ix(Z,4,5,4,5);

	i.set(1);
	ii.set(2);
	iii.set(3);
	iv.set(4);
	v.set(5);
	vi.set(6);
	vii.set(7);
	viii.set(8);
	ix.set(9);

	printf("Z:\n");
	Z.print();

	Matrix Y(6,1);

	Y(0,0) = 1;
	Y(1,0) = 2;
	Y(2,0) = 3;
	Y(3,0) = 4;
	Y(4,0) = 5;
	Y(5,0) = 6;

	Matrix X(6,1);

	MatrixAlias W(Z);

	X = W * Y;

	printf("X:\n");
	X.print();

	SubMatrixAlias sub(Z,1,4,1,4);

	printf("sub:\n");
	sub.print();

	Matrix op(4,1);

	op(0,0) = 1;
	op(1,0) = 2;
	op(2,0) = 3;
	op(3,0) = 4;

	X = sub * op;

	printf("X:\n");
	X.print();

	SubMatrixAlias subop(Z,0,3,5,5);

	printf("subop:\n");
	subop.print();

	X = sub * subop;

	printf("X:\n");
	X.print();

	X = 2*X;

	printf("X:\n");
	X.print();


	SquareMatrix sqm(4);

	sqm.identity();

	sqm.print();

	SquareMatrix sqm2(sqm);

	sqm2.print();

	sqm2.element(0,0) = 20;

	sqm2.print();
	sqm.print();

	RowVector rv(4);

	rv(0) = 1;
	rv(1) = 2;
	rv(2) = 3;
	rv(3) = 4;

	rv.print();

	ColumnVector cv(4);

	cv(0) = 1;
	cv(1) = 2;
	cv(2) = 3;
	cv(3) = 4;

	cv.print();

	Matrix ans = cv * rv;

	ans.print();

	SquareMatrix fred(4);

	fred(0,0) = 1;
	fred(0,1) = 2;
	fred(0,2) = 3;
	fred(0,3) = 4;
	fred(1,0) = 5;
	fred(1,1) = 6;
	fred(1,2) = 7;
	fred(1,3) = 8;
	fred(2,0) = 9;
	fred(2,1) = 10;
	fred(2,2) = 11;
	fred(2,3) = 12;
	fred(3,0) = 13;
	fred(3,1) = 14;
	fred(3,2) = 15;
	fred(3,3) = 16;

	fred.rand();

	fred.printM();

	SquareMatrix fred2 = fred.inverse();

	fred2.print();

	SquareMatrix fred3 = fred2.inverse();

	fred3.print();*/



}