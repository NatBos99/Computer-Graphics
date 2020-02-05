#version 330 core

in vec3 interpolatedColor;

out vec4 colorstuff;

void main()
{
    colorstuff = vec4(interpolatedColor, 1);
}
