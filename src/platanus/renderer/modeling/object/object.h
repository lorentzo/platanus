
#include "./../../../foundation/math/ray.h"
#include "./../../../foundation/math/vector.h"

//
// Object base class.
//

class Object
{
  public:

    // Default constructor.
    Object() : color(1.0, 1.0, 1.0) {}

    // Destructor.
    virtual ~Object() {}

    // Given ray, perform intersection of object. 
    // Return ray parameter t for intersection.
    virtual bool intersect(const Ray &, double &) const = 0;

    // Returns normal in intersection point.
    virtual void get_surface_data(const Vector3d &, Vector3d &) const = 0;

    Vector3d color;

};