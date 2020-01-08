
#include "./../../modeling/scene/scene.h"

class TraceContext
{
    public:
    
    Scene m_scene;

    TraceContext(Scene scene)
    {
        m_scene = scene;
    }
}