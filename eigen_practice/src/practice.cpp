#include "practice/practice.h"

const float PI = 3.141592653;

#define ANGLE(x) x/180.0*PI 

namespace practice {
	void Foo::show() const {
		std::cout << "ID: " << table_.first 
			<< ", Name: " << table_.second << std::endl;
	}

	void Foo::fill(int id, std::string name) {
		table_.first = id;
		table_.second = name;
	}

	void Foo::ShowInfo() const {
		std::cout << "INFO:\nID: " << std::get<0>(info_) << ", Name: "
			<< std::get<1>(info_) << ", anyway: " << std::get<2>(info_) 
			<< std::endl;
	}

	bool Foo::FillInfo(int id, std::string name, float anyway) {
		info_ = std::make_tuple(id, name, anyway);
		return true;
	}

	void Foo::FillRotation(const float angle, const Vector3f axis) {
		rotation_= AngleAxisf(ANGLE(angle),axis);
	}

	void Foo::ToQuaternion() const {
		//cout << Quaternionf(rotation_).coeffs() << endl;
		cout << "w: " << Quaternionf(rotation_).coeffs().w() << endl;
		cout << "x: " << Quaternionf(rotation_).coeffs().x() << endl;
		cout << "y: " << Quaternionf(rotation_).coeffs().y() << endl;
		cout << "z: " << Quaternionf(rotation_).coeffs().z() << endl;
	}
}