#include <iostream>

//Const Usage:
              // 1: Variables to being constant vars
              // 2: Pointer to being constant to their contents or their mem adress
              // 3: classes and methods


class Entity {
private:
	int m_X, m_Y;
	int* m_P;
	mutable int m_Mutable; //debugging purposes. Can modify it inside const methods
public:
	int GetX() const // compiler treats methods as constant method. U can't modify anything inside the method. Just works with classes. Put const just for read.only usage
	{
		m_Mutable = 2;
		return m_X;
	}

	int GetX() // non-const func that makes the same but its call it for non-const params. A bit messy because 2 identical name methods
	{
		return m_X;
	}

	const int* const GetP() const //Promise we are returning a pointer that cant modify nothing and inside a method that promise cant modify entity class
	{
		return m_P;
	}


	void SetX(int x)
	{
		m_X = x;
	}

};

void PrintEntity(const Entity& e) // reference param because we dont want to copy and allocate in mem another 8 bytes. Thats make it slow and most likely for read-only functions. Second, we make param const because of that & we can modify the object itself and that can be dangerous for us. To take care of that we declared as const param. Besides, we enforce to make all entity methods we call it as const methods because we can't guarrantee that inside those methods entity e is not changing
{
	//e = Entity(); ERROR

	std::cout << e.GetX() << std::endl;//Therefore, just can call const methods 
}
int main()
{
	const int MAX_AGE = 90; //compiler treats this variable as read-only constant

	int* a = new int; //non-const pointer

	const int* a = new int; // can't modify the contents of that pointer

	int const* a = new int;// can't modify the contents of that pointer

	int* const a = new int;// can't modify the mem adress that pointer is pointing

	const int* const a = new int; //u can't modify nothing

	*a = 2;
	a = (int*)&MAX_AGE; //to bypass this read-only constant just cast it as int*. Thats how promise is broken

	std::cout << *a << std::endl;
	
	std::cin.get();
}