#include "Vector3D.h"
#include <iostream>;

using namespace std;

int main() {
	
	
	Vec3<int> v1(2, 1, 5);
	Vec3<int> v2 = { 3, 0 };

	Vec3<int> v3 = v1 + v2;
	
	v3.Log();
	v3 += v1;
	v3.Log();
	v3 -= v2;
	v3.Log();

	Vec3<float> normalised = v1.GetNormalised();

	float dist = v1.distance_to(v3);
	normalised.Log();

	printf("\n ");
	
	system("pause");
	//return 0;
}