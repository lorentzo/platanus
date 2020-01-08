
#include "./../../../foundation/math/vector.h"
#include "./../../../foundation/math/ray.h"

//
// Inspired by:
// https://users.cg.tuwien.ac.at/zsolnai/gfx/smallpaint/
// https://www.scratchapixel.com/lessons/3d-basic-rendering/computing-pixel-coordinates-of-3d-point/mathematics-computing-2d-coordinates-of-3d-points
//

//
// Virtual camera (eye) is placed in world origin, facing -z.
// Frame is parallel to placed to (0, 0, -1).
//

struct Pinhole_Camera
{
    double m_fov_angle;
    int m_frame_width;
    int m_frame_height;

    Pinhole_Camera(
        const double fov_angle,
        const int frame_width,
        const int frame_height)
    {
        m_fov_angle = fov_angle;
        m_frame_width = frame_width;
        m_frame_height = frame_height;
    }

    Ray spawn_ray(
        const double x,
        const double y)
    {
        // Raster to NDC space. Middle of pixel.
        double ndc_x = (x + 0.5) / m_frame_width;
        double ndc_y =  (y + 0.5) / m_frame_height;

        // NDC to frame space.
        double frame_aspect_ratio = m_frame_width / m_frame_height; // pixel ratio.
        double frame_x = (2 * ndc_x - 1) * frame_aspect_ratio;
        double frame_y = 1 - 2 * ndc_y;

        // Frame space to camera space. 
        double camera_x = frame_x * tan(m_fov_angle);
        double camera_y = frame_y * tan(m_fov_angle);

        // Eye (virtual camera).
        Vector3d origin = Vector3d(0.0, 0.0, 0.0);

        // Point on frame in camera space.
        Vector3d direction = Vector3d(camera_x, camera_y, -1.0);

        // Ray.
        return Ray(origin, direction);

    }

};

