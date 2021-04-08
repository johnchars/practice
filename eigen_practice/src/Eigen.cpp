#include "eigen3/Eigen/Dense"
#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;
using namespace Eigen;

int main() {
	Matrix<float, 2, 4> foo;
	foo << 1.0 , 2.0 , 3.0 , 4.0,
		 5.0 , 6.0 , 7 , 8;
	cout << "Size:  " << foo.size() << endl;
	cout << "rows*columns = [" << foo.rows() << ", " << foo.cols() 
		<< "]\n";
	cout << "col(1): " << foo.col(0) << endl;
	cout << "foo.row(1).mean: " << foo.row(1).mean() << endl;
	foo.col(0) -= foo.col(1);
	cout << "foo.col(0).rows() * cols(): [" << foo.col(0).rows() 
		<< ", " << foo.col(0).cols() << "]\n";
	foo(0,3) = 10;
	cout << "foo updated:" << foo << endl;
	cout << "foo.col(0)-foo.col(1): " << foo.col(0)-foo.col(1) <<  endl;

	Matrix<float, 2, 1> bar;
	bar << 5,5;
	cout << "bar:" << bar << endl;
	cout << "foo.col(0)-bar: " << foo.col(0)-bar <<  endl;

	JacobiSVD<MatrixXf> svd(foo, ComputeThinU | ComputeThinV);
	cout << "Its singular values are:" << endl << svd.singularValues() << endl;
	cout << "Its left singular vectors are the columns of the thin U matrix:" 
		<< endl << svd.matrixU() << endl;
	cout << "Its right singular vectors are the columns of the thin V matrix:"
	  << endl << svd.matrixV() << endl;


	Matrix<int, 2, Eigen::Dynamic> foobar(2,10);
	std::cout <<"rows*cols: "<< foobar.rows() <<", " << foobar.cols() << std::endl;
	for (int i =0; i< 10; i++) {
		//foobar.resize(2,i+1);
		foobar(0,i) = i;
		foobar(1,i) = i+1;
		std::cout << "rows*cols: " << foobar.rows()
			<< ", " << foobar.cols() << std::endl;
	}
	std::cout << "foobar: \n" << foobar << std::endl; 

	Eigen::Vector3d position(0.0, 1.0, 2.0);
	std::cout << "x, y, z: " << position.x() << ", "
		<< position.y() << ", " << position.z() << '\n';
	std::cout << "Vector3d elements: " << position[0]
		<< ", " << position[1] << ", " << position[2] 
		<< std::endl;

	std::cout << "------分割线------\n";
	const float step = 0.2;
  const float head = -3.2;
  const float tail = 3.2;
  std::cout << "((tail-head)/step): "<< (tail-head)/step << std::endl;
  std::cout << "typeid int((tail-head)/step): "<< typeid((tail-head)/step).name() << std::endl;
  std::cout << "int((tail-head)/step): "<< int((tail-head)/step) << std::endl;

  std::cout << "======line=======\n";
  std::vector< std::vector<float> > box;
  std::cout << "1. box.size(): " << box.size();// << ", box[10].size(): " << box[10].size() << endl;
  box.resize(32);
  std::cout << "2. box.size(): " << box.size() << ", box[10].size(): " << box[10].size() << endl;
  box.reserve(32);
  std::cout << "3. box.size(): " << box.size() << ", box[10].size(): " << box[10].size() << endl;

  cout << "------Eigen-------\n";
  cout << "UnitZ: " << Eigen::Vector3d::UnitZ() << endl;


  cout << "------array-------\n";
  Eigen::Vector2d points[2];
  for (int i=0; i<2; i++) {
  	points[i][0] = 1.0+i;
  	points[i][1] = 2.0+i;
  }

  for (int i=0; i<2; i++) {
  	std::cout << i << ": [" << points[i][0] << ", " << points[i][1] << "]\n";
  }
	return 0;
}