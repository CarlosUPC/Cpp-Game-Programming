#include <iostream>
#include <GLFW/glfw3.h> // ANGULAR BRACKETS: compiler espezified build
                        //QUOTES: relative path and then compiler esp build

//Recommended way: quotes for files that are inside the solution. Angular brackets for dependencies & external lib not compiled into the solution


//External Linking: NOT!, dont must be kind of syncing to package manager to deal with repository projects

//Recommended: keep versions of depedencies and libraries u are using within all ur code source. all of that binaries in my working directory of solution project

//Point: should i be comppiling these myself or be linking against pre-built binaries. For most serius projects, recommended building the source code, just add another project that contains all of source code of your library / dependency and then compile that into either a static or dynamic lib. However, if u cant access its source code or planning a quick small project then its recommended link against the binaries because is a easy and quicker set up

//one case: maybe the binaries are not compiled and u are forced to compile it yourself (just if use mac or linux).

//If u have time, recommended to compile it yourself because it helps for debugging purposes and can modify the lib and change it a little bit

//32-bit binaries vs 64-bit: if u are compilin ur app as an x86 /win32 app then u want 32-bit bins, otherwise, u want 64-bit. make sure u match them together cause u dont they wont link

//2 parts of a library: include directory and lib directory

//Include Dir: bunch of header files. each of them have declarations of symbols u would use that are in the pre-built binaries

//2 phases: static and dynamic libraries to want to link statically or dynamically

//Static linking: the library gets basically put into your executable

//Dynamic linking: library gets actually linked at runtime. a separate file u need to have alongside .exe

//dll: dynamic link library

//Tip: use static linking whenever it possible. technically faster cause we know what functions we are linking whereas dyn libs we dont know whats gonna happen

//Usage: include files are used to include header files to tell compiler that some declarations of lib exist and link properly lib files for a good linkage about its definitions

//pre-compiled files:
// 1 - static lib for static linkage. significantly bigger KB we linked it if we dont want compile time linking. we dont need dll file

// 2 - dynamic lib for dynamic linkage at runtime (.dll). we will ask to .dll about a function pointers to each function we want to call for its usage 

// 3 - static lib + dll: this file contains all the locations of defined functions .dll have and we avoid asking to .dll for all of them when we call them. we can kink them at compile time

//extern "C" int glfwInit(); //mangling name cause the library was written in C
int main() {

	int a = glfwInit();
	std::cout << a << std::endl;

	std::cin.get();
}