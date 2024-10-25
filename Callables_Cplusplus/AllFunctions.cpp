#include "AllFunctions.h"

int square(int p) {
	return (p * p);
}

int add(int x, int y) {
	return x + y;
}

int multiply(int x, int y) {
	return x * y;
}

int multiplyForEach(int x) {
	return x * x;
}

void print(std::string x) {
	std::cout << x << std::endl;
}

void run() {
	std::cout << "Imma Runnin" << std::endl;
}

void walk() {
	std::cout << "Imma walkin" << std::endl;
}

void remapKey(void(*&btnToRemap)(), void(*btnAction)()) {
	btnToRemap = btnAction;
}

void display2(int p) {
	std::cout << p << "\t";
}

void printScores(const int scoresP[], int sizeP, Display displayP) {
	for (int i = 0; i < sizeP; i++) {
		displayP(scoresP[i]);
	}
	std::cout << "\n";
}

void displayString(std::string myStr) {
	const char* cStyleStr = myStr.c_str();
	std::cout << "C-style string: " << cStyleStr << std::endl;
	char* modifiableCopy = new char[myStr.length() + 1];
#ifdef _WIN32
	strcpy_s(modifiableCopy, myStr.length() + 1, myStr.c_str());
#else
	std::strncpy(modifiableCopy, myStr.c_str(), myStr.length());
#endif
	modifiableCopy[myStr.length()] = '\0';
	delete[] modifiableCopy;
}

void Display::operator()(int p) const {
	std::cout << p << "\t";
}