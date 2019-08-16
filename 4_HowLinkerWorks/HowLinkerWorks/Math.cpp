#include <iostream>
#include "Log.h"

//Linker always make 2 thing:
// 1 - if linker read a call symbol, he searches for its definition in same file and all other files
// 2 - if linker read a definition symbol, he searches for its possibly calls in same file and all other files


//There are 2 external linking errors:
// 1 - external un-defined symbol 
// 2 - external multiple-defined symbol

// How to resolve a external un-defined symbol:
//1 - define the symbol you are calling (just one time in any file)

// How to resolve a external multiple-defined symbol:
// 1 - static symbols --> internal linking
// 2 - inline symbols --> just copy the body of symbol
// 3 - declaration's h file --> include .h file into other cpp files


void Log(const char* message);

static int Multiply(int a, int b)
{
	Log("Multiply");
	return a * b;
}

int main()
{
	//std::cout << Multiply(2, 5) << std::endl;
}