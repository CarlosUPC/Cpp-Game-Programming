#include <iostream>
#include <string>

using String = std::string;

//2 ways to instantiate obj
//1: Stack --> for not big classes and dont want to take control from its lifetime objs. FASTER WAY / Few memory mega byte. Recommended way

//2: Heap --> for bigger classes and want to take control from its lifetime objs. SLOWER WAY / HIT PERFORMANCE / more mem 

//Scope --> functions, statements, for loops and empty scope {}

//new costs: allocate on heap takes longer and manually u need to destroy obj and free mem
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
	//Stack (3 manners)
	Entity entity0; //default constructor
	Entity entity1("Cherno"); 
	Entity entity2 = Entity("Cherno");

	Entity* e;

	//STACK SCOPE
	{
		Entity s_entity = Entity("Cherno");
		e = &s_entity;
		std::cout << s_entity.GetName() << std::endl;

	} //when scope ends, e pointers will point on same adress mem but empty mem because obj instantiate locally will be destroyed
	

	//HEAP SCOPE
	{
		Entity* h_entity = new Entity("Cherno"); // new: allocate in heap mem an obj and returns a pointer that points to. Thats why we need to declare a pointer

		e = h_entity;
		std::cout << (*h_entity).GetName() << std::endl;
	}


	std::cout << entity0.GetName() << std::endl;

	std::cin.get();
	delete e;
}