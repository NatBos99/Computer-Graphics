#version 330 core

// Define constants.
#define M_PI 3.141593
in vec3 normal;

// Specify the output of the fragment shader.
out vec4 fColor;

void main()
{
    fColor = vec4(normal.x, normal.y, normal.z, 1.0F);
}
