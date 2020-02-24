#include "quad.h"

#include <limits>

using namespace std;

Hit Quad::intersect(Ray const &ray)
{
    // placeholder
	Hit min_hit(numeric_limits<double>::infinity(), Vector());
	Hit t1_intersect = t1->intersect(ray);
	Hit t2_intersect = t2->intersect(ray);
	if (t1_intersect.t < min_hit.t) {
		return t1_intersect;
	}
	if (t2_intersect.t < min_hit.t) {
		return t2_intersect;
	}
    return Hit::NO_HIT();
}

Quad::Quad(Point const &v0,
           Point const &v1,
           Point const &v2,
           Point const &v3)
{
    // Store and/or process the points defining the quad here.
	t1 = new Triangle(v0, v1, v2);
	t2 = new Triangle(v0, v2, v3);
}
