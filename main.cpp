#include <iostream>
#include "Vector3D/vector3D.h"
#include "System/system.h"



int main(){
	std::cout<<"It is working!\n";

	/*Vector3D v = Vector3D{2., 6., 8.};
	//std::cin>>v;
	std::cout<<v<<"\n";
	double l = v.length();
	std::cout<<l<<"\n";*/



	System s;


	for(int i=0; i<1000; ++i){
		s.RK4_step(1.2e-14);
		std::cout<<s.gett()<<"     "<<s.getr()<<"     "<<s.getu()<<"\n";
	}
}




