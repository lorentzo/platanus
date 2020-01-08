
#include <vector>

#include "./../object/sphereobject.h"
#include "./../../../foundation/math/ray.h"

class Scene {
public:

	std::vector<Sphere*> objects;



	void add(Sphere* object) {
		objects.push_back(object);
	}
	
};
