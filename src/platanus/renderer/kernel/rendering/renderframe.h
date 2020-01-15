
#pragma once

#include <stdlib.h>

#include "foundation/math/vector.h"
#include "foundation/math/ray.h"

#include "renderer/modeling/camera/pinholecamera.h"
#include "renderer/modeling/frame/frame.h"
#include "renderer/modeling/scene/scene.h"

#include "renderer/kernel/intersection/intersector.h"
#include "renderer/kernel/shading/shadingengine.h"

namespace renderer {

void render_frame(
    renderer::Frame &frame,
    renderer::PinholeCamera &camera,
    renderer::Scene &scene,
    const int &samples_per_pixel)
{
    // Shading engine.
    ShadingEngine shading_engine = renderer::ShadingEngine(scene);

    for (int s = 0; s < samples_per_pixel; s++) {

            foundation::Vector3d *pix = frame.m_frame_buffer; 

            for (size_t j = 0; j < frame.m_frame_height; j++) {
                for (size_t i = 0; i < frame.m_frame_width; i++) {

                    foundation::Vector3d color;
                    foundation::Ray camera_ray;

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

} // namespace renderer