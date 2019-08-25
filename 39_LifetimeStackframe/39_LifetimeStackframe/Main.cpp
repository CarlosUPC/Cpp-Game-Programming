#include <iostream>

//Stack base variables: goes out of scope and gets destroyed is actually useful. For instance, a timer for benchmarking or mutex lock 
class Entity
{
public:
	Entity()
	{
		std::cout << "Created Entity!" << std::endl;
	}

	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
};

int* CreateArrayStack()
{
	int array[50];
	//1 Way to resolve:
	int* array = new int[50]; //heap mem
	return array;
}

// 2 Way to resolve:
void FilledArray(int* a)
{
	//Filled array
}

class ScopedPtr
{
private:
	Entity* m_Ptr;
public:
	ScopedPtr(Entity* ptr)
		: m_Ptr(ptr){}
	ScopedPtr()
	{
		delete m_Ptr;
	}

};
int main()
{
	int arr[50]; //Good code
	FilledArray(arr);


	int* a = CreateArrayStack(); //bad code cause array pointer is cleaned up when func scope ends

	{ //Empty scope/stack frame

		Entity s_e; //mem freed when scope ends
		Entity* h_e = new Entity(); //mem freed by operating system when program ends
	}

	{
		//ScopedPtr smart_ptr(new Entity()); //Explicit convention


		ScopedPtr smart_ptr = new Entity(); //Implicit convention // allocates Entity obj in heap mem and returns his entity pointer to scopedptr constructor


	} //when scope ends frees smart_ptr and calls destructor


	std::cin.get();
}