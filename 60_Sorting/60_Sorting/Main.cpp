#include <iostream>
#include <vector>
#include <algorithm>

//U can build buuble sort or quick sort by ur own but if u are dealing with std data structures like vector or array then use std sorting

int main() {

	std::vector<int> values = { 3,5,1,4,2 };
	std::sort(values.begin(), values.end()); //sorting by operator< (no predicator)

	for (int value : values)
		std::cout << value << std::endl;

	std::sort(values.begin(), values.end(), std::greater<int>()); //sorting by a predicator

	for (int value : values)
		std::cout << value << std::endl;

	std::sort(values.begin(), values.end(), [](int a, int b) 
	{
		if (a == 1)
			return false;
		if (b == 1)
			return true;

		return a < b; //by comp with lambda, read std::sort cppreference for more details
	});

	std::cin.get();
}