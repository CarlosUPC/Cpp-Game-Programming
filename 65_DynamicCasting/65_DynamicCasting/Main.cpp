#include <iostream>

class Entity
{
public:
	virtual void Func(){}
};

class Player : public Entity
{
public:
	int a, c;
};

class Enemy : public Entity
{
public:
	float b;
	double d;
};

int main() 
{
	Player* player = new Player(); //it has 2 types associated: Entity and Player
	player->a = 2;
	player->c = 6;

	Entity* e1 = player; //implicit conversion -> no problem 

	Player* p1 = player; //implicit conversion -> no problem

	Enemy* e = (Enemy*)player; //cant implicit conversion --> problem //Solved with explicit conversion but its dangerous because at this point an enemy pointer points to a player stream of mem and if enemy class has unique func and u try to call it with enemy pointer will be funny crashes. if both classes are identical might it wouldnt crash, might xD
	//e->b = 3.5f;
	
	std::cout << e->d << std::endl;
	
	//Dynamic cast
	Entity* actuallyEnemy = new Enemy();
	Entity* actuallyPlayer = player;

	Player* p0 = dynamic_cast<Player*>(actuallyEnemy);//to use dc, base class needs to have virtual functions to tell to the compiler that that base class has props wich extend to sub-classes so make the cast more realistic

	if (p0) { //that returns a null ptr
		//bla bla bla
	}
	Player* p0 = dynamic_cast<Player*>(actuallyPlayer); //returns null if is invalid cast and the adress mem if is valid cast


	//dynamic cast uses Runtime type information to handle type checking validation to make it possible --> incurs a biit of overhead

	std::cin.get();
}