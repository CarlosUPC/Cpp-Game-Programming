#include <iostream>

class Base
{
public:
	Base() { std::cout << "Base Constructor" << std::endl; }

	virtual ~Base() { std::cout << "Base Destructor" << std::endl; }
};

class Derived : public Base
{
public:
	Derived() { m_Array = new int[5]; std::cout << "Derived Constructor" << std::endl; }

	~Derived() { delete[] m_Array; std::cout << "Derived Destructor" << std::endl; }

private:
	int* m_Array;
};


class AnotherClass : public Base
{
public:
	AnotherClass() {  std::cout << "AnotherClass Constructor" << std::endl; }

	~AnotherClass() {  std::cout << "AnotherClass Destructor" << std::endl; }

};

int main()
{
	double value = 5.25;
	double a = (int)value + 5.3;
	std::cout << a << std::endl;

	double s = static_cast<int>(value) + 5.3; //static has more features like compile time checks for error/not valid conversion

	/*double s_invalid = static_cast<AnotherClass*>(value) + 5.3;*/

	Derived* derived = new Derived();
	Base* base = derived; //casted to base

	//base is an derived or ac instance?

	AnotherClass* ac1 = dynamic_cast<AnotherClass*>(base);//dynamic has more features like compile time checks for error/not valid conversion -- NULL ptr

	Derived* ac2 = dynamic_cast<Derived*>(base);//Works succesfully

	std::cin.get();
}