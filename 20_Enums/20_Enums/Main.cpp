#include <iostream>

enum Example : unsigned char // Enums solo coleccionan valores de integers type
{
	A = 0,
	B = 65,
	C 
};


int main() 
{
	

	Example value = B; //Enum variables no traducen ascii values, todo son numeros
	unsigned char a = B; //char variables traducen ascii values, todo son letras
	

	std::cout <<  value  << std::endl;
	std::cout << sizeof(value) << std::endl;

	std::cout << a << std::endl;
	std::cout << sizeof(a) << std::endl;

	if (value == 1)
	{
		//Do something here
	}

	std::cin.get();
}