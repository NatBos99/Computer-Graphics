#include "scene.h"

#include "hit.h"
#include "image.h"
#include "material.h"
#include "ray.h"

#include <algorithm>
#include <cmath>
#include <limits>
#include <iostream>

using namespace std;

pair<ObjectPtr, Hit> Scene::castRay(Ray const &ray) const
{
    // Find hit object and distance
    Hit min_hit(numeric_limits<double>::infinity(), Vector());
    ObjectPtr obj = nullptr;
    for (unsigned idx = 0; idx != objects.size(); ++idx)
    {
        Hit hit(objects[idx]->intersect(ray));
        if (hit.t < min_hit.t)
        {
            min_hit = hit;
            obj = objects[idx];
        }
    }

    return pair<ObjectPtr, Hit>(obj, min_hit);
}

Color Scene::trace(Ray const &ray, unsigned depth, bool inside)
{
    pair<ObjectPtr, Hit> mainhit = castRay(ray);
    ObjectPtr obj = mainhit.first;
    Hit min_hit = mainhit.second;

    // No hit? Return background color.
    if (!obj)
        return Color(0.0, 0.0, 0.0);

    Material const &material = obj->material;
    Point hit = ray.at(min_hit.t);
    Vector V = -ray.D;

    // Pre-condition: For closed objects, N points outwards.
    Vector N = min_hit.N;

    // The shading normal always points in the direction of the view,
    // as required by the Phong illumination model.
    Vector shadingN;
    if (N.dot(V) >= 0.0)
        shadingN = N;
    else
        shadingN = -N;
	
	Color matColor;

	if (material.hasTexture) {
		Vector temp = obj->toUV(hit);
		float u = temp.x;
		float v = temp.y;
		matColor = material.texture.colorAt(u, 1.0 - v);
	} else {
	    matColor = material.color;
	}
    // Add ambient once, regardless of the number of lights.
    Color color = material.ka * matColor;

    // Add diffuse and specular components.
    for (auto const &light : lights) {
        Vector L = (light->position - hit).normalized();

        if (renderShadows) {

            Ray shadowRay(hit + epsilon * shadingN, (light->position - (hit + epsilon * shadingN)).normalized());
            pair<ObjectPtr, Hit> shadowHit = castRay(shadowRay);
            if (shadowHit.second.t < (light->position - (hit + epsilon * shadingN)).length()) {
                continue;
            }
        }
        
        // Add diffuse.
        double diffuse = std::max(shadingN.dot(L), 0.0);
        color += diffuse * material.kd * light->color * matColor;

        // Add specular.
        Vector reflectDir = reflect(-L, shadingN);
        double specAngle = std::max(reflectDir.dot(V), 0.0);
        double specular = std::pow(specAngle, material.n);

        color += specular * material.ks * light->color;
    }

    if (depth > 0 && material.isTransparent)
    {
        // The object is transparent, and thus refracts and reflects light.
        // Use Schlick's approximation to determine the ratio between the two.
        Ray reflectRay(hit + epsilon * shadingN, reflect(ray.D, shadingN));
		
		double ni, nt;

		if (not inside) {
			ni = 1.0;
        	nt = material.nt;
		} else {
			ni = material.nt;
        	nt = 1.0;
		}

        double k = 1.0 - ni*ni*(1.0 - pow((ray.D).dot(shadingN), 2)) / (nt*nt);

        Vector T(0, 0, 0);
        if (k >= 0.0) {
            T = ni * (ray.D - (ray.D).dot(shadingN) * shadingN) / nt;
            T -= shadingN * sqrt(k);
        }

        double kr0 = pow((ni-nt)/(ni+nt), 2);
        double kr = kr0 + (1.0 - kr0) * pow((1.0 - ((-ray.D).dot(shadingN))), 5);
        double kt = 1.0 - kr;

        Ray refractRay(hit - epsilon * shadingN, T.normalized());

    	color += kr * trace(reflectRay, depth-1, inside) + kt * trace(refractRay, depth-1, not inside);
    }
    else if (depth > 0 && material.ks > 0.0)
    {
        Ray reflectRay(hit + epsilon * shadingN, reflect(ray.D, shadingN));
        color += material.ks * trace(reflectRay, depth-1, inside);
    }

    return color;
}

Color Scene::supersample(double x, double y, bool inside, double shift, unsigned ssr) {
	Color col;
    if (ssr != 1) {
        col = supersample(x - shift, y + shift, inside, shift/2.0, ssr-1);
        col += supersample(x + shift, y + shift, inside, shift/2.0, ssr-1);
        col += supersample(x + shift, y - shift, inside, shift/2.0, ssr-1);
        col += supersample(x - shift, y - shift, inside, shift/2.0, ssr-1);
        col /= 4; 
    } else { // ssr == 1
        Point pixel(x, y, 0);
		Ray ray(eye, (pixel - eye).normalized());
        col = trace(ray, recursionDepth, inside);
    }
    return col;
} 

void Scene::render(Image &img)
{
    unsigned w = img.width();
    unsigned h = img.height();

    for (unsigned y = 0; y < h; ++y)
        for (unsigned x = 0; x < w; ++x)
        {
            Color col = supersample(x + 0.5, h - 1 - y + 0.5, false, 0.25, supersamplingFactor);
            col.clamp();
            img(x, y) = col;
        }
}

// --- Misc functions ----------------------------------------------------------

// Defaults
Scene::Scene()
:
    objects(),
    lights(),
    eye(),
    renderShadows(false),
    recursionDepth(0),
    supersamplingFactor(1)
{}

void Scene::addObject(ObjectPtr obj)
{
    objects.push_back(obj);
}

void Scene::addLight(Light const &light)
{
    lights.push_back(LightPtr(new Light(light)));
}

void Scene::setEye(Triple const &position)
{
    eye = position;
}

unsigned Scene::getNumObject()
{
    return objects.size();
}

unsigned Scene::getNumLights()
{
    return lights.size();
}

void Scene::setRenderShadows(bool shadows)
{
    renderShadows = shadows;
}

void Scene::setRecursionDepth(unsigned depth)
{
    recursionDepth = depth;
}

void Scene::setSuperSample(unsigned factor)
{
    supersamplingFactor = factor;
}
