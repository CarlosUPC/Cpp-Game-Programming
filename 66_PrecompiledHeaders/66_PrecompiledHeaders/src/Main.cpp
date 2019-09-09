#include "pch.h"

//first time u build the project header will compiled and be around 2300 ms (2,3s) and then the following time u build project and dont change header it will compile and run fester around (600-700ms) using precompiled headers

//in g++ it compiles much faster than visual studio compiler

//remember tools->options->porejcts solutions->settings->timing
int main()
{
	std::cout << "Hello Word" << std::endl;
	
}