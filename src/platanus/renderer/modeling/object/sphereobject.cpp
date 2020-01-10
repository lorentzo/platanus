
#include "sphereobject.h"

#include "./../../../foundation/math/intersection/raysphere.h"

Sphere::Sphere(
    Vector3d center,
    double radius)
  : m_center(center)
  , m_radius(radius)
  , m_radius2(radius * radius)
{
}

bool Sphere::intersect(const Ray &ray, double &t)
{
    intersect_sphere(ray, m_center, m_radius2, t);
}
  
void Sphere::get_surface_data(const Vector3d &p_hit, Vector3d &normal) 
{
    normal = (p_hit - m_center).norm();
}


