
#include "./../../../foundation/math/ray.h"
#include "./../../../foundation/math/vector.h"
#include "./../material/material.h"

//
// Object base class.
//

class Object
{
  public:

    // Default constructor.
    Object();

    Object(Material material) : m_material(material) {}

    // Destructor.
    virtual ~Object() {}

    // Given ray, perform intersection of object. 
    // Return ray parameter t for intersection.
    virtual bool intersect(const Ray &, double &) const = 0;

    // Returns normal in intersection point.
    virtual void get_surface_data(const Vector3d &, Vector3d &) const = 0;

    Material m_material;

};