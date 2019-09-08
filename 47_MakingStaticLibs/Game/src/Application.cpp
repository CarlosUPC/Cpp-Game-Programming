//#include "../../47_MakingStaticLibs/src/Engine.h"
#include "Engine.h"
#include <iostream>


//To link one project(as lib) to another (as exe) u can automate it using add-> reference with an advantage of if u change something like the name u need to change the namepath includes and setup link in overall. with reference option engine is now dependency against so game depends on engine. that means if something engine changes and we compile game, is going to compile engine and game
int main()
{

	engine::PrintMessage();
	std::cin.get();
}