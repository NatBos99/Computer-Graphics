#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the input locations of attributes
layout (location = 0) in vec3 vertCoordinates_in;
layout (location = 1) in vec3 vertColor_in;
layout (location = 2) in vec3 normCoordinates_in;
layout (location = 3) in vec2 texCoordinates_in;

// Specify the Uniforms of the vertex shader
uniform mat4 modelViewTransform;
uniform mat4 projectionTransform;
uniform mat3 normalTransform;
uniform vec3 light;
uniform vec3 lightColor;
uniform vec3 lightIntensity;
uniform vec3 material;

// Specify the output of the vertex stage
out vec3 vertColor;
out vec2 texCoordinates;

void main()
{
    // gl_Position is the output (a vec4) of the vertex shader
    gl_Position = projectionTransform * modelViewTransform * vec4(vertCoordinates_in, 1.0);

    vec3 N, L, R, V;
    N = normalTransform * normCoordinates_in;
    vec4 temp = modelViewTransform*vec4(vertCoordinates_in, 1.0);
    L = normalize(light - temp.xyz);
    R = -reflect(L, N);
    V = normalize(-temp.xyz);

    int p = 5;

    vertColor = (material.x * lightIntensity.x) +
                (material.y * lightIntensity.y * max(0, dot(N, L)) * lightColor) +
                (material.z * lightIntensity.z * pow(max(0, dot(R, V)), p) * lightColor);
    texCoordinates = texCoordinates_in;
}
