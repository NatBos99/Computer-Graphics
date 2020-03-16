#version 330 core

// Specify the input locations of attributes.
layout (location = 0) in vec3 vertCoordinates_in;
layout (location = 1) in vec3 vertNormals_in;
layout (location = 2) in vec2 gridCoords_in;

// Specify the uniforms of the vertex shader.
uniform mat4 modelViewTransform;
uniform mat4 projectionTransform;
uniform mat3 normalTransform;

// Specify the output of the vertex stage.
out vec3 vertNormal;

void main()
{
    vec3 vertCoords = vertCoordinates_in;
    vec2 gridCoords = gridCoords_in;
    float u = gridCoords.x;
    float v = gridCoords.y;
    vertCoords.z = vertCoords.z + 0.2*sin(30.0F*u);
    gl_Position  = projectionTransform * modelViewTransform * vec4(vertCoords, 1.0F);

    vertNormal = normalize(normalTransform * vec3(-6.0*cos(30.0F * u), 0.0F, 1.0F));
}
