#ifndef VERTEX_H
#define VERTEX_H

struct vertex{
    float x, y, z;
    float r, g, b;
};

vertex makeVertex(float x, float y, float z, float r, float g, float b) {
    vertex newVertex;
    newVertex.x = x;
    newVertex.y = y;
    newVertex.z = z;
    newVertex.r = r;
    newVertex.g = g;
    newVertex.b = b;
    return newVertex;
}

#endif // VERTEX_H

