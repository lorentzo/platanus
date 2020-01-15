
#include "material.h"

namespace renderer {

Material::Material() {}

Material::Material(BSDF bsdf) : m_bsdf(bsdf) {}

} // namespace renderer