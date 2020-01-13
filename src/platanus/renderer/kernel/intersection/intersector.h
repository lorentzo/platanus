
#include "./../../modeling/scene/scene.h"
#include "./../../modeling/object/object.h"

class Intersector
{
  public: 

	Intersector();
	Intersector(Scene scene);

    bool trace(
		const Ray& ray,
		double &t,
		const Object *&hit_object);

	Scene m_scene;

};
