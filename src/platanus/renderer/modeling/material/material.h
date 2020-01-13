
#include "./bsdf/bsdf.h"

class Material
{
  public:
    Material();
    Material(BSDF bsdf);

    BSDF m_bsdf;

};