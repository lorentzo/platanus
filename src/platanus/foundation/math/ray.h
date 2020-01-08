
#include "vector.h"

// Rays have origin and direction.
// The direction vector should always be normalized.
struct Ray {
	Vector3d o, d;
	Ray(Vector3d o0 = 0, Vector3d d0 = 0) { o = o0, d = d0.norm(); }
};