
#include "./../../modeling/scene/scene.h"
#include "./../../modeling/object/object.h"

class Intersector
{
  public: 

	Intersector(Scene scene);

    bool trace(
		const Ray& ray,
		double &t,
		Object **object);

	Scene m_scene;

};
