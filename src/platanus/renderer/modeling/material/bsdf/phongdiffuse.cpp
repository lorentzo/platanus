
#include "phongdiffuse.h"

#include <algorithm>

using namespace foundation;

namespace renderer {

PhongDiffuse::PhongDiffuse() : m_object_albedo(0.0, 0.0, 0.0) {}

PhongDiffuse::PhongDiffuse(Vector3d object_albedo) : m_object_albedo(object_albedo) {}

Vector3d PhongDiffuse::evaluate(
    const Vector3d &hit_normal, 
    const Vector3d &light_direction, 
    const Vector3d &light_color,
    const double &light_intensity) const
{
    return light_color * std::max(0.0, hit_normal.dot(light_direction)) * light_intensity;
}

} // namespace renderer