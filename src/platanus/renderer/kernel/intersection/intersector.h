
#include "tracecontext.h"
#include "./../shading/shadingcontext.h"

class Intersector
{
    TraceContext m_trace_context;

    Intersector(TraceContext trace_context) 
    {
        trace_context = trace_context;
    }

    ShadingContext trace(const Ray& ray) const {
		ShadingContext closestIntersection;
		// intersect all objects, one after the other
		for (auto iter = m_trace_context.m_scene.objects.begin(); iter != objects.end(); ++iter) {

			double t = (*iter)->intersect(ray);
			if (t > eps && t < closestIntersection.t) {
				closestIntersection.t = t;
				closestIntersection.object = *iter;
			}
		}
		return closestIntersection;
	}


}
