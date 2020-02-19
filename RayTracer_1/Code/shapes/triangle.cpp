#include "triangle.h"

Hit Triangle::intersect(Ray const &ray)
{
		if (N.dot(ray.D) >= 0) {
				return Hit::NO_HIT();
		}
		
    Vector OS = v0 - ray.O;
		Vector perp = OS.dot(ray.D) * ray.D;
		Vector Sperp = perp - OS;
		Vector Sint = N.cross(Sperp);
		Sint = Sint.cross(N);
    
    
    double t;
    
    return Hit(t, N);
}

Triangle::Triangle(Point const &v0,
                   Point const &v1,
                   Point const &v2)
:
    v0(v0),
    v1(v1),
    v2(v2),
    N()
{
    N = (v1-v0).cross(v2-v0);
}
