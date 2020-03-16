#version 330 core

// The input from the vertex shader.
in vec3 vertNormal;

// Specify the output of the fragment shader.
out vec4 fColor;

void main()
{
    fColor = vec4(vertNormal, 1.0F);
}
