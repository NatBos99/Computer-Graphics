#include "sphere.h"

#include <cmath>

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

    Vector OC = position - ray.O;
    if (OC.dot(ray.D) <= 0) {
				return Hit::NO_HIT();
    }
    Vector perp = OC.dot(ray.D) * ray.D;
    Vector Cperp = perp - OC;
    if (Cperp.length() > r) {
        return Hit::NO_HIT();
    }
    double cplen = Cperp.length();
    double t = perp.length() - tan(acos(cplen/r))*cplen;

    /****************************************************
    * RT1.2: NORMAL CALCULATION
    *
    * Given: t, C, r
    * Sought: N
    *
    * Insert calculation of the sphere's normal at the intersection point.
    ****************************************************/

    Vector N = t*ray.D - OC;
    N.normalize();

    return Hit(t, N);
}

Sphere::Sphere(Point const &pos, double radius)
:
    position(pos),
    r(radius)
{}
