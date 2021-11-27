//Vector.cpp
#include "Vector3D.h"

int main(){

  //vector
  double x1=1;
  double x2=1;
  double x3=1;

  //spherical polar
  Vector3D v1= Vector3D::Polar(x1,x2,x3);
  //Cartesian
  Vector3D v2 = Vector3D::Cartesian(x1,x2,x3);

  v1.print("v1");
  v2.print("v2");

  std::cout<<"v1"<<v1<<std::endl;
  
  return 0;
}
