#include <iostream>

#define LOG(x) std::cout << x << std::endl;

int main() {

	for (int i = 0; i < 5; i++) {

		/*if (i % 2 == 1)  //CONTINUE STATEMENT
			continue;*/

		/*if (i % 2 == 1)  //BREAK STATEMENT
			break;*/

		if (i % 2 == 1)    //RETURN STATEMENT
			return 0;

		LOG("Hello World");
		LOG(i);

	}

	std::cin.get();
}