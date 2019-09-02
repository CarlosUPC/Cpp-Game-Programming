#include <iostream>
#include <string>

//Macros: text replacers, before compilation time, at preprocessor time

//Backslash: like a scaping key

#define MACRO
#define MACRO 0 //better with a value cause u dont need to comment or remove the macro, just change value to 0 or 1


//One Way
/*
#ifdef PR_DEBUG
#define WAIT std::cin.get()
#define LOG(x) std::cout << x << std::endl;
#elif PR_RELEASE
#define WAIT
#define LOG(x)
#endif
*/

//Second Way

#if PR_DEBUG == 1 //clearer way
#define WAIT std::cin.get()
#define LOG(x) std::cout << x << std::endl;
#elif defined(PR_RELEASE)
#define WAIT
#define LOG(x)
#endif


int main()
{
	LOG("Hello!");
	WAIT;
}