#include <iostream>

//Variables: 2 consideraciones -> Lifetime y scope (global o local)

//Global: lifetime until program runs down

//Local: lifetime until last curvy bracket is read (functions, statements, classes, etc)

//Local Static: lifetime like globals but scope limited to local cause is within something, thus, not accesible for everyone whom call it

//int i = 0; // Global
// static int i = 0; // Global static
void Function()
{
	static int i = 0; // Local static
	//int i = 0; //Local
	i++;
	std::cout << i << std::endl;
}

/*
class Singleton //Without local static instance
{
private:
	static Singleton* s_Instance;
public:
	static Singleton& Get() { return *s_Instance; }

	void Hello() {}
};

Singleton* Singleton::s_Instance = nullptr;
*/

class Singleton //With local static instance
{
public:
	static Singleton& Get() 
	{ 
		static Singleton instance;
		return instance;
	}

	void Hello() {}
};

//Resumen: hacen un codigo mas limpio y reducido, suelen servir cuando por ejemplo necesitas llamar una funcion static inicializadora para crear todos tus objetos 
int main()
{
	
	Singleton::Get().Hello();
	Function();
	//i = 10;  // Error symbol undefined porque la variable es local 
	Function();
	Function();
	Function();
	std::cin.get();
}