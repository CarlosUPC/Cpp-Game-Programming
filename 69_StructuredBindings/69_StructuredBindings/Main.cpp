#include <iostream>
#include <string>
#include <tuple>

std::tuple<std::string, int> CreatePerson()
{
	return{ "Cherno", 24 };
}

int main() 
{

	//TIE WAY
	std::string name;
	int age;

	std::tie(name, age) = CreatePerson();//3 lines

	//BINDING WAY
	auto[name1, age1] = CreatePerson(); //1 line 

	std::cout << name1 << std::endl;

	std::cin.get();
}