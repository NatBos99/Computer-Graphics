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
    vec4 vertCoordinates = modelViewTransform*vec4(vertCoordinates_in, 1.0);

    // gl_Position is the output (a vec4) of the vertex shader
    gl_Position = projectionTransform * vertCoordinates;

    vec3 N, L, R, V;
    N = normalize(normalTransform * normCoordinates_in);

    L = normalize(light - vertCoordinates.xyz);
    R = -reflect(L, N);
    V = normalize(-vertCoordinates.xyz);

    int p = 2;

    vertColor = material.x * lightIntensity.x * lightColor
                + material.y * lightIntensity.y * max(0, dot(N, L)) * lightColor
                + material.z * lightIntensity.z * pow(max(0, dot(R, V)), p) * lightColor;

    texCoordinates = texCoordinates_in;
}
