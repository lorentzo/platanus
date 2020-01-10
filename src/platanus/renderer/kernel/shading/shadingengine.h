
#include <math.h>
#include <random>

#include "shadingcontext.h"
#include "./../../../foundation/math/vector.h"

// Helpers for random number generation
std::mt19937 mersenneTwister;
std::uniform_real_distribution<double> uniform;

#define RND (2.0*uniform(mersenneTwister)-1.0)
#define RND2 (uniform(mersenneTwister))
#define PI 3.1415926536

class ShadingEngine
{
    public:

    ShadingContext m_shading_context;

    ShadingEngine(ShadingContext shading_context)
    {
        m_shading_context = shading_context;
    }

    // given v1, set v2 and v3 so they form an orthonormal system
    // (we assume v1 is already normalized)
    void ons(const Vector3d& v1, Vector3d& v2, Vector3d& v3) {
        if (std::abs(v1.x) > std::abs(v1.y)) {
            // project to the y = 0 plane and construct a normalized orthogonal vector in this plane
            float invLen = 1.f / sqrtf(v1.x * v1.x + v1.z * v1.z);
            v2 = Vector3d(-v1.z * invLen, 0.0f, v1.x * invLen);
        } else {
            // project to the x = 0 plane and construct a normalized orthogonal vector in this plane
            float invLen = 1.0f / sqrtf(v1.y * v1.y + v1.z * v1.z);
            v2 = Vector3d(0.0f, v1.z * invLen, -v1.y * invLen);
        }
        v3 = v1 % v2;
    }

    // Uniform sampling on a hemisphere to produce outgoing ray directions.
    // courtesy of http://www.rorydriscoll.com/2009/01/07/better-sampling/
    Vector3d hemisphere(double u1, double u2) {
        const double r = sqrt(1.0 - u1*u1);
        const double phi = 2 * PI * u2;
        return Vector3d(cos(phi)*r, sin(phi)*r, u1);
    }


    Vector3d shade()
    {

        Vector3d intersection_point;
        Vector3d normal;
        m_shading_context.calculate_shading_params(intersection_point, normal);

        // Sample shading ray from hemisphere.
        Ray shading_ray;
        shading_ray.o = intersection_point;
        Vector3d rotX, rotY;
		ons(normal, rotX, rotY);
		Vector3d sampledDir = hemisphere(RND2, RND2);
		Vector3d rotatedDir;
		rotatedDir.x = Vector3d(rotX.x, rotY.x, normal.x).dot(sampledDir);
		rotatedDir.y = Vector3d(rotX.y, rotY.y, normal.y).dot(sampledDir);
		rotatedDir.z = Vector3d(rotX.z, rotY.z, normal.z).dot(sampledDir);
		shading_ray.d = rotatedDir;	// already normalized

        // Russian roulette: starting at depth 5, each recursive step will stop with a probability of 0.1
        double rrFactor = 1.0;
        int depth = 0;

        while(true)
        {
            if (depth >= 5)
            {
                const double rrStopProbability = 0.1;

                if (RND2 <= rrStopProbability) 
                {
                    break;
                }

                rrFactor = 1.0 / (1.0 - rrStopProbability);
            }

            


        }





        
        // izlazna u kameru je N * L * ro / pi

    }


};