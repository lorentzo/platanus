
#pragma once

#include "foundation/math/vector.h"

namespace renderer {

// marker class for now.
class BSDF
{

  public:

    BSDF() {}
    virtual ~BSDF();

    virtual foundation::Vector3d evaluate(
        const foundation::Vector3d &normal, 
        const foundation::Vector3d &light_direction, 
        const foundation::Vector3d &light_color,
        const double &light_intensity
    ) const;
};

} // namespace renderer