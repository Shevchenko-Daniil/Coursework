#include <iostream>
#include "Vector3D/vector3D.h"
#include "System/system.h"



int main(){

	System s;

	for(int i=0; i<400; ++i){
		s.RK4_step(3e-17);
		std::cout<<s.gett()<<"     "<<s.getr()<<"     "<<s.getu()<<"\n";
	}
}




