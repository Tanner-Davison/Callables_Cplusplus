#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>

class Display {
public:
	void operator()(int p) const;
};

int square(int p);
int add(int x, int y);
int multiply(int x, int y);
int multiplyForEach(int x);
void print(std::string x);
void run();
void walk();
void remapKey(void(*&btnToRemap)(), void(*btnAction)());
void display2(int p);
void printScores(const int scoresP[], int sizeP, Display displayP);
void displayString(std::string myStr);