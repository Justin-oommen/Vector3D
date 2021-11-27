//Vector3D.h  
#ifndef Vector3D_h
#define Vector3D_h
#include<cmath>
#include<iostream>
//#include<vector>
using std::cout;
using std::cin;
using std::endl;

class Vector3D{

 public:
  //default constructor
  Vector3D();
  //spherical-polar coordinate(r,theta,phi)
  static Vector3D Polar(double r, double theta, double phi){
    return Vector3D(r*sin(theta)*cos(phi), r*sin(theta)*sin(phi), r*cos(theta));
  }
  //cartesian coordinate(x,y,z)
  static Vector3D Cartesian(double x, double y, double z){
    return Vector3D(x,y,z);
  }
  //Destructor
  ~Vector3D() {};

  //getter methods

  //get the coordinates
  double coordinate_x() const {
    return (coordinate1_);
  }
  double coordinate_y() const {
    return (coordinate2_);
  }
  double coordinate_z() const {
    return (coordinate3_);
  }

  //calculate the magnitude
  double magnitude() const;
  //Calculate theta
  double theta() const;
  //Calculate Phi
  double phi() const;
  //Scalar Product
  double scalar_product(const Vector3D& rhs ) const;
  //Vector Product
  Vector3D vector_product(const Vector3D& rhs) const;

  //setter method
  //change the coordinate values
  void setCoordinates(double coordinate1, double coordinate2, double coordinate3){coordinate1_= coordinate1; coordinate2_ = coordinate2 ; coordinate3_ = coordinate3;} 


  //overloading operators +,-,=
  Vector3D operator+(const Vector3D& rhs) const;
  Vector3D operator-(const Vector3D& rhs) const;
  const Vector3D&  operator=(const Vector3D& rhs);

  //overloading  <,>
  // bool operator<(const Vector3D& rhs) const;
  //bool operator>(const Vector3D& rhs) const;

  //overloading >=,<=
  //const Vector3D& operator>=(const Vector3D& rhs);
  //const Vector3D& operator<=(const Vector3D& rhs);
  
  //overloading * and / to multiply and divide by a float
  Vector3D operator*(const float& rhs) const;
  Vector3D operator/(const float& rhs) const;
  //using friend method to achieve symmetry of the above operation
  friend Vector3D operator*(const float& lhs, const Vector3D& rhs);
  friend Vector3D operator/(const float& lhs, const Vector3D& rhs);
  
  //overloading <<
  friend std::ostream& operator<<(std::ostream& os, const Vector3D& rhs);

  //Utility function
  void print(const std::string& vector) const;
  
  
 private:
  double coordinate1_;
  double coordinate2_;
  double coordinate3_;

  //Regular Constructor:
  Vector3D(double coordinate1, double coordinate2, double coordinate3){
    coordinate1_=coordinate1;
    coordinate2_=coordinate2;
    coordinate3_=coordinate3;
  };
  
  
};

#endif
