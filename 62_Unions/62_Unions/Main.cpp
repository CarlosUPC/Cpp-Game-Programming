#include <iostream>

struct Vector2
{
	float x, y;
};

struct Vector4
{
	union //anonymous union & structs
	{
		struct //16 bytes
		{
			float x, y, w, z;
		};

		struct //16 bytes
		{
			Vector2 a, b;
		};
	};
};

union S
{
	int a;
	float b;
};

void PrintVector2(const Vector2& vector)
{
	std::cout << vector.x << " , " << vector.y << std::endl;
}

int main() {

	S s = { 4 };
	std::cout << s.a << std::endl;
	std::cout << s.b << std::endl;

	struct Union
	{
		union
		{
			float a;
			int b;
		};
	};

	Union u;
	u.a = 2.0f;
	std::cout << u.a << std::endl;
	std::cout << u.b << std::endl;

	Vector4 vector = { 1.0f,2.0f, 3.0f, 4.0f };
	PrintVector2(vector.a);
	PrintVector2(vector.b);

	vector.z = 500.0f;
	std::cout << "-----------------" << std::endl;

	PrintVector2(vector.a);
	PrintVector2(vector.b);



	std::cin.get();
}