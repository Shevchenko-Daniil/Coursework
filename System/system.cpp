#include "system.h"
#include <cmath>


const double k(9e9);

Vector3D System::func1(Vector3D R){
	return gamma*k*( R * (3*scalprod(p, R) + q*R.length()*R.length())/pow(R.length(), 5) - p/pow(R.length(), 3)  );
}

Vector3D System::func2(Vector3D R){
	return gamma*k*q*R/pow(R.length(), 3);
}


void System::RK4_step(double dt){
	Vector3D u0 = u;

	Vector3D k1, k2, k3, k4, l1, l2, l3, l4;

	k1 = u0;
	l1 = func1(r);
	k2 = u0 + 0.5*dt*l1;
	l2 = func1(r + 0.5*dt*k1);
	k3 = u0 + 0.5*dt*l2;
	l3 = func1(r + 0.5*dt*k2);
	k4 = u0 + l3*dt;
	l4 = func1(r + dt*k3);

	r += (dt/6.)*(k1 + 2*k2 + 2*k3 + k4);
	u += (dt/6.)*(l1 + 2*l2 + 2*l3 + l4);
	t += dt;

}



