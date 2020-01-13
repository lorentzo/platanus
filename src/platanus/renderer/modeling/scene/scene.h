
#include <vector>

#include "./../object/object.h"

class Scene {

  public:

	Scene();

	void add(Object* object);

	std::vector<Object*> objects;
	
};
