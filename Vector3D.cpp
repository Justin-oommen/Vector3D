//Vector.cpp
#include "Vector3D.h"

int main(){

  //vector
  double x1=1;
  double x2=2;
  double x3=3;

  double y1 = 4;
  double y2 = 3;
  double y3 = 2;

  //spherical polar
  //Vector3D v1= Vector3D::Polar(x1,x2,x3);
  //Cartesian
  Vector3D v = Vector3D::Cartesian(x1,x2,x3);
  Vector3D y = Vector3D::Cartesian(y1,y2,y3);
  v.print("v");
  y.print("y");

  //std::cout<<"v1"<<v1<<std::endl;

  //get the coordinate
  double v3_x= v.coordinate_x();
  std::cout<<"Coordinates X :"<<v3_x<<std::endl;
  double v3_y= v.coordinate_y();
  std::cout<<"Coordinates Y :"<<v3_y<<std::endl;
  double v3_z= v.coordinate_z();
  std::cout<<"Coordinates Z :"<<v3_z<<std::endl;

  double v4_x = y.coordinate_x();
  std::cout<<"Coordinates X :"<<v4_x<<std::endl;
  double v4_y = y.coordinate_y();
  std::cout<<"Coordinates Y :"<<v4_y<<std::endl;
  double v4_z = y.coordinate_z();
  std::cout<<"Coordinates Z :"<<v4_z<<std::endl;

  //magnitude
  double v5 = v.magnitude();
  std::cout<<"Magnitude : "<<v5<<std::endl;
  double v6 = y.magnitude();
  std::cout<<"Magnitude : "<<v6<<std::endl;

  //theta
  double v7 = v.theta();
  std::cout<<"Theta : "<<v7<<std::endl;
  double v8 = y.theta();
  std::cout<<"Theta : "<<v8<<std::endl;

  //scalar product
  double scalar = v.scalar_product(y);
  std::cout<<"Scalar : "<<scalar<<std::endl;
  
  return 0;
}
