
#include <iostream>
#include <cstring>
#include <vector>
#include <array>
#include "AllFunctions.h"
using std::cout;
enum class UserChoice { ADD = 1, MULTIPLY = 2 };
template<typename T>
using Test = bool(*)(const T&, const T&);

//The asterisk (*) in using Test = bool(*)(const T&, const T&);
// indicates that Test is a type alias for a pointer to a function. 
// This function takes two parameters of type const T& (constant references to objects of type T)
// and returns a bool.


template<typename T>
bool lessThan(const T& operand1, const T& operand2) {
	if (operand1 < operand2) {
		return true;
	}
	else {
		return false;
	}
}
template <typename T>
bool greaterThan(const T& operand1, const T& operand2) {
	if (operand1 > operand2) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
void compare(T operand1, T operand2, Test<T> fp_comparator) {
	if (fp_comparator(operand1, operand2)) {
		cout << "TRUE" << std::endl;
	}
	else {
		cout << "FALSE" << std::endl;
	}
}

template <typename T>
T getElement(const T scoresP[], int sizeP, Test<T> fpAlias_func) {
	T element = scoresP[0];
	for (int i = 0; i < sizeP; i++) {
		if (fpAlias_func(scoresP[i], element)) {
			element = scoresP[i];
		}
	}
	return element;
}
template <typename T>
T middle(const T scoresP[], int sizeP) {
	T mid = sizeP / 2;
	if (sizeP % 2 == 0) {
		// Even number of elements
		// Return the average of the two middle elements
		return (scoresP[mid - 1] + scoresP[mid]) / 2.0;
	}
	else {
		// Odd number of elements
		// Return the middle element
		return scoresP[mid];
	}
	T element = scoresP[mid];
	return element;
}
template<typename T>
T increment(T p) {
	return (p + p);
}

template<typename T>
void modifyElements(T elements[], int sizeP, T(*fp_modify)(T)) {
	for (int i = 0; i < sizeP; i++) {
		elements[i] = fp_modify(elements[i]);
	}
}

int main()
{
	const int SIZE = 6;
	int x{ 200 }, y{ 300 };
	int points[SIZE]{ 5,10,15,20,25,30 };
	modifyElements(points, SIZE, multiplyForEach);
	Display dis;
	printScores(points, SIZE, dis);

	compare(x, y, lessThan);
	compare(x, y, greaterThan);

	int greatestPoint = getElement(points, SIZE, greaterThan);
	int leastGreatest = getElement(points, SIZE, lessThan);
	int isMiddle = middle(points, SIZE);

	for (int p : points) {
		std::cout << p << " ";
	}
	cout << "\n";
	cout << "Greatest: " << greatestPoint << "\t";
	cout << "Least: " << leastGreatest << "\t";
	cout << "Middle: " << isMiddle << "\n";

	return EXIT_SUCCESS;
}


