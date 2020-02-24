#include "triangle.h"

Hit Triangle::intersect(Ray const &ray)
{
	const double EPSILON = 0.0000001;

	double a,f,u,v;
	Vector edge1, edge2, h, s, q;

	edge1 = v1 - v0;
    edge2 = v2 - v0;

	h = (ray.D).cross(edge2);
	a = edge1.dot(h);

	if (a > -EPSILON && a < EPSILON)
        return Hit::NO_HIT();

	f = 1.0/a;
    s = ray.O - v0;
    u = f * s.dot(h);

	if (u < 0.0 || u > 1.0)
        return Hit::NO_HIT();

	q = s.cross(edge1);
    v = f * (ray.D).dot(q);
    if (v < 0.0 || u + v > 1.0)
        return Hit::NO_HIT();

	float t = f * edge2.dot(q);
    if (t > EPSILON) // ray intersection
    {
        return Hit(t, N);
    }
    else // This means that there is a line intersection but not a ray intersection.
        return Hit::NO_HIT();

}

Triangle::Triangle(Point const &v0,
                   Point const &v1,
                   Point const &v2)
:
    v0(v0),
    v1(v1),
    v2(v2)
{
    N = (v1-v0).cross(v2-v0);
	N.normalize();
}
