#include <iostream>

#define LOG(x) std::cout << x << std::endl;

//FUNCIÓN POR REFERENCIA
void Increment(int& value)
{
	value++; // value == a , se modifica a
}

//FUNCIÓN POR VALOR
/*
void Increment(int value)
{
	value++; // value es una copia de a, no se modifica a
}
*/

//FUNCIÓN POR PUNTERO
/*
void Increment(int* value)
{
	(*value)++;//*ptr --> acceso al contenido de su dirección de memoria asignada 
}
*/

int main() 
{
	int a = 5;
	int b = 4;


	int& ref = a;
	ref = b; //referencia solo referencia a uno --> a = b

	int* ptr = &a;
	ptr = &b; //puntero cambia de dirección de memoria


	//Increment(a); F.Valor
	//Increment(&a); F.Puntero
	Increment(a); //F.Referencia

	//Referencias: Es lo mismo que los punteros, mejor leible y más simple. No son variables, son alias de otras variables a las que hace referencia (solo a 1)

	//Punteros: Son variables que contienen un entero (0x0000) direcciones de memoria de otras variables. Son muy potentes

	LOG(a);
	LOG(b);
	std::cin.get();
}