#ifndef VEC3D
#endif VEC3D

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
	Vec3<T> operator +(const Vec3<T> &other) const {
		return Vec3<T>{ x + other.x, y + other.y, z + other.z };
	}

	Vec3<T> operator -(const Vec3<T> &other) const {
		return Vec3<T>{ x - other.x, y - other.y, z - other.z };
	}

	Vec3<T> operator +=(const Vec3<T> &other) {
		return Vec3<T>(x += other.x, y += other.y, z += other.z);
	}

	Vec3<T> operator -=(const Vec3<T> &other) {
		return Vec3<T>(x -= other.x, y -= other.y, z -= other.z);
	}

	Vec3<T> operator = (const Vec3<T> &other) {
		return Vec3<T>(x = other.x, y = other.y, z = other.z);
	}

	bool operator == (const Vec3 other) {
		return (x == other.x && y == other.y && z == other.z);
	}



};

#endif VEC3D

