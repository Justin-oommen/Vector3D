//Vector3D.cc
#include "Vector3D.h"
#include<iostream>
#include<cmath>
using std::cout;
using std::endl;

Vector3D::Vector3D (){
  coordinate1_=0;
  coordinate2_=0;
  coordinate3_=0;
}


//magnitude
double Vector3D::magnitude() const{
  return sqrt ( pow(coordinate1_,2)+pow(coordinate2_,2)+pow(coordinate3_,2));
}

//theta
double Vector3D::theta() const {
  //double m = m.magnitude();
  return atan((sqrt (pow(coordinate1_,2)+pow(coordinate2_,2) ))/coordinate3_);
}

//phi
double Vector3D::phi() const{
  return atan(coordinate2_/coordinate1_);
}

//scalar product
//a.b=x1x2+y1y2+z1z2
double Vector3D::scalar_product(const Vector3D& rhs) const{
  double scalar = (coordinate1_*rhs.coordinate1_)+(coordinate2_*rhs.coordinate2_)+(coordinate3_*rhs.coordinate3_);
  return scalar;
}

//Vector Product
//a x b = ((x2y3-x3y2),(x1y3-x3y1),(x1y2-x2y1))
Vector3D Vector3D::vector_product(const Vector3D& rhs) const{
  double coordinate1 = (coordinate2_*rhs.coordinate3_) - (coordinate3_*rhs.coordinate2_);
  double coordinate2 = (coordinate1_*rhs.coordinate3_) - (coordinate3_*rhs.coordinate1_);
  double coordinate3 = (coordinate1_*rhs.coordinate2_) - (coordinate2_*rhs.coordinate1_);

  return Vector3D(coordinate1,coordinate2,coordinate3);
}

//overloading operators +,-,=
//a+b = (x1+y1),(x2+y2),(x3+y3)
//a-b = (x1-y1),(x2-y2),(x3-y3)
Vector3D Vector3D::operator+(const Vector3D& rhs) const{
  double coordinate1 = coordinate1_ + rhs.coordinate1_;
  double coordinate2 = coordinate2_ + rhs.coordinate2_;
  double coordinate3 = coordinate3_ + rhs.coordinate3_;

  return Vector3D(coordinate1, coordinate2, coordinate3);
}

Vector3D Vector3D::operator-(const Vector3D& rhs) const{
  double coordinate1 = coordinate1_ - rhs.coordinate1_;
  double coordinate2 = coordinate2_ - rhs.coordinate2_;
  double coordinate3 = coordinate3_ - rhs.coordinate3_;

  return Vector3D(coordinate1, coordinate2, coordinate3);
}

const Vector3D& Vector3D::operator=(const Vector3D& rhs){
  coordinate1_ = rhs.coordinate1_;
  coordinate2_ = rhs.coordinate2_;
  coordinate3_ = rhs.coordinate3_;

  return *this;
}

//overloading <,>
//bool Vector3D::operator<(const Vector3D& rhs) const{
//return ()
//}

//overloading *,/ to multiply and divide by float
Vector3D Vector3D::operator*(const float& rhs) const{
  return Vector3D(coordinate1_*rhs, coordinate2_*rhs, coordinate3_*rhs);
}

Vector3D Vector3D::operator/(const float& rhs) const{
  return Vector3D(coordinate1_/rhs, coordinate2_/rhs, coordinate3_/rhs);
}

//global method to achieve symmetry of the above operation
Vector3D operator*(const float& lhs, const Vector3D& rhs){
  return Vector3D(lhs*rhs.coordinate1_, lhs*rhs.coordinate2_, lhs*rhs.coordinate3_);
}

Vector3D operator/(const float& lhs, const Vector3D& rhs){
  return Vector3D(rhs.coordinate1_/lhs, rhs.coordinate2_/lhs, rhs.coordinate3_/lhs);
}

//overloading <<
std::ostream& operator<<(std::ostream& os, const Vector3D& rhs){
  using namespace std;
  os << " = " << rhs.coordinate1_<< "i^ + "<< rhs.coordinate2_<<" j^ + "<<rhs.coordinate3_<<" k^";
  return os;
}

//print
void Vector3D::print(const std::string& vector) const{
  cout<< vector << " = " << coordinate1_<< "i^ + "<<coordinate2_<<" j^ +  "<<coordinate3_<<" k^"<<endl;
}
