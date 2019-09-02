#include <iostream>
#include <string>

//Template: bunch of code that will be compiled based on its usage. The compiler writes code for u based on the rules u have given. Its like a blueprint when it is called with a list of params, then the data pass into template and create that function by ur compiler

//Usage: templates are useful to avoid code duplication. is the solution from overloading again and again a function manually

//Template is not actual code, is a blueprint that is created when is called with a given params

//templates are a sort of meta programming: instead of actually programming what our code does at runtime we are kind of programming what the compiler will actually do during compile time --> extremely powerful

//tip: use templates but dont go too far
template<typename T>
void Print(T value) {
	std::cout << value << std::endl;
}

template<typename T,int N> //templates are evaluated at compile time
class Array //allocated stack array need to know which is his size at compile time
{
private:
	T m_Array[N];
public:
	int GetSize() const { return N; }
};

int main() {
	Print<int>(5); //u can pass the param type explicity
	Print<float>(5.5f);
	Print("Hello");

	Array<int,5> array;
	std::cout << array.GetSize() << std::endl;

	std::cin.get();
}