// Preprocessor -> Preprocess to a file -> Yes (no genera obj files)

//Asembler language -> C++ -> output files -> Asm listing only

//Change Optimization -> C++ -> Optimization -> Maximum Speed & Code Generation ->Basic Runtime Checks->Default (code that compiler inserts for debugging)

const char* Log(const char* message) {
	return message;
}

int Multiply(int a, int b) {
	
	Log("Hello World");
	return a * b;
}

// hash Preprocessor 1: include
/*
int Multiply(int a, int b) {
	int result = a * b;
	return result;
#include "EndBrace.h"
*/

// hash Preprocessor 2: define
/*
#define INTEGER int

INTEGER Multiply(INTEGER a, INTEGER b) {
	INTEGER result = a * b;
	return result;
}
*/

// hash Preprocessor 3: if/endif
/*
#if 0
int Multiply(int a, int b) {
	int result = a * b;
	return result;
}
#endif
*/