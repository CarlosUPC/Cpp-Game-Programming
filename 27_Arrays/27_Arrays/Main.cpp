#include <iostream>
#include <array>
//Memory access violation

//For loops: indexable like arrays
//stored data in a row by its data type. in this case stores 4 bytes each element in a row: 20 bytes

//diff stack and heap: heap allocation memory differs with stack when we talk about his lifetime. when it allocates mem on stack, it frees when the scope of func ends. when it allocates mm on heap, it frees when program ends or using delete keyword.

//Real world example: if you want to return a new brand array created within a func u need to create it dinamically. Otherwise this array will be destroyed when func scope ends

//Memory indirection: pointer thats points into another adress mem which points to block of mem (array). it results in kind of mem fragmentation and caches misses. this gets a performance hit

//C++ 11 standard arrays: bound checking, keeps track of the size of array.A bit of overhead. are safer than raw arrays

//Raw arrays: faster than standard arrays
class Entity
{
public:
	//int example[5]; this doesnt do mem indirection
	int* example = new int[5]; //this does mem indirection

	static const int size = 5;
	int example2[size]; //compile-time known constant, error just int stack allocated arrays

	std::array<int, 5> another;

	Entity() {
		const int size2 = 5;
		int a[size2]; // 4 bytes x 5 = 20
		int count = sizeof(a) / sizeof(int); // 20 / 4 = 5

		//Usually recomended only for stack allocated arrays but not at all. u need to maintain manually that size

		

		int count = sizeof(example) / sizeof(int); // if u put example, thats a integer pointer thats why is 4 / 4 =  1



		for (int i = 0; i < size; i++)
			example[i] = 2;

		for (int i = 0; i < another.size(); i++)
			another[i] = 2;
	}
};
int main() {

	

	int example[5];
	/*
	example[0] = 2;
	example[4] = 4;

	std::cout << example[0] << std::endl;

	std::cout << example << std::endl;
	*/

	int* ptr = example;

	for (int i = 0; i < 5; i++) //dont use <= 4 because performance hit and < 5 is more readable such as 5 is same as array count 
		example[i] = 2;
	


	example[2] = 5; //writting an offset of 8 bytes from pointer

	*(ptr + 2) = 6; //thats how array pointer acts internally. Pointer arithmetic. The number of bytes depends on pointer data type. If u add + 2 it means u are adding 4 bytes 2 times = 8 bytes because the pointer is an integer and bumps up each 4 bytes of memory adress

	*(int*)((char*)ptr + 8) = 6; // same behaviour but with a char pointer which bumps up throught adress memory byte by byte. that why we add + 8 to reach third element. and then we can't write a int number within char pointer thats why we cast it back to integer pointer. Thats how arrays work

	int* another = new int[5]; //allocate memory on heap and not on stack like before

	for (int i = 0; i < 5; i++)
		another[i] = 2;


	delete[] another;

	
	Entity e;

	
	std::cin.get();
}