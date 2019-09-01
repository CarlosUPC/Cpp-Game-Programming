#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <array>
#include <vector>
#include <utility>
#include <functional>

//Reference: u need to pass in a valid variable
void MultipleValuesRef(std::string& str1, std::string& str2)
{
	std::stringstream ss[2];

	std::string vs = ss[0].str();
	std::string fs = ss[1].str();

	str1 = vs;
	str2 = fs;

}

//Pointer: u can pass in a null or valid variable 
void MultipleValuesPtr(std::string* str1, std::string* str2)
{
	std::stringstream ss[2];

	std::string vs = ss[0].str();
	std::string fs = ss[1].str();

	if(str1)
		*str1 = vs;

	if(str2)
		*str2 = fs;

}

//Array of string pointer
std::string* MultipleValuesString()
{
	std::stringstream ss[2];

	std::string vs = ss[0].str();
	std::string fs = ss[1].str();

	return new std::string[]{ vs, fs };

}

//std::array allocated on stack, faster
std::array<std::string,2> MultipleValuesArray()
{
	std::stringstream ss[2];

	std::string vs = ss[0].str();
	std::string fs = ss[1].str();

	std::array<std::string, 2> output;

	output[0] = vs;
	output[1] = fs;

	return output;
}


//vector allocated on heap, less fast
std::vector<std::string> MultipleValuesVector()
{
	std::stringstream ss[2];

	std::string vs = ss[0].str();
	std::string fs = ss[1].str();

	//One way
	std::vector<std::string> output;

	output.push_back(vs);
	output.push_back(fs);

	//Second Way
	std::vector<std::string> output(2);
	output[0] = vs;
	output[1] = fs;

	return output;
}

std::tuple<std::string, std::string> MultipleValuesTuple()
{
	std::stringstream ss[2];

	std::string vs = ss[0].str();
	std::string fs = ss[1].str();

	

	return std::make_pair(vs,fs);
}

std::pair<std::string, std::string> MultipleValuesPair()
{
	std::stringstream ss[2];

	std::string vs = ss[0].str();
	std::string fs = ss[1].str();

	

	return std::make_pair(vs, fs);
}

struct MultipleValues
{
	std::string NameString1;
	std::string NameString2;
};

MultipleValues MultipleValuesStruct()
{
	std::stringstream ss[2];

	std::string vs = ss[0].str();
	std::string fs = ss[1].str();

	

	return { vs, fs };
}
int main() {

	std::string vs, fs;
	MultipleValuesRef(vs,fs);

	MultipleValuesPtr(&vs, nullptr);

	std::string* source = MultipleValuesString(); //annoying cause we dont know how big it is, its a pointer. a wiser way is using std::array

	std::array<std::string, 2> input = MultipleValuesArray();


	std::vector<std::string> Vecinput = MultipleValuesVector();

	std::tuple<std::string, std::string> tupleSource = MultipleValuesTuple();


	//Horrendous. u cant know which one is each of them. doesnt make sense
	std::string tupleVar1 = std::get<0>(tupleSource);
	std::string tupleVar2 = std::get<1>(tupleSource);


	std::pair<std::string, std::string> pairSource = MultipleValuesPair();

	//little bit better but we dont know what the variable are. whats first and second?
	std::string pairVar1 = pairSource.first;
	std::string pairVar2 = pairSource.second;
	
	//Optimal and Cleaner Way STRUCTS!
	auto structSource = MultipleValuesStruct();

	structSource.NameString1;
	structSource.NameString2;

	std::cin.get();
}