#include <iostream>
#include <array>

//Como podemos pasar como parametro una static array sin saber explicitamente su size?

template<typename T, std::size_t size>
void PrintArray(const std::array<T, size>& arr) {
	for (unsigned int i = 0; i < size; i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

//Static Array: same performance cost as raw array but with a bunch of debug features. Allocated on stack

int main() {

	std::array<int, 5> arr;
	arr[0] = 2;
	arr[4] = 3;

	std::cout << arr.size() << std::endl;

	PrintArray(arr);

	std::cin.get();
}