
#pragma once

#include <vector>

#include "renderer/modeling/object/object.h"

namespace renderer {

class Scene {

  public:

	Scene();

	void add(Object* object);

	std::vector<Object*> objects;
	
};

} // namespace renderer