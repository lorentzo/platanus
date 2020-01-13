
#include <stdlib.h>

#include "./../../../foundation/math/vector.h"
#include "./../../../foundation/math/ray.h"

#include "./../../modeling/camera/pinholecamera.h"
#include "./../../modeling/frame/frame.h"
#include "./../../modeling/scene/scene.h"

#include "./../intersection/intersector.h"
#include "./../shading/shadingengine.h"

void render_frame(
    const int &frame_width, 
    const int &frame_height, 
    const int &camera_fov_angle,
    const int &samples_per_pixel,
    const Scene &scene)
{

    // Image frame.
    Frame frame = Frame(frame_width, frame_height);

    // Camera.
    PinholeCamera camera = PinholeCamera(camera_fov_angle, frame);

    // Shading engine.
    ShadingEngine shading_engine = ShadingEngine(scene);

    for (int s = 0; s < samples_per_pixel; s++) {

            Vector3d *pix = frame.m_frame_buffer; 

            for (size_t j = 0; j < frame_height; j++) {
                for (size_t i = 0; i < frame_width; i++) {

                        Vector3d color;
                        Ray camera_ray;

                        camera.spawn_ray(i,j, camera_ray); 
                        //camera_ray.d = camera_ray.d.x + RND / 700; // random pixel sample for denoise
                        //camera_ray.d = camera_ray.d.y + RND / 700;
                        
                        color = shading_engine.shade_simple(camera_ray);

                        *(pix++) = *(pix++) + color;

                }
            }
            frame.save();
    }
}