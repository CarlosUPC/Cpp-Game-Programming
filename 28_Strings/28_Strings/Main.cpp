#include <iostream>
#include <string>


void PrintString(const std::string& string) { //copying a string on heap make slow operations so take care to use const& to make it read-only
	std::cout << string << std::endl;
}
int main() {

	//ALL CHAR TYPES

	// Char
	char ch = 'A';

	// Char array
	char var[7] = { 'c', 'h', 'e', 'r', 'n', 'o' , 0}; //fixed size (manually)
	 char var1[] = "cherno"; //unknown size (compiler fixed it)

	 // String 
	 const char* var2 = "cherno"; //inmutable , unknown size (compiler fixed it)
	                              //const: string data size is allocated in mem so u cant modify the size. To do this, u need to delete te mem allocated and create  new brand data to allocate it 


	 //String array
	 const char* arr[3] = { "carlos","ferran", "asier" };

	 //Standart strings
	 std::string str = "cherno";
	 strlen(str.c_str());
	 strlen(var2);
	 strlen(var1);
	 strlen(var);

	 str.size();

	 //String appending
	 std::string str2 = "cherno"; // 1 way
	 str2 += "hello";
	  
	 std::string str3 = std::string("cherno") + "hello"; // 2 way

	 //Find characters in strings
	 bool contains = str2.find("no") != std::string::npos; //illegal position (outside mem allocation)

	ch = 'b'; //mutable char
	var[2] = 'a'; //mutable char
	var1[2] = 'a'; //mutable char
	//var2[2] = 'b'; //inmutale string //all string are const
	//arr[3][2] = 'a'; //inmutale string //all string are const

	std::cout << var << std::endl;
	std::cout << var1 << std::endl;
	std::cout << var2 << std::endl;
	std::cout << str << std::endl;


	PrintString(str);
	std::cin.get();
}