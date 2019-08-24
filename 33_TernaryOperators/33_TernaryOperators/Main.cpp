#include <iostream>
#include <string>

static int s_Level = 1;
static int s_Speed = 2;

//TERNARY OPERATOR: a bit better and faster than if statementsbut not so much

//NESTED TERNARY OPERATORS: avoid them xD

int main() {

	//Normal statement
	if (s_Level > 5)
		s_Speed = 10;
	else
		s_Speed = 5;

	//Ternary operator
	s_Speed = s_Level > 5 ? 10 : 5;

	//Ternary operator with strings
	std::string rank = s_Level > 10 ? "Master" : "Beginner";

	//Nested Ternary operators
	s_Speed = s_Level > 5 ? s_Level > 10 ? 15 : 10 : 5;
	//Nested Ternary operators with other logical operators
	s_Speed = s_Level > 5 && s_Level < 100 ? s_Level > 10 ? 15 : 10 : 5;

	std::cin.get();
}