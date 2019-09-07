#include <iostream>
#include <variant>
#include <string>


enum class ErrorCode {
	None = 0, NotFound = 1, NoAccess = 2
};

std::variant<std::string, ErrorCode> ReadFileString()
{
	return {};
}

int main()
{
	std::variant<std::string, int> data;
	std::cout << sizeof(std::string) << "\n";
	std::cout << sizeof(int) << "\n";
	std::cout << sizeof(data) << "\n";
	data = "Cherno";
	data.index(); // 0 (string)
	std::cout << std::get<std::string>(data) << "\n";


	if (auto* value = std::get_if<std::string>(&data))
	{
		std::string& v = *value;
	}
	else {

	}

	data = 2;
	data.index(); // 1 (int)
	std::cout << std::get<int>(data) << "\n";
	std::cin.get();
}