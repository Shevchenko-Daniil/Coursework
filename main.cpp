#include <iostream>
#include "Vector3D/vector3D.h"
#include "System/system.h"
#include <cmath>



int main(){

	System s;

	double T = M_PI * 2 * 1e-9/sqrt( scalprod(s.getu(), s.getu()) );
	double dt = T/400;
	for(int i=0; i<400; ++i){
		s.RK4_step(dt);
		std::cout<<s.gett()<<"     "<<s.getr()<<"     "<<s.getu()<<"\n";
	}
}




