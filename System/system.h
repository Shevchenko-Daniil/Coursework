#ifndef SYSTEM_SYSTEM_H_
#define SYSTEM_SYSTEM_H_

#include "../Vector3D/vector3D.h"


class System{
private:
	double q, gamma, t;
	Vector3D p, r, u;

public:
	System(double q0, double g, double t0, Vector3D p0, Vector3D r0, Vector3D u0): q(q0), gamma(g), t(t0), p(p0), r(r0), u(u0){}
	System(){
		q = 1.6e-19;
		gamma = -1.76e11;
		t = 0;
		p = Vector3D{6.11e-33, 0, 0};
		r = Vector3D{0, 1e-9, 0};
		u = Vector3D{5e5, 0, 0};
	}

	Vector3D func1(Vector3D R);  //как в задаче
	Vector3D func2(Vector3D R);  //по окружности

	void RK4_step(double dt);


	Vector3D getr(){return r;}
	double gett(){return t;}
	Vector3D getu(){return u;}



};





#endif /* SYSTEM_SYSTEM_H_ */
