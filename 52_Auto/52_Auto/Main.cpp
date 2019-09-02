#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
std::string GetName()
{
	return "Cherno";
}

class Device {};

class DeviceManager {
private:
	std::unordered_map<std::string, std::vector<Device*>> m_Device;

public:
	const std::unordered_map<std::string, std::vector<Device*>>& GetDevices() const {
		return m_Device;
	}
};
int main() {

	auto name = GetName(); //Pro: u can modify API functions and dont need to change data types on client-server like thaat

	int a = name.size(); //Contr: if u change API functions, maybe can have a break code like in this case cause .size() is a method from string constructor


	std::vector<std::string> strings;
	strings.push_back("Apple");
	strings.push_back("Orange");

	
	//Useful case to use Auto keyword
	for (/*std::vector<std::string>::iterator*/auto it = strings.begin(); it != strings.end; it++) {
		std::cout << *it << std::endl;
	}

	//Alternatives to avoid Auto keyword
	using DeviceMap = std::unordered_map<std::string, std::vector<Device*>>;

	typedef std::unordered_map<std::string, std::vector<Device*>> DeviceMap;


	//Another useful case to use auto keyword
	DeviceManager dm;
	/*const std::unordered_map<std::string, std::vector<Device*>>& devices = dm.GetDevices();*/

	const auto& devices = dm.GetDevices();

	std::cin.get();
}