#include "eigen3/Eigen/Dense"
#include "eigen3/Eigen/Geometry"
#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;
using namespace Eigen;

#define print(obj) cout << "Array : \n" << obj << endl;

void ArrayDefination() {
	// better in coefficient-wise operations
	// define an array 
	Array<float, 2, 2> array;
	// print(array);
	// same type
	// Array<float,Dynamic,1> ArrayXf 
	// Array<float,3,1> Array3f 
	// Array<double,Dynamic,Dynamic> ArrayXXd 
	// Array<double,3,3> Array33d 

	// accessing value inside of Array
	array(0,0) = 1;
	array(0,1) = 2;
	array(1,0) = 3;
	array(1,1) = array(0,0)+array(1,0);

	cout << "Array " << array << endl;

	ArrayXXf arr(2,3);
	arr << 1, 2, 3, 4, 5, 6;
	cout << "arr 2, 3 " << arr << endl;
}

void ArrayOperation() {
	ArrayXXf lhs(2,2), rhs(2,2);
	print(lhs);
	lhs << 1, 2, 3, 4;
	rhs << 5, 6, 7, 8;
	print(lhs);
	print(rhs);
	cout << "operation multiply " << lhs*rhs << endl;
	lhs << -1, 2, -3, 4;
	rhs << 5, -6, 7, -8;
	print(lhs);
	print(rhs);
	cout << "abs\n";
	print(lhs.abs());
	cout << "abs().sqrt()\n";
	print(lhs.abs().sqrt());
	cout << "lhs.min(rhs)\n";
	print(lhs.min(rhs));
}

void ArrayAndMatrix() {
	// operation cann't replacement with each other
	MatrixXf m(2,2), n(2,2), result(2,2);
	m << 1,2,3,4;
	n << 5,6,7,8;
	result = m*n;
	result = m.array();
	cout << "m*n " << result << endl;
	ArrayXXf foo;
	foo = m.matrix();
	foo = m.array() * n.array();
	cout << ".matrix() " << foo.matrix() << endl;
	print(foo);
	result = m.array() * n.array();
	cout << "m.array() * n.array(): " << result << endl;
	result = m.cwiseProduct(n);
  cout << "-- With cwiseProduct: --" << endl << result << endl << endl;
  result = m.array() + 5;
  cout << "-- Array m + 4: --" << endl << result << endl << endl;
}

void TranslationFunc() {
	Rotation2D<float> rot2(0);
	cout << "rot2(0)\n" << rot2.matrix() << endl;
	Rotation2Df rotation2(3.141592653);
	// foo = rotation2 if forbidden
	Matrix2f foo = rotation2.matrix();
	cout << "foo=\n" << foo << endl;
	Translation2f tf2(1,2);
	Vector2f p(3,4);
	// vector sum
	cout << tf2*p << endl;
	cout << tf2.inverse()*p << endl;
	Translation<float, 3> tf3;
	Affine2f af2f;
	Transform<float, 3, Affine> af3f;
	AngleAxisf temp(0, Vector3f::UnitZ());
	Transform<float, 4, Affine> bar;
	bar.setIdentity();
	cout << bar.translation() << endl;
	cout << bar.rotation() << endl << endl;
	// cout << bar * Vector3f(1, 0, 0) << endl << endl;
	cout << bar.linear() * Vector4f(1, 0, 0, 0) << endl;
}

int main() {
	// ArrayDefination();
	// ArrayOperation();
	// ArrayAndMatrix();
	TranslationFunc();
	return 0;
}