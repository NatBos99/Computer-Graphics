#version 330 core

// Define constants.
#define M_PI 3.141593

// The input from the vertex shader.
in vec3 vertNormal;
in vec3 vertPosition;
in vec3 relativeLightPosition;
in vec2 gridCoords;
in vec3 normal;

// Illumination model constants.
uniform vec4 material;
uniform vec3 lightColor;

// Specify the output of the fragment shader.
out vec4 fColor;

void main()
{
    fColor = vec4(normal.x, normal.y, normal.z, 1.0F);
}
