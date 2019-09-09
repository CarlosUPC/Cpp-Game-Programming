#include <iostream>
#include <string>


//Big diff: allocation
//Stack: 1 CPU Instruction
//Heap: whole thing -> operator new takes so much time
//new operator: calls malloc function that which calls a specific platform function from operative system to search free list of memory to allocate mem, if the mem requested is bigger than the free list the program ask to OS for more memory and thats expensive and take time
//Stack allocation: all data is allocated in a row split it by a guard bytes to prevent overflowing
//heap allocation: malloc search for free list, so each block of mem is allocated randomly and for access into them, expensive job
//always use stack
//use heap when u need a non-scope-based lifetime, if there isnt stack mem,or u need more data like 20 megabytes to allocate

//stack allocation: allocated together, so they can fit onto one cpu cache line. we wouldnt get any cache misses
//heap allocation: a bit cache misses we would get

//The CPU has several levels of caches that are much faster than ram on the motherboard, but the kind of memory is more expensive and has to fit in the CPU, so there is a lot less of it.  When data is used accessed it will load the whole area of memory to the cache.  If the next data it needs is in the same area it will already be loaded.  If not you have a cache miss, so it has to load more from ram to cache, and that's slow.  Basically when you have a cache miss the CPU has to sit on idle while waiting for the data -- if it was already in the cache it could just keeps going.  It could make things 50 or 100 times slower if you have constant misses versus very few (if there is much data some will happen since only so much is moved at once).  This is an advantage of arrays over linked lists -- linked lists cause lots of misses, which makes them much slower than arrays even at things they're better at in theory.  That's simplified a bit, since different level of cache do have different speeds too, but that should give you the general idea.
struct Vector3
{
	float x, y, z;
	Vector3()
		:x(10), y(11), z(12){}
};



int main()
{
	//Stack allocation
	int value = 5;

	int array[5];

	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	array[3] = 4;
	array[4] = 5;

	Vector3 vec;

	//Heap allocation
	int* hvalue = new int;
	*hvalue = 5;

	int* harray = new int[5];

	Vector3* hvec = new Vector3();
	std::cin.get();

	delete hvalue;
	delete[] harray;
	delete hvec;
}