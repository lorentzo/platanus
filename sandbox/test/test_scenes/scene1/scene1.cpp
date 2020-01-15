
#include "foundation/math/vector.h"

#include "renderer/modeling/scene/scene.h"
#include "renderer/modeling/object/sphereobject.h"
#include "renderer/modeling/camera/pinholecamera.h"
#include "renderer/modeling/frame/frame.h"
#include "renderer/modeling/material/material.h"
#include "renderer/modeling/material/bsdf/phongdiffuse.h"

#include "renderer/kernel/rendering/renderframe.h"

int main(int argc, char** argv)
{

    const int frame_width = 640;
    const int frame_height = 480; 
    double camera_fov_angle = 0.9;

    // Image frame.
    renderer::Frame frame = renderer::Frame(frame_width, frame_height);

    // Camera.
    renderer::PinholeCamera camera;
    camera.m_fov_angle = camera_fov_angle;
    camera.m_frame = frame;

    // Scene.
    renderer::Scene scene;

    renderer::PhongDiffuse phong_diffuse1(foundation::Vector3d(0.2, 0.3, 0.5));
    renderer::Material material1(phong_diffuse1);

    foundation::Vector3d center1(5, 5, 5);
    double radius1 = 0.5; 
    renderer::Sphere sphere1;
    sphere1.m_center = center1;
    sphere1.m_radius = radius1;
    sphere1.m_radius2 = radius1 * radius1;
    sphere1.m_material = material1;
    scene.add(&sphere1);

    foundation::Vector3d center2(7, 2, 4);
    double radius2 = 0.2; 
    renderer::Sphere sphere2;
    sphere2.m_center = center2;
    sphere2.m_radius = radius2;
    sphere2.m_radius2 = radius2 * radius2;
    sphere2.m_material = material1;
    scene.add(&sphere2);

    foundation::Vector3d center3(2, 7, 6);
    double radius3 = 0.2; 
    renderer::Sphere sphere3;
    sphere3.m_center = center3;
    sphere3.m_radius = radius3;
    sphere3.m_radius2 = radius3 * radius3;
    sphere3.m_material = material1;
    scene.add(&sphere3);

    // Render scene.
    render_frame(frame, camera, scene, 1);


}






