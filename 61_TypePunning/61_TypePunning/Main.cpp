#include <iostream>
// see that for more details: https://www.cocoawithlove.com/2008/04/using-pointers-to-recast-in-c-is-bad.html

struct Entity
{
	int x, y;
};

int main()
{
	int a = 50;
	double value1 = a; //implicit conversion. different mem adress 
	std::cout << value1 << std::endl;

	double value2 = (double)a;//explicit conversion. diff mem adress

	double value3 = *(double*)&a;//type punning. same mem. treating one type mem as another type mem --> cause nasty bugs xd

	value3 = 0.4; //if u reassign value, the invalid mem is cleaned and all is sorted out


	std::cout << value3 << std::endl;

	double& value4 = *(double*)&a;

	value4 = 0.6;//as reference, when reassign value, the same int mem is increased as double mem, this might get crash

	std::cout << value4 << std::endl;

	//PRACTICAL EXAMPLE

	Entity e = { 5,8 }; //u can acces to struct fields mem because is like a stream of bytes through a pointer cast

	//int posx = e.x;
	int* position = (int*)&e; //safe with a pointer

	//int posy = e.y;
	int posy = *(int*)((char*)&e + 4);//safe with same type data

	std::cout << position[0] << " , " << *(position + 1) << std::endl;

	
	std::cin.get();
}