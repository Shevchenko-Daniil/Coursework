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

	Vector3D ku1, ku2, ku3, ku4;
	ku1 = func2(r);
	ku2 = func2(r + 0.5*dt*ku1);
	ku3 = func2(r + 0.5*dt*ku2);
	ku4 = func2(r + ku3*dt);

	u += (dt/6.)*(ku1 + 2.*ku2 + 2.*ku3 + ku4);

	Vector3D kr1, kr2, kr3, kr4;

	kr1 = u0;
	kr2 = u0 + 0.5*dt*kr1;
	kr3 = u0 + 0.5*dt*kr2;
	kr4 = u0 + kr3*dt;


	r += (dt/6.)*(kr1 + 2.*kr2 + 2.*kr3 + kr4);

	t += dt;

	/*
	Vector3D dr = u*dt;
	Vector3D du = gamma*k*( r * (3*scalprod(p, r) + q*r.length()*r.length())/pow(r.length(), 5) - p/pow(r.length(), 3)  )*dt;

	t +=dt;
	u +=du;
	r +=dr;*/
}



