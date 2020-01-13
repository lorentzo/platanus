
#include "shadingengine.h"

ShadingEngine::ShadingEngine(Scene scene) : m_scene(scene) 
{
    m_intersector = Intersector(scene);
}

void ShadingEngine::ons(const Vector3d& v1, Vector3d& v2, Vector3d& v3)
{
    if (std::abs(v1.x) > std::abs(v1.y)) {
        // project to the y = 0 plane and construct a normalized orthogonal vector in this plane
        float invLen = 1.f / sqrtf(v1.x * v1.x + v1.z * v1.z);
        v2 = Vector3d(-v1.z * invLen, 0.0f, v1.x * invLen);
    } else {
        // project to the x = 0 plane and construct a normalized orthogonal vector in this plane
        float invLen = 1.0f / sqrtf(v1.y * v1.y + v1.z * v1.z);
        v2 = Vector3d(0.0f, v1.z * invLen, -v1.y * invLen);
    }
    v3 = v1 % v2;
}

Vector3d ShadingEngine::hemisphere(double u1, double u2)
{
    const double r = sqrt(1.0 - u1*u1);
    const double phi = 2 * PI * u2;
    return Vector3d(cos(phi)*r, sin(phi)*r, u1);
}

Vector3d ShadingEngine::shade_simple(const Ray &ray)
{

    const Object *hit_object = nullptr;
    double t;
    Vector3d hit_color;

    if(m_intersector.trace(ray, t, hit_object))
    {
        Vector3d hit_point = ray.o + ray.d * t;
        Vector3d hit_normal;
        hit_object->get_surface_data(hit_point, hit_normal);
        hit_color = hit_object->color * std::max(0.0, hit_normal.dot(-ray.d));
    }

    return hit_color;
}