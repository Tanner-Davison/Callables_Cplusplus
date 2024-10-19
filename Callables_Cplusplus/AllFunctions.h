#pragma once
#include <iostream>

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
void printScores(const int scoresP[], int sizeP, Display display);
void displayString(std::string myStr);

