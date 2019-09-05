#include <iostream>
#include <vector>

//Functions are allocated as CPU instructions in binary executable to be called. Func can be retrieved from his locations and points to a variable with same data type of that function

void HelloWord(int a)
{
	std::cout << "Hello World" << a << std::endl;
}

void ForEach(const std::vector<int>& values, void(*func)(int))
{
	for (int value : values)
		func(value);
}

int main()
{
	//1. Func.Pointer creation
	void(*Hello)(int) = HelloWord;
	Hello(3);

	//2. Func. Pointer creation with auto
	auto function = HelloWord; //implicit convention of &HelloWorld adress mem
	function(3); 

	//3. Func.Pointer creation with typedef
	typedef void(*FuncPtr)(int);
	FuncPtr func = HelloWord;
	func(3);

	//1 - Example
	std::vector<int> values = { 1,5,4,2,3 };

	ForEach(values, HelloWord);

	//2 - Example
	ForEach(values, [](int value) {std::cout << "Value: " << value << std::endl; }); //Lambda, avoid extra func creation

	std::cin.get();
}