
#include "./../../../../foundation/math/vector.h"

#include "./bsdf.h"

class PhongDiffuse : public BSDF
{

  public:

    PhongDiffuse();
    PhongDiffuse(Vector3d object_albedo);

    Vector3d evaluate(
        const Vector3d &hit_normal, 
        const Vector3d &light_direction, 
        const Vector3d &light_color,
        const double &light_intensity) const override;

    Vector3d m_object_albedo;

};