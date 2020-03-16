#version 330 core

// Define constants.
#define M_PI 3.141593

// The input from the vertex shader.
in vec3 vertNormal;
in vec2 gridCoords;
in vec3 vertPosition;
in vec3 relativeLightPosition;
in vec3 materialColorFromHeight;

// Illumination model constants.
uniform vec4 material;
uniform vec3 materialColor;
uniform vec3 lightColor;

// Specify the output of the fragment shader.
out vec4 fColor;

void main()
{
    vec3 color = material.x * materialColorFromHeight;

    // Calculate light direction vectors in the Phong illumination model.
    vec3 lightDirection = normalize(relativeLightPosition - vertPosition);
    vec3 normal         = normalize(vertNormal);

    // Diffuse color.
    float diffuseIntensity = max(dot(normal, lightDirection), 0.0F);
    color += material.y * diffuseIntensity * materialColorFromHeight;

    // Specular color.
    vec3 viewDirection      = normalize(-vertPosition); // The camera is always at (0, 0, 0).
    vec3 reflectDirection   = reflect(-lightDirection, normal);
    float specularIntensity = max(dot(reflectDirection, viewDirection), 0.0F);
    color += lightColor * material.z * materialColorFromHeight * pow(specularIntensity, material.w);

    fColor = vec4(color, 1.0F);
}
