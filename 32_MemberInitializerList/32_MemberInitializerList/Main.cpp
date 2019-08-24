#include <iostream>
#include <string>

// Usage of member init list:
      //1 - cleaner code
      //2 - avoid repetition member creation

class Example {
public:
	Example() {
		
		std::cout << "Created Entity!" << std::endl;
	}

	Example(int x) {
		std::cout << "Created Entity " << x << std::endl;
	}
};





class Entity
{
private:
	std::string m_Name;
	int m_Scope;
	Example m_Example; //compiler will run this obj var and initialize automatically by his default construct
	
public:
	Entity()
		: m_Name("Unknown"), m_Scope(0), m_Example(Example(8)) //init members in order as declared before to avoid compiler errors
	{
		
		//m_Example = Example(8); 
	}

	Entity(const std::string& name)
		:m_Name(name) {}

	const std::string& GetName() const { return m_Name; }
};

int main() {

	 Entity e0; //we create 2 obj in one. Thats because when define a obj the compiler run the region of variables the class has too
	 Entity e1(std::string("Hello"));

	 //This performance hit doesnt work with primitive data types like int
	
	
	

	std::cin.get();
}