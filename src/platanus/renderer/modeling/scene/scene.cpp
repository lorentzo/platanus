
#include "scene.h"

Scene::Scene() {}

void Scene::add(Object* object)
{
    objects.push_back(object);
}