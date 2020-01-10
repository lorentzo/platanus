
#include <vector>

#include "./../object/object.h"

class Scene {

  public:

	Scene() {}

	void add(Object* object) {
		objects.push_back(object);
	}

	std::vector<Object*> objects;
	
};
