#include <iostream>
#include "Log.h"
#include "Common.h"

// Evitar la copia multiple de header files para evitar errores de redefinition (ex: structs)
int main()
{
	Log("Hello World");
	std::cin.get();
}