#include <iostream>
#include <string>
#include <memory>

//Unique Pointers: Scoped pointers, when scope ends, they are destroyed an mem is freed. Really low overhead

//Shared Pointers: use reference counting that keeps track how many references u have to ur pointer. if the counting reaches 0, pointer gets destroyed

//Weak Pointers: same as shared pointers but dont increase reference counting. Useful if u dont want to take ownership of entity. Example, u have a list of entities and dont really care if they are valid or not u just want to store like a reference to them

//BIT OVERHEAD SHARED POINTERS: ref counting system

//Useful cause it prevent u to avoid memory leaks 

//Preference by its overhead: unique, shared, weak

class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity" << std::endl;
	}
	~Entity() 
	{
		std::cout << "Destroyed Entity" << std::endl;
	}

	void Print() {}

};

int main() {

	
	//UNIQUE POINTERS
	{
		std::unique_ptr<Entity> entity0(new Entity());//not implicit convention 

		std::unique_ptr<Entity> entity1 = std::make_unique<Entity>();//exception safety PREFERRED WAY

		entity1->Print();
		//entity1 = entity0; // compiler error, can't copy smart pointers cause when one ptr dies and free mem, another pointer is pointing to mem which has been freed
	} 

	
	
	//SHARED POINTERS
	{

			std::shared_ptr<Entity> ent_shared0; //shared ptr without allocate mem, just for copy ref of another ptr
		{

			std::shared_ptr<Entity> ent_shared1 = std::make_shared<Entity>();//not use new in shared pointers cause they allocate mem in another blok of mem called control block where it sores reference count. if u make it, u are allocating the entity constructor on heap and pointer reference count on another bock of mem

			ent_shared0 = ent_shared1;
		}//delete ent_shared1 and ref counting is 1

	}//delete ent_shared0 and ref counting is 0. then mem allocated for that obj entity is freed. Object destroyed



	//WEAK POINTERS
	{

		std::weak_ptr<Entity> weak1; //invalid mem pointing to
		{
			std::shared_ptr<Entity> shared1 = std::make_shared<Entity>();

			weak1 = shared1; //weak points to valid mem (Entity bytes) but ref count is still 1

		} //shared pointer deleted and mem is freed

	} //weak pointer is pointing again an invalid mem until scope ends and gets deleted. In this case u can ask weak pointer if he is still valid or expired?
	std::cin.get();
}