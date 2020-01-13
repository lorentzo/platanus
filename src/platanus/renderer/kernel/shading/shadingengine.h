
#include <math.h>
#include <random>

#include "./../../../foundation/math/vector.h"
#include "./../../../foundation/math/ray.h"

#include "./../intersection/intersector.h"

#include "./../../modeling/scene/scene.h"
#include "./../../modeling/object/object.h"

// Helpers for random number generation
std::mt19937 mersenneTwister;
std::uniform_real_distribution<double> uniform;

#define RND (2.0*uniform(mersenneTwister)-1.0)
#define RND2 (uniform(mersenneTwister))
#define PI 3.1415926536

class ShadingEngine
{
    public:

    Scene m_scene;
    Intersector m_intersector;

    ShadingEngine(Scene m_scene);

    // given v1, set v2 and v3 so they form an orthonormal system
    // (we assume v1 is already normalized)
    void ons(const Vector3d& v1, Vector3d& v2, Vector3d& v3);

    // Uniform sampling on a hemisphere to produce outgoing ray directions.
    // courtesy of http://www.rorydriscoll.com/2009/01/07/better-sampling/
    Vector3d hemisphere(double u1, double u2);

    // Assume point light in viewer (camera) position.
    // Only L*N*color.
    Vector3d shade_simple(const Ray &ray);


};