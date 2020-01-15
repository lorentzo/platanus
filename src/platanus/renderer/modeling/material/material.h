
#pragma once

#include "renderer/modeling/material/bsdf/bsdf.h"

namespace renderer {

class Material
{
  public:
    Material();
    Material(BSDF bsdf);

    BSDF m_bsdf;

};

} // namespace renderer