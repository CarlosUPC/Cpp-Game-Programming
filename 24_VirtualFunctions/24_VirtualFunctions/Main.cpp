#include <iostream>
#include <string>

//dynamic dispatch -> compiler implement a v-table that contain all mapping of virtual functions. we can map them to correct overwritten function at runtime

//2 runtime costs about dynamic dispatch:
          // 1--> memory cost to allocate v table and member base pointer that points to it
          // 2--> every call of a virtual function will perform v table mapping, that means more cpu work, additional perfomance penalty     
class Entity
{
public:
	virtual std::string GetName() { return "Entity"; } //virtual: enables dynamic dispatch, tells the compiler that

};

class Player : public Entity { 

private:
	std::string m_Name;
public:
	Player(const std::string& name)
		:m_Name(name) {}

	std::string GetName() override{ return m_Name; } //override: not necessary but make code more readable, prevents bugs like spelling mistakes. Te avisan de si existen funciones virtuales para que puedan ser sobreescritas
	
};

void PrintName(Entity* entity) {
	std::cout << entity->GetName() << std::endl;
}

int main()
{
	Entity* e = new Entity();
	PrintName(e);
	std::cout << e->GetName() << std::endl;

	Player* p = new Player("Carlos");
	PrintName(p);
	std::cout << p->GetName() << std::endl;

	Entity* entity = p;
	std::cout << entity->GetName() << std::endl;

	std::cin.get();
}