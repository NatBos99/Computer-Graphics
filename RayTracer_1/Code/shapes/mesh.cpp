#include "mesh.h"

#include "../objloader.h"
#include "../vertex.h"
#include "triangle.h"

#include <cmath>
#include <iostream>
#include <limits>

using namespace std;

Hit Mesh::intersect(Ray const &ray)
{
    // Replace the return of a NO_HIT by determining the intersection based
    // on the ray and this class's data members.

	Hit min_hit(numeric_limits<double>::infinity(), Vector());
	Hit best_hit(numeric_limits<double>::infinity(), Vector());
	bool hits = false;

	for (size_t i = 0; i != d_tris.size(); ++i) {
		ObjectPtr tri = d_tris[i];
		
		Hit intersect = tri->intersect(ray);
		if (intersect.t < min_hit.t) {
			if (intersect.t < best_hit.t) {
				best_hit.t = intersect.t;
				best_hit.N = intersect.N;
			}
			hits = true;
		}
	}

	if (hits) {
		return best_hit;
	}

    return Hit::NO_HIT();
}

Vector Mesh::rotate(Vector v, Vector r) {
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

Mesh::Mesh(string const &filename, Point const &position, Vector const &rotation, Vector const &scale)
{
    OBJLoader model(filename);
    d_tris.reserve(model.numTriangles());
    vector<Vertex> vertices = model.vertex_data();
    for (size_t tri = 0; tri != model.numTriangles(); ++tri)
    {
        Vertex one = vertices[tri * 3];
        Point v0(one.x, one.y, one.z);

        Vertex two = vertices[tri * 3 + 1];
        Point v1(two.x, two.y, two.z);

        Vertex three = vertices[tri * 3 + 2];
        Point v2(three.x, three.y, three.z);

        // Apply non-uniform scaling, rotation and translation to the three points
        // of the triangle (v0, v1, and v2) here.

        // Non-uniform scaling
        v0 = v0 * scale;
        v1 = v1 * scale;
        v2 = v2 * scale;

        // Rotation
		v0 = rotate(v0, rotation);
		v1 = rotate(v1, rotation);
		v2 = rotate(v2, rotation);

        // Translation
        v0 = v0 + position;
		v1 = v1 + position;
		v2 = v2 + position;

        d_tris.push_back(ObjectPtr(new Triangle(v0, v1, v2)));
    }

    cout << "Loaded model: " << filename << " with " <<
        model.numTriangles() << " triangles.\n";
}
