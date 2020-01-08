
#include "./../../../foundation/math/vector.h"
#include "./../../../foundation/math/ray.h"
#include "./../../../foundation/math/intersection/raysphere.h"
#include <string>

class Sphere
{
    Vector3d m_center;
    double m_radius;
    std::string m_material;

    Sphere(
        Vector3d center,
        double radius,
        std::string material)
    {
        m_center = center;
        m_radius = radius;
        m_material = material;
    }

    double intersect(Ray ray)
    {
	return intersect_sphere(ray, m_center, m_radius);
    }

}
