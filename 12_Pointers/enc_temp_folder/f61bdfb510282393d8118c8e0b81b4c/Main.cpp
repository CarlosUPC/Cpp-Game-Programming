#include <iostream>
#define LOG(x) std::cout << x << std::endl;


int main() {

	/*double* pt = NULL;
	pt = (double*)&a;*/

	int a = 5;
	int* pt = &a;
	*pt = 10;


	LOG(a);

	//Cuando no sabemos el size de bloque de memoria que apunta un pointer, la podemos crear nosotros mismos en el heap
	char* buffer = new char[8];
	memset(buffer, 0, 8);

	char** ptr = &buffer;

	delete[] buffer;
	std::cin.get();
}