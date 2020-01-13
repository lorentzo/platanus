
#include "./../../../../src/platanus/foundation/math/vector.h"

#include "./../../../../src/platanus/renderer/modeling/scene/scene.h"
#include "./../../../../src/platanus/renderer/modeling/object/sphereobject.h"
#include "./../../../../src/platanus/renderer/modeling/camera/pinholecamera.h"
#include "./../../../../src/platanus/renderer/modeling/frame/frame.h"
#include "./../../../../src/platanus/renderer/modeling/material/material.h"
#include "./../../../../src/platanus/renderer/modeling/material/bsdf/phongdiffuse.h"

#include "./../../../../src/platanus/renderer/kernel/rendering/renderframe.h"

int main(int argc, char** argv)
{

    const int frame_width = 640;
    const int frame_height = 480; 
    const int camera_fov_angle = 0.9;

    // Image frame.
    Frame frame = Frame(frame_width, frame_height);

    // Camera.
    PinholeCamera camera = PinholeCamera(camera_fov_angle, frame);

    // Scene.
    Scene scene;

    PhongDiffuse phong_diffuse1(Vector3d(0.2, 0.3, 0.5));
    Material material1(phong_diffuse1);

    Vector3d center1 = (5, 5, 5);
    double radius1 = (0.5); 
    scene.add(new Sphere(center1, radius1, material1));

    Vector3d center2 = (7, 2, 4);
    double radius2 = (0.2); 
    scene.add(new Sphere(center2, radius2, material1));

    Vector3d center3 = (2, 7, 6);
    double radius3 = (0.2); 
    scene.add(new Sphere(center3, radius3, material1));


    render_frame(frame, camera, scene, 1);


}






