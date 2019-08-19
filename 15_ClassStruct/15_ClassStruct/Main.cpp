#include <iostream>
#define LOG(x) std::cout << x << std::endl;

struct Player // visibility public by default
{
	int x, y;
	int speed;

	void Move(int xa, int ya)
	{
		x += xa * speed;
		y += ya * speed;
	}

public: // los miembros y metodos privados solo se pueden acceder via funciones publicas
	void func(int xa, int ya) {
		Move(xa, ya);
	}
};

struct Vec2 // Las structs son lo mismo que las classes, pero para el uso de codigo sirven para generar un tipo de variable que collecciona data y metodos. Cuando se tiene en cuenta darle funcionalidad a los objetos, inheritance, polimorfims, parents, etc, se usan classes.
{
	float x, y;

	void Add(const Vec2& other)
	{
		x += other.x;
		y += other.y;
	}
};


int main() {
	

	Vec2 vec1;
	vec1.x = 5;
	vec1.y = 5;
	
	Vec2 vec2;
	vec2.x = 2;
	vec2.y = 2;

	vec1.Add(vec2);

	LOG(vec1.x);
	LOG(vec1.y);

	
	std::cin.get();
}