
#include "intersector.h"

#include <limits>

const float infinity = std::numeric_limits<double>::max(); 

Intersector::Intersector(Scene scene) : m_scene(scene) {}

bool Intersector::trace(
    const Ray& ray,
    double &t,
	Object **hit_object)
{

    *hit_object = nullptr;

    for(size_t i = 0; i < m_scene.objects.size(); ++i)
    {
        double t_near = infinity;

        if(m_scene.objects[i]->intersect(ray, t))
        {
            if(t < t_near)
            {
                *hit_object = m_scene.objects[i];
                t_near = t;
            }
        }

    }

    return (hit_object != nullptr);
    
}
