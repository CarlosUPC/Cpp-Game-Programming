#include <iostream>


class Entity
{
public:
	void Print() const { std::cout << "Hello!" << std::endl; }
};

class ScopedPtr
{
private:
	Entity* m_Obj;
public:
	ScopedPtr(Entity* entity)
		:m_Obj(entity){}

	~ScopedPtr()
	{
		delete m_Obj;
	}

	const Entity* GetObject() const { return m_Obj; }

	 Entity* operator->()
	{
		return m_Obj;
	}

	 const Entity* operator->() const
	 {
		 return m_Obj;
	 }

};

struct Vector3
{
	float x, y, z;
};

int main() {

	//Object
	Entity e;
	e.Print();

	//Pointer object
	Entity* ptr = &e;
	Entity& ref = *ptr; //dereferencing
	ref.Print();

	//Pointer object (cleaner way)
	Entity* ptr1 = &e;
	//(*ptr1).Print();
	ptr1->Print(); //Arrow: automate all instructions above

	const ScopedPtr entity = new Entity(); //implicit convention // same as Entity* ent = new Entity except manually delete keyword
	entity.GetObject()->Print(); // messy code
	entity->Print(); // overlading ->



	int offset = (int)&((Vector3*)nullptr)->x; //useful for serializing data into liek a stream of bytes and u want to figure out offsets

	std::cout << offset << std::endl;
	/*
	you cast a 0 into a Vector3*.now, since a pointer is a variable that stores a memory adress, it translates that into memory adress 00000000, so that's the adress it's now pointing to.now, when you try to use the -> operator to get the value of one of the variables of the object that the pointer is supposed to be pointing to, you get some kind of an error since there's actully no object being pointed to and therefore there's no value at the memory adress.
		however, even though there's no underlying object, a pointer to a class/struct still knows how an object of that class/struct is supposed to be structured in memory. so when you use the & to get the memory adress the variable is supposed to be stored at, instead of trying to get the data stored there, it actually returns a valid value .

		Since the only pieces of data this particular Vector3 object needs to store in memory are member variables X, Y and Z, the first variable, X is stored at the adress the pointer is pointing to, 00000000. Since all 3 data members are floats, and a float is 4 bytes, that means that X takes up memory adresses 00000000, 00000001, 00000002 and 00000003. Then 00000004 through 00000007 is Y and 00000008 through 00000011 is Z.But when you're returning the adress of a variable, you only get the adress where the 1st byte is stored and the rest of it is stored in the following adresses. And then you just cast it into an int to convert the adress value from hexadecimal to decimal and send to cout.
		*/

	std::cin.get();
}