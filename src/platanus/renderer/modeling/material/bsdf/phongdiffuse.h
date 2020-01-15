
#pragma once

#include "foundation/math/vector.h"

#include "bsdf.h"

namespace renderer {

class PhongDiffuse : public BSDF
{

  public:

    PhongDiffuse();
    PhongDiffuse(foundation::Vector3d object_albedo);

    foundation::Vector3d evaluate(
        const foundation::Vector3d &hit_normal, 
        const foundation::Vector3d &light_direction, 
        const foundation::Vector3d &light_color,
        const double &light_intensity) const override;

    foundation::Vector3d m_object_albedo;

};

} // namespace renderer