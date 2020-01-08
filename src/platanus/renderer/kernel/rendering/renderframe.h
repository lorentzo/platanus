
#include <stdlib.h>
#include "./../../../foundation/math/vector.h"
#include "./../../../foundation/math/ray.h"
#include "./../../modeling/camera/camera.h"

void render_frame(int frame_width, int frame_height)
{
    Pinhole_Camera camera = Pinhole_Camera(0.9, frame_width, frame_height);

    int samples_per_pixel = 100;

    //for (int s = 0; s < samples_per_pixel; s++) {

            for (size_t i = 0; i < frame_width; i++) {
                for (size_t j = 0; j < frame_height; j++) {


                        Vector3d color;
                        Ray ray;

                        Ray camera_ray = camera.spawn_ray(i,j); 
                        //camera_ray.d = camera_ray.d.x + RND / 700; // random pixel sample
                        //camera_ray.d = camera_ray.d.y + RND / 700;

                        ray.d = (camera_ray.d - camera_ray.o).norm(); 

                        trace(ray, scene, 0, color, params, hal, hal2);

                        color = shade();

                        pix[col][row] = pix[col][row] + color;


                }
            }
            imageOutput(pix, s);
        //}
}