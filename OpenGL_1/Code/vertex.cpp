#include "vertex.h"

Vertex makeVertex(float x, float y, float z, float r, float g, float b) {
    Vertex v;
    v.x = x;
    v.y = y;
    v.z = z;
    v.r = r;
    v.g = g;
    v.b = b;
    return v;
}
