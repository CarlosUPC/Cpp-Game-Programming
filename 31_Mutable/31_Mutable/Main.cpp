#include <iostream>
#include <string>

class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCount = 0;
public:
	const std::string& GetName() const
	{
		m_DebugCount++;
		return m_Name;
	}

};

int main() {

	const Entity e;
	e.GetName();

	//Lambda case:
	int x = 8;

	auto f = [=]() mutable
	{
		x++;
		std::cout << x << std::endl;
	};

	f(); //lambda func
	// x = 8 cause was param value capture list =


	std::cin.get();
}