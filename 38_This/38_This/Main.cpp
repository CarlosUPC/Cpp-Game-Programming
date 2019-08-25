#include <iostream>

//THIS: pointer to current obj instance that the method belong to. Just accesible on member functions(methods)

void PrintEntity(const Entity& e);

class Entity
{
public:
	int x, y;

	Entity(int x, int y) //non-const method: this is const and can't reassing to another mem adress
	{
		 Entity* const e = this; 
		//Entity* & const  e = this;// error
		//Entity*const &  e = this; //no error
		e->x = x;
		e->y = y;

		//Cleaner way
		this->x = x;
		this->y = y;

		PrintEntity(*this); //to call functions defined outside the class within a method the pointer this is usefull to reference ob instance

		 Entity& p = *this; //dereferencing in a non-const method
		
	}

	int GetX() const //const method: this is const const and cant modify nothing
	{ 
		const Entity* const e = this;

		const Entity& e = *this; //dereferencing in a const method

		return x;
	}
};

int main() {

	std::cin.get();
}

void PrintEntity(const Entity& e)
{
	//Print Something
}
