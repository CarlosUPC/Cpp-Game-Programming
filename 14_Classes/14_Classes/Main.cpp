#include <iostream>
#define LOG(x) std::cout << x << std::endl;

class Player // visibility private by default
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
int main() {
	Player player;

	//player.x = 5;
	//player.Move(1, -1);

	player.func(1,-1);
	std::cin.get();
}