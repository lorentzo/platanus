
#include "pinholecamera.h"

PinholeCamera::PinholeCamera(
    const double fov_angle,
    const Frame frame)
  : m_fov_angle(fov_angle)
  , m_frame(frame)
{
}

void PinholeCamera::spawn_ray(
    const double &x,
    const double &y,
    Ray &ray)
{

    // Raster to NDC space. Middle of pixel.
    double ndc_x = (x + 0.5) / m_frame.m_frame_width;
    double ndc_y =  (y + 0.5) / m_frame.m_frame_height;

    // NDC to frame space.
    double frame_aspect_ratio = m_frame.m_frame_width / m_frame.m_frame_height; // pixel ratio.
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
    ray.o = origin;
    ray.d = direction;

}