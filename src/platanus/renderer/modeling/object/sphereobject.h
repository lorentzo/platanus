
#pragma once

#include "object.h"

#include "foundation/math/vector.h"
#include "foundation/math/ray.h"

#include "renderer/modeling/material/material.h"

#include <string>

namespace renderer {

class Sphere : public Object
{
  public: 

    Sphere();

    Sphere(
        foundation::Vector3d center,
        double radius,
        Material material);

    bool intersect(const foundation::Ray &ray, double &t) const override;

    void get_surface_data(const foundation::Vector3d &p_hit, foundation::Vector3d &normal) const override;

    foundation::Vector3d m_center;
    double m_radius;
    double m_radius2;

};

} // namespace renderer