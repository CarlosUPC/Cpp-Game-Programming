#include <iostream>
#include <string>

using String = std::string;

// NEW: when using new keyword, we ask operating system for x bytes of heap mem to allocate our data. If data type is a class obj. In same time it calls his default constructor

//New is an operator
//New returns a void pointer
//New = malloc function

class Entity
{
private:
	String m_Name;
public:
	Entity() : m_Name("Unknown") {}
	Entity(const String& name) : m_Name(name) {}

	const String& GetName() const { return m_Name; }
};

int main()
{
	int a = 2;
	int* b = new int; //4 bytes
	int* c = new int[50]; //200 bytes

	//OBJ NEW MANNERS
	Entity* e0 = new Entity(); //allocates mem and call its constructor
	Entity* e1 = new Entity;
	Entity* e2 = new Entity[50];


	//DIFF BETWEEN NEW AND MALLOC
	Entity* example0 = new Entity();//allocates mem, return a void pointer and CALLS CONSTRUCT!
	Entity* example1 = (Entity*)malloc(sizeof(Entity)); //This just allocates mem and return a void pointer. Not recomend to allocate mem from this way. 

	//FREE MEM
	delete b;
	delete[] c;

	delete example0; // free mem and calls DESTRUCTOR!

	//PLACEMENT NEW
	Entity* place = new(b) Entity(); //Explicit an adress mem toallocate Entity obj bytes. Make sure that adress mem have enough size 
	std::cin.get();
}