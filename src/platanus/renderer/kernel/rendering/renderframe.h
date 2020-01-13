
#include <stdlib.h>

#include "./../../../foundation/math/vector.h"
#include "./../../../foundation/math/ray.h"

#include "./../../modeling/camera/pinholecamera.h"
#include "./../../modeling/frame/frame.h"
#include "./../../modeling/scene/scene.h"

#include "./../intersection/intersector.h"
#include "./../shading/shadingengine.h"

void render_frame(
    Frame &frame,
    PinholeCamera &camera,
    const Scene &scene,
    const int &samples_per_pixel)
{
    // Shading engine.
    ShadingEngine shading_engine = ShadingEngine(scene);

    for (int s = 0; s < samples_per_pixel; s++) {

            Vector3d *pix = frame.m_frame_buffer; 

            for (size_t j = 0; j < frame.m_frame_height; j++) {
                for (size_t i = 0; i < frame.m_frame_width; i++) {

                    Vector3d color;
                    Ray camera_ray;

                    camera.spawn_ray(i,j, camera_ray); 
                    //camera_ray.d = camera_ray.d.x + RND / 700; // random pixel sample for denoise
                    //camera_ray.d = camera_ray.d.y + RND / 700;
                    
                    color = shading_engine.shade(camera_ray);

                    *(pix++) = *(pix++) + color;

                }
            }
            frame.save();
    }
}