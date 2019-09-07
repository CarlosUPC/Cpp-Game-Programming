#include <iostream>
#include <fstream>
#include <string>
#include <optional>

//Optional: c++ feature used to deal when data is may present or may not like files
std::optional<std::string> ReadFileAsString(const std::string& filepath) 
{
	std::ifstream stream(filepath);

	if (stream) {
		std::string result;
		//read file
		stream.close();
		return result;
	}


	return {};
}
int main() {

	std::optional<std::string> data = ReadFileAsString("data.txt");

	std::string value = data.value_or("Not present");

	if (data.has_value()) {
		std::cout << "file read succesfully" << std::endl;
		std::string& value = data.value();
		//std::string& value = *data;
		std::cout << value << std::endl;
	}
	else
	{
		std::cout << "file read failed" << std::endl;
	}

	std::cin.get();
}