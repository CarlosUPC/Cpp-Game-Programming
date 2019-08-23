#include <iostream>
#include <stdlib.h>
#include <string>

int main() {

	//string literals  are located in a section of mem which is read-only.  CHAR POINTERS AND ARRAY CHAR! but compiler generates a new variable that can be modify it. When we deal with char pointer, compiler can't generate that variable. The gist of this is that string literals are stored in a const segment of memory allways.

	const char name[8] = "Che\0rno";
	const char* name2 = "Cherno"; 
	//char* name = "Cherno" //Undefined behaviour. Never ever do this!

	//name2[2] = 'a'; // Can't modify 

	//ALL SIZE CHAR TYPES

	const char* n1 = u8"Cherno"; // 1 byte per char
	const wchar_t* n2 = L"Cherno"; // 2 bytes on windows, 4 bytes on linux and mac per char
	const char16_t* n3 = u"Cherno"; //2 bytes per char
	const char32_t* n4 = U"Cherno"; //4 bytes per char

	//APPENDING ALL SIZE CHAR TYPES
	using namespace std::string_literals;


	std::string sn1 = u8"Cherno"s + "hello";

	std::wstring sn2 = L"Cherno"s + L"hello";

	std::u16string sn3 = u"Cherno"s + u"hello";

	std::u32string sn4 = U"Cherno"s + U"hello";

	//IGNORE ENTER CARACTERS (/n)
	const char* example = R"(cherno cherno cherno cherno
cherno cherno cherno cherno
cherno cherno cherno cherno
cherno cherno cherno cherno)";

	const char* example2 = "hello world\ncarlos";

	std::cout << strlen(name) << std::endl;
	std::cout << name2 << std::endl;
	std::cout << example << std::endl;
	std::cout << example2 << std::endl;

	std::cin.get();
}