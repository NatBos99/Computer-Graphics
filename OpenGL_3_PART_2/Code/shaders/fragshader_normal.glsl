#version 330 core

// Define constants.
#define M_PI 3.141593

// The input from the vertex shader.
in vec3 vertNormal;
in vec2 gridCoords;

// Specify the output of the fragment shader.
out vec4 fColor;

void main()
{
    //fColor = vec4(gridCoords.x, gridCoords.y, 0.0F, 1.0F);
    fColor = vec4(0.5*vertNormal + 0.5, 1.0F);
}
