#include <iostream>
#include <string>

// C libs like GLFW dont have namespace cause is C code. Therefore, his functions are named with a unique prefix to avoid naming conflicts. Ex: GLFWInit()

//Namespaces: avoid naming conflicts. Ex: std::cout from STL lib that has namespace cause is C++ code

//Usin namespace: avoid using that prefix namespace. Not recommended on top level scopes or header files because can cause a lot of problems with naming conflicts of diferents libs. Use it on small local scopes like if statements or functions or for loops etc if u need to use it. Also, is not recommended cause is confusing his namespace functions with yours new brand functions or functions from another lib C++

namespace apple {
	namespace functions { //nested namespace
		void print(const std::string& text) {
			std::cout << text << std::endl;
		}
	}
}

namespace orange {
	void orange_print(const char* text) {
		std::string temp = text;
		std::reverse(temp.begin(), temp.end());
		std::cout << temp << std::endl;
	}
}


int main()
{
	//Manners of use "using" with namespace
	using namespace orange;
	namespace a = apple;
	using namespace apple::functions;
	
	print("Hello");
	
	orange_print("Hello");


	std::cin.get();
}