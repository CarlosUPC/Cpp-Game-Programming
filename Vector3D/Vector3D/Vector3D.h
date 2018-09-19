#ifndef VEC3D
#define VEC3D

#include <cmath>
#include <stdio.h>

template <class TYPE>
class Vec3 {

private:
	TYPE x, y, z;

public:

	//Contructors
	Vec3<TYPE>() {
	} 

	Vec3<TYPE>(const TYPE &_x, const TYPE &_y, const TYPE &_z) {
		x = _x;
		y = _y;
		z = _z;
	}

    Vec3<TYPE>(const TYPE &_x, const TYPE &_y) {
        x = _x;
        y = _y;
		z = 0;
	}

	//Operators
	Vec3<TYPE> operator +(const Vec3<TYPE> &other) const {
		return Vec3<TYPE>{ x + other.x, y + other.y, z + other.z };
	}

	Vec3<TYPE> operator -(const Vec3<TYPE> &other) const {
		return Vec3<TYPE>{ x - other.x, y - other.y, z - other.z };
	}

	Vec3<TYPE> operator +=(const Vec3<TYPE> &other) {
		return Vec3<TYPE>(x += other.x, y += other.y, z += other.z);
	}

	Vec3<TYPE> operator -=(const Vec3<TYPE> &other) {
		return Vec3<TYPE>(x -= other.x, y -= other.y, z -= other.z);
	}

	Vec3<TYPE> operator = (const Vec3<TYPE> &other) {
		return Vec3<TYPE>(x = other.x, y = other.y, z = other.z);
	}

	bool operator == (const Vec3 other) {
		return (x == other.x && y == other.y && z == other.z);
	}

	Vec3<float> GetNormalised() {
		float module = sqrt(x*x + y * y + z * z);
		return { (float)x / module, (float)y / module, (float)z / module };
	}

	Vec3 Zero() {
		return { 0, 0, 0 };
	}

	bool is_Zero() {
		return (x == 0 && y == 0 && z == 0);
	}

	float distance_to(const Vec3 other) {
		Vec3 result = *this - other;
		float resultModule = sqrt(result.x*result.x + result.y*result.y + result.z*result.z);

		return resultModule;
	}

	void Log() const {
		printf("\n( %f, %f, %f ) \n", (float)x, (float)y, (float)z);
	}



};

#endif VEC3D

