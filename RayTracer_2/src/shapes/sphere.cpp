#include "sphere.h"
#include "solvers.h"

#include <cmath>

using namespace std;

Hit Sphere::intersect(Ray const &ray)
{
    // Sphere formula: ||x - position||^2 = r^2
    // Line formula:   x = ray.O + t * ray.D

    Vector L = ray.O - position;
    double a = ray.D.dot(ray.D);
    double b = 2.0 * ray.D.dot(L);
    double c = L.dot(L) - r * r;

    double t0;
    double t1;
    if (not Solvers::quadratic(a, b, c, t0, t1))
        return Hit::NO_HIT();

    // t0 is closest hit
    if (t0 < 0.0)  // check if it is not behind the camera
    {
        t0 = t1;    // try t1
        if (t0 < 0.0) // both behind the camera
            return Hit::NO_HIT();
    }

    // calculate normal
    Point hit = ray.at(t0);
    Vector N = (hit - position).normalized();

    // Note that the direction of the normal is not changed here,
    // but in scene.cpp - if necessary.

    return Hit(t0, N);
}

Vector Sphere::rotate(Vector v, Vector r) {
    Vector newVec = v;
	// Rotation around x axis
    newVec.x = v.x;
    newVec.y = v.y * cos(r.x) - v.z * sin(r.x);
    newVec.z = v.y * sin(r.x) + v.z * cos(r.x);
	// Rotation around y axis
	v = newVec;
	newVec.x = v.x * cos(r.y) + v.z * sin(r.y);
	newVec.y = v.y;
	newVec.z = - v.x * sin(r.y) + v.z * cos(r.y);
	// Rotation around z axis
	v = newVec;
	newVec.x = v.x * cos(r.z) - v.y * sin(r.z);
	newVec.y = v.x * sin(r.z) + v.y * cos(r.z);
	newVec.z = v.z;
	return newVec;
}

Vector Sphere::toUV(Point const &hit)
{
    // placeholders
	Point newHit = hit - position;
	
	newHit = rotate(newHit, (-(PI*angle)/180)*axis);

    double u = 0.5 + atan2(newHit.y, newHit.x)/(2*PI);
    double v = 1 - acos(newHit.z/r)/PI;

    // Use a Vector to return 2 doubles. The third value is never read.
    return Vector{u, v, 0.0};
}

Sphere::Sphere(Point const &pos, double radius, Vector const& axis, double angle)
:
    // Feel free to modify this constructor.
    position(pos),
    r(radius),
    axis(axis),
    angle(angle)
{}
