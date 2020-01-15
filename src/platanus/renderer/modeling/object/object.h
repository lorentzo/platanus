
#pragma once

#include "foundation/math/ray.h"
#include "foundation/math/vector.h"

#include "renderer/modeling/material/material.h"

//
// Object base class.
//

namespace renderer {

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
    virtual bool intersect(const foundation::Ray &, double &) const = 0;

    // Returns normal in intersection point.
    virtual void get_surface_data(const foundation::Vector3d &, foundation::Vector3d &) const = 0;

    renderer::Material m_material;

};

} // namepsace renderer