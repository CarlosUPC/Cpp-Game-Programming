
#include <iostream>
#include <GLFW/glfw3.h> 


//DL = linking that happens at runtime. that means when ur exe is launched, ut dynamic link lib is loaded, u are linking an external binary file into memory with ur binary exe

//exe is aware of dll and list it as a requirement that why u need this additional files near ur exe, in other words, dll needs to be present at launch time

//static linking -> allos more of that optimization cause all the lib contents are inside the exe and compiler and linker are aware of that

//header files supports both static and dyn linking

//glfw3dll.lib => a set of pointers that point to dll file so we dont have to retrieve the locations of everything at runtime. important to compiler both iles at same time cause u can get mismatching functions etc. dll and dll.lib are related directly and u cant separate these two

//u can build the program but cant execute it cause of .exe doesnt know about the presence of dll (dll requirement pop-up). dll need to be in an accessible place for the exe. also, u can set path to certain libs like search locations but the root folder that fold .exe file is kind of a search path

//REMINDER: declare as inner preprocessor macro = GLFW_DLL to import dll file and turn on GLFWAPI as dyn lib
int main() {

	int a = glfwInit();
	std::cout << a << std::endl;

	std::cin.get();
}