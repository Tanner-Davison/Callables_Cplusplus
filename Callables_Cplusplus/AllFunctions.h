#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

int square(int p);
int add(int x, int y);
int multiply(int x, int y);
int multiplyForEach(int x);
void print(std::string x);

void run();
void walk();

void remapKey(void(*&btnToRemap)(), void(*btnAction)());

void display2(int p);

class Display {
public:
	void operator()(int p)const;
};


void printScores(const int scoresP[], int sizeP, Display displayP);

void displayString(std::string myStr);

template <typename T>
void printSortedVec(const std::vector<T>& scoresP)
{

	std::cout << "Vector Size: " << scoresP.size() << std::endl;
	for (const auto& score : scoresP) {
		std::cout << score << " ";
	}
	std::cout << "\n";
}