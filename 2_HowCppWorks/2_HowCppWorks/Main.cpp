#include <iostream> //Preprocessor statement

void Log(const char* message);//Function Declaration

extern int a; //Variable Declaration 

int main() { // función especial que retorna int 0 por default aunque no lo retornes al final (return 0;)

	a = 10;
	Log("Hello World");
	std::cin.get();
}

