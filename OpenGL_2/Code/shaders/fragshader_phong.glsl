#version 330 core

// Define constants
#define M_PI 3.141593

// Specify the inputs to the fragment shader
// These must have the same type and name!
in vec3 vertCoordinates;
in vec3 vertNormal;
in vec3 vertColor;
in vec2 texCoordinates;

// Specify the Uniforms of the fragment shaders
// uniform vec3 lightPosition; // for example
uniform mat4 modelViewTransform;
uniform mat4 projectionTransform;
uniform mat3 normalTransform;
uniform vec3 light;
uniform vec3 lightColor;
uniform vec3 lightIntensity;
uniform vec3 material;
uniform sampler2D tex;

// Specify the output of the fragment shader
// Usually a vec4 describing a color (Red, Green, Blue, Alpha/Transparency)
out vec4 fColor;

void main()
{
    vec4 textureColor = texture2D(tex, texCoordinates);
    vec3 N, L, R, V;
    N = normalTransform * vertNormal;
    vec4 temp = modelViewTransform*vec4(vertCoordinates, 1.0);
    L = normalize(light - temp.xyz);
    R = -reflect(L, N);
    V = normalize(-temp.xyz);

    int p = 5;

    fColor = textureColor *
             vec4((material.x * lightIntensity.x) +
                  (material.y * lightIntensity.y * max(0, dot(N, L)) * lightColor) +
                  (material.z * lightIntensity.z * pow(max(0, dot(R, V)), p) * lightColor), 1.0);
}
