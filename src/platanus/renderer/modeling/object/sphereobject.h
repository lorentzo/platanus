
#include "./../../../foundation/math/vector.h"
#include "./../../../foundation/math/ray.h"

#include "object.h"
#include <string>

class Sphere : public Object
{
  public: 

    Sphere(
        Vector3d center,
        double radius);

    bool intersect(const Ray &ray, double &t);

    void get_surface_data(const Vector3d &p_hit, Vector3d &normal);

  private:
    
    Vector3d m_center;
    double m_radius;
    double m_radius2;

};
