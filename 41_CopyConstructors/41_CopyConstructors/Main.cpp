#include <iostream>
#include <string>

//Copy constructors: useful for the case when u copy pointers, stright away u are copying its adress mem. thus, 2 pointers are pointing same data. When that data is freed by one pointer gets deleted, another is still pointing to that adress and when is deleted, this adress mem is freed again. so, the mem is freed twice and this gets an compiler error from wntd.dll not loaded


class String
{
private:
	char* m_Buffer;
	unsigned int m_Size;

public:
	String(const char* string)
	{
		m_Size = strlen(string);
		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, string, m_Size);
		m_Buffer[m_Size] = 0;
	}

	String(const String& other) // default signature of copy constructors, this definition means a copy mem from a variable of same data type
		:m_Size(other.m_Size) 
	{
		std::cout << "Copied String" << std::endl;

		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
		
	}

	//String(const String& other) = delete; //Another way is forbidding copy constructors like unique pointers do

	~String()
	{
		delete[] m_Buffer;
	}


	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
	


};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}


void PrintString(const String& string)
{
	std::cout << string << std::endl;
}

int main()
{
	String string("Cherno");
	String second(string);
	second[2] = 'a';

	PrintString(string);
	PrintString(second);
	

	std::cin.get();
}