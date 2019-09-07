#include <iostream>
#include <any>

//variant better than any
//any: generates heap allocation if size allocation is bigger than 32 bytes, variant not.

void* operator new(size_t size)
{
	return malloc(size);
}

struct CustomClass {
	std::string s0, s1;
};
int main() {

	std::any data;
	data = 2;
	data = "Cherno";
	//data = std::string("Cherno");
	data = CustomClass(); //call new operator

	std::string& string = std::any_cast<std::string&>(data);

	std::cin.get();
}