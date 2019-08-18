#include <iostream>
#define LOG(x) std::cout << x << std::endl;


int main() {

	/*double* pt = NULL;
	pt = (double*)&a;*/ //

	int a = 5;
	int* pt = &a;
	*pt = 10;


	LOG(a);

	//Cuando no sabemos el size de bloque de memoria que apunta un pointer, la podemos crear nosotros mismos en el heap
	char* buffer = new char[8]; //Memoria dinamica - heap
	memset(buffer, 0, 8);

	char** ptr = &buffer; // Puntero que apunta a puntero

	delete[] buffer;
	std::cin.get();
}