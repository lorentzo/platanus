
#include "./../../../foundation/math/vector.h"
#include "./../../../foundation/math/ray.h"

#include "./../frame/frame.h"

//
// Inspired by:
// https://users.cg.tuwien.ac.at/zsolnai/gfx/smallpaint/
// https://www.scratchapixel.com/lessons/3d-basic-rendering/computing-pixel-coordinates-of-3d-point/mathematics-computing-2d-coordinates-of-3d-points
//

//
// Virtual camera (eye) is placed in world origin, facing -z.
// Frame is parallel to placed to (0, 0, -1).
//

class PinholeCamera
{
  public:
    
    PinholeCamera(
        const double fov_angle,
        const Frame frame);

    void spawn_ray(
        const double &x,
        const double &y,
        Ray &ray);

    double m_fov_angle; // scale
    Frame m_frame;

};

