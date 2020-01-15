
#include "scene.h"

namespace renderer {

Scene::Scene() {}

void Scene::add(Object* object)
{
    objects.push_back(object);
}

} // namespace renderer