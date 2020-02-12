#ifndef VERTEX_H
#define VERTEX_H

struct Vertex {
    float x;
    float y;
    float z;
    float r;
    float g;
    float b;
};

Vertex makeVertex(float x, float y, float z, float r, float g, float b);

#endif // VERTEX_H

