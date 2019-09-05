#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
//Lambda: anonymous function that define a body without having define a body 



void ForEach(const std::vector<int>& values, const std::function<void(int)>& func)
{
	for (int value : values)
		func(value);
}

int main()
{
	
	std::vector<int> values = { 1,5,4,2,3 };
	int a = 5;
	auto lambda = [a](int value) mutable {a = 6; std::cout << "Value: " << a << std::endl; };
	ForEach(values, lambda); 

	auto it = std::find_if(values.begin(), values.end(), [](int value) {return value > 3; }); //quicker bool func. avoid extrafunc creation
	std::cout << *it << std::endl;
	std::cin.get();
}