
#pragma once

#include "./../ray.h"
#include "./../vector.h"

//
// Inspired by
// https://www.scratchapixel.com/code.php?id=10&origin=/lessons/3d-basic-rendering/minimal-ray-tracer-rendering-simple-shapes
//

namespace foundation {

// Ray-sphere intersection test.
// \param ray: ray for intersection.
// \param center: center of the sphere.
// \param radius2: squared radius of the sphere.
// \param[out] t: distance from the ray origin to the intersection point 
bool intersect_sphere(
    const Ray &ray, 
    const Vector3d &center,
    const double &radius2,
    double &t)
{
    float t0, t1; // soulutions if ray intersects the sphere

    // Geometric solution.
    Vector3d L = center - ray.o;
    float tca = L.dot(ray.d);

    if (tca < 0)
    {
        return false;
    }

    float d2 = L.dot(L) - tca * tca;

    if (d2 > radius2)
    {
        return false;
    }

    float thc = sqrt(radius2 - d2);

    t0 = tca - thc;
    t1 = tca + thc;

    if (t0 > t1)
    {
        double t_tmp = t0;
        t0 = t1;
        t1 = t_tmp;
    }

    if(t0 < 0)
    {
        t0 = t1;
        if (t0 < 0)
        {
            return false;
        }
    }

    t = t0;
    return true;

}

//
// Inspired by:
// https://users.cg.tuwien.ac.at/zsolnai/gfx/smallpaint/
//
/*
double intersect_sphere(
    const Ray& ray,
    const Vector3d c,
    const double r)
{
    double eps = 1e-6;

    double b = ((ray.o - c) * 2).dot(ray.d);
    double c_ = (ray.o - c).dot((ray.o - c)) - (r*r);
    double disc = b*b - 4 * c_;

    if (disc < 0)
    {
        return 0;
    }
    else 
    {
        disc = sqrt(disc);
    }

    double sol1 = -b + disc;
    double sol2 = -b - disc;
    
    return (sol2 > eps) ? sol2 / 2 : ((sol1 > eps) ? sol1 / 2 : 0);
}
*/

} // namespace foundation
