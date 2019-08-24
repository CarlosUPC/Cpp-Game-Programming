#include <iostream>
#include <string>


//Implicit convention of symbol types just can be enabled thanks to constructors with his entry parameters. Thats make possible the conversion

//Eplicit keyword: disables implicit conversion. Useful something related to math libraries that convert numbers into vectors internally but not used oftenly

class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	explicit Entity(int age) : m_Name("Unknown"), m_Age(age) {} 

	explicit Entity(const std::string& name) : m_Name(name), m_Age(-1) {}

	/*
	Entity(const char name[]) : m_Name(name), m_Age(-1) {}
	*/
	
};

void PrintEntity(const Entity& entity)
{
	//Printing
}

int main()
{
	//Explicit keyword generates compiler errors

	PrintEntity(22);

	PrintEntity(std::string("Cherno"));

	Entity a = std::string("Cherno");//implicit convention of string to Entity 
	Entity b = 22; //implicit convention of int to Entity 


	std::cin.get();
}