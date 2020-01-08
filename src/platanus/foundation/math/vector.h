
#include <math.h>
#include <stdlib.h>

//
// Inspired by:
// https://users.cg.tuwien.ac.at/zsolnai/gfx/smallpaint/
//

struct Vector3d {

	double x, y, z;

	Vector3d(
        double x0 = 0, 
        double y0 = 0, 
        double z0 = 0) 
    { 
        x = x0; 
        y = y0; 
        z = z0; 
    }

	Vector3d operator+(const Vector3d &b) const 
    { 
        return Vector3d(x + b.x, y + b.y, z + b.z); 
    }

	Vector3d operator-(const Vector3d &b) const 
    { 
        return Vector3d(x - b.x, y - b.y, z - b.z); 
    }

	Vector3d operator*(double b) const 
    { 
        return Vector3d(x*b, y*b, z*b); 
    }

	Vector3d operator/(double b) const 
    { 
        return Vector3d(x / b, y / b, z / b); 
    }

	Vector3d mult(const Vector3d &b) const 
    { 
        return Vector3d(x*b.x, y*b.y, z*b.z); 
    }

	Vector3d& norm() 
    { 
        return *this = *this * (1 / sqrt(x*x + y*y + z*z)); 
    }

	double length() 
    { 
        return sqrt(x*x + y*y + z*z); 
    }

	double dot(const Vector3d &b) const 
    { 
        return x*b.x + y*b.y + z*b.z; 
    }

	Vector3d operator%(const Vector3d &b) const 
    { 
        return Vector3d(y*b.z - z*b.y, z*b.x - x*b.z, x*b.y - y*b.x); 
    }

    /*
	double& operator[](size_t i) 
    { 
        return data[i]; 
    }
    */

	const double& operator[](size_t i) const 
    { 
        return i == 0 ? x : (i == 1 ? y : z); 
    }

};