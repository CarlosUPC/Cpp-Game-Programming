#include <iostream>


class Entity
{
public:
	float X, Y;

	Entity() { 
		std::cout << " Created Entity" << std::endl;
		X = 0.0f;
		Y = 0.0f;
	}

	~Entity() { //Applied on both stack-scope and heap-scope cases. When scope function ends, this function is called and clean up all memory allocated to prevent memory leaks. When use the keyword delete this special function is called too

		std::cout << " Destroyed Entity" << std::endl;
	}

	Entity(float x, float y) { 
		X = x;
		Y = y;
	}

	

	void Print()
	{
		std::cout << X << " , "
			<< Y << std::endl;
	}

};

void Function() {
	Entity e;
	e.Print();
	e.~Entity(); //rarely usage. Not recomended. If u allocated mem on heap manually u need to deallocate mem memory using delete but dont need to call de destructor. Same with constructor.
}

int main()
{
	 
	Function();
	std::cin.get();
}