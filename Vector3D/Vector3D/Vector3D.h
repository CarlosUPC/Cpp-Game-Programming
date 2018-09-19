#ifndef VEC3D
#endif VEC3D

template <class TYPE>

class Vec3 {

private:
	TYPE x, y, z;

public:

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


};

#endif VEC3D

