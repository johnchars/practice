#include <utility>
#include <iostream>
#include <string>
#include <tuple>
#include <eigen3/Eigen/Dense>

using namespace Eigen;
using std::cout;
using std::cin;
using std::endl;

namespace practice {
	class Foo {
		public:
			Foo():table_(0,"Empty") {};
			~Foo() {};
			void show() const;
			void ShowInfo() const;
			void fill(int id, std::string name);
			bool FillInfo(int, std::string, float);
			void FillRotation(float angle, Vector3f axis);
			void ToQuaternion() const;
		private:
			std::pair<int,std::string> table_;
			std::tuple<int, std::string, float> info_;
			AngleAxisf rotation_;
	};
}