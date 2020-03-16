#version 330 core

// Define constants.
#define M_PI 3.141593
#define NWAVES 4

// Specify the input locations of attributes.
layout (location = 0) in vec3 vertCoordinates_in;
layout (location = 1) in vec3 vertNormals_in;
layout (location = 2) in vec2 gridCoords_in;

// Specify the uniforms of the vertex shader.
uniform mat4 modelViewTransform;
uniform mat4 projectionTransform;
uniform vec3 lightPosition;
uniform mat3 normalTransform;

uniform float amplitude[NWAVES];
uniform float frequency[NWAVES];
uniform float phase[NWAVES];

uniform float time;

// Specify the output of the vertex stage.
out vec3 vertNormal;
out vec2 gridCoords;
out vec3 vertPosition;
out vec3 relativeLightPosition;
out vec3 materialColorFromHeight;

float waveHeight(int waveIdx, float u)
{
    return amplitude[waveIdx] * sin(2*M_PI*frequency[waveIdx]*u + phase[waveIdx] + time);
}

float waveDU(int waveIdx, float u)
{
    return amplitude[waveIdx] * 2 * M_PI * frequency[waveIdx] * cos(2*M_PI*frequency[waveIdx]*u + phase[waveIdx] + time);
}

void main()
{
    vec3 vertCoords = vertCoordinates_in;
    gridCoords = gridCoords_in;
    relativeLightPosition = lightPosition;
    float u = gridCoords.x;
    float v = gridCoords.y;

    float tempNormal = 0.0;
    float tempHeight = 0.0;
    for(int i = 0; i < NWAVES; i++) {
        tempHeight += waveHeight(i, u);
        tempNormal += waveDU(i, u);
    }

    vertCoords.z += tempHeight;
    vertPosition = vec3(modelViewTransform * vec4(vertCoords, 1.0F));

    vertNormal = normalize(normalTransform * vec3(-tempNormal, 0.0F, 1.0F));

    gl_Position  = projectionTransform * modelViewTransform * vec4(vertCoords, 1.0F);

    float tempColor = smoothstep(-0.2, 0.2, tempHeight);
    vec3 color1 = vec3(0.137, 0.537, 0.855); // RGB Hex: #2389da
    vec3 color2 = vec3(0.804, 0.89, 0.96); // RGB Hex: #cde3f5
    materialColorFromHeight = mix(color1, color2, tempColor);
}
