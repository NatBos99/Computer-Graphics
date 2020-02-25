#include "sphere.h"

#include <cmath>
#include <iostream>

using namespace std;

Hit Sphere::intersect(Ray const &ray)
{
    /****************************************************
    * RT1.1: INTERSECTION CALCULATION
    *
    * Given: ray, position, r
    * Sought: intersects? if true: *t
    *
    * Insert calculation of ray/sphere intersection here.
    *
    * You have the sphere's center (C) and radius (r) as well as
    * the ray's origin (ray.O) and direction (ray.D).
    *
    * If the ray does not intersect the sphere, return false.
    * Otherwise, return true and place the distance of the
    * intersection point from the ray origin in *t (see example).
    ****************************************************/

    /****************************************************
    * RT1.2: NORMAL CALCULATION
    *
    * Given: t, C, r
    * Sought: N
    *
    * Insert calculation of the sphere's normal at the intersection point.
    ****************************************************/
    
		Vector OC = ray.O - position;
		double a = ray.D.dot(ray.D);
		double b = 2.0 * OC.dot(ray.D);
		double c = OC.dot(OC) - r*r;
		double d = b*b - 4*a*c;
		
		bool inSphere = abs(OC.length()) < r;
		
		if(d < 0.0) {
			return Hit::NO_HIT();
		} else {
			double numerator = -b - sqrt(d);
			if (numerator > 0.0) {
				double t = numerator / (2.0 * a);
				Vector N = t*ray.D + OC;
				N.normalize();
				if (inSphere) N = -N;
				return Hit(t, N);
			}

			numerator = -b + sqrt(d);
			if (numerator > 0.0) {
				double t = numerator / (2.0 * a);
				Vector N = t*ray.D + OC;
				N.normalize();
				if (inSphere) N = -N;
				return Hit(t, N);
			} else {
				return Hit::NO_HIT();
			}
		}
}

Sphere::Sphere(Point const &pos, double radius)
:
    position(pos),
    r(radius)
{}
