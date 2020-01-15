
#pragma once

#include "foundation/math/ray.h"

#include "renderer/modeling/scene/scene.h"
#include "renderer/modeling/object/object.h"

namespace renderer {

class Intersector
{
  public: 

	Intersector();
	Intersector(Scene scene);

    bool trace(
		const foundation::Ray& ray,
		double &t,
		const Object *&hit_object);

	Scene m_scene;

};

} // namespace renderer