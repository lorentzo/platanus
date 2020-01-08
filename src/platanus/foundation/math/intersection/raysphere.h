
#include "./../ray.h"
#include "./../vector.h"

//
// Inspired by:
// https://users.cg.tuwien.ac.at/zsolnai/gfx/smallpaint/
//

double intersect_sphere(
    const Ray& ray,
    const Vector3d c,
    const double r)
{
    double eps = 1e-6;

    double b = ((ray.o - c) * 2).dot(ray.d);
    double c_ = (ray.o - c).dot((ray.o - c)) - (r*r);
    double disc = b*b - 4 * c_;

    if (disc < 0)
    {
        return 0;
    }
    else 
    {
        disc = sqrt(disc);
    }

    double sol1 = -b + disc;
    double sol2 = -b - disc;
    
    return (sol2 > eps) ? sol2 / 2 : ((sol1 > eps) ? sol1 / 2 : 0);
}
