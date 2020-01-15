
#include "intersector.h"

#include <limits>

using namespace foundation;

namespace renderer {

const float infinity = std::numeric_limits<double>::max(); 

Intersector::Intersector() {}

Intersector::Intersector(Scene scene) : m_scene(scene) {}

bool Intersector::trace(
    const Ray& ray,
    double &t_near,
	const Object *&hit_object)
{

    t_near = infinity;

    for(size_t i = 0; i < m_scene.objects.size(); ++i)
    {
        double t_tmp = infinity;

        if(m_scene.objects[i]->intersect(ray, t_tmp))
        {
            if(t_tmp < t_near)
            {
                hit_object = m_scene.objects[i];
                t_near = t_tmp;
            }
        }

    }

    return (hit_object != nullptr);
    
}

} // namespace renderer