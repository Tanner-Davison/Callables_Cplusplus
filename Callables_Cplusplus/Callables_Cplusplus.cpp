
#include <iostream>

int square(int p) { return (p * p); }
int add(int x, int y) { return x + y; }
int multiply(int x, int y) { return x * y; }

void run() { std::cout << "Imma Runnin" << std::endl; }
void walk() { std::cout << "Imma walkin" << std::endl; }
void remapKey(void(*&btnToRemap)(), void(*btnAction)()) { btnToRemap = btnAction; }

void display(int p) {
	std::cout << p << std::endl;
}
void display2(int p) {
	std::cout << p << "\t";
}
void printScores(const int scoresP[], int sizeP, void(*&fp_display)(int xP)) {
	for (int i = 0; i < sizeP; i++) {
		fp_display(scoresP[i]);
	}
}

int main()
{

	void (*fp_upArrowBtn)() = walk;
	//register up btn;
	remapKey(fp_upArrowBtn, run);

	fp_upArrowBtn();
	fp_upArrowBtn();

	void(*dis)(int x) = display2;
	void(*dis1)(int x) = display;

	const int ARRSIZE = 5;
	int scores[ARRSIZE] = { 34,52,81 };

	printScores(scores, ARRSIZE, dis1);
	printScores(scores, ARRSIZE, dis);

	//array of function pointers

	int(*fp_arr[])(int, int) = { add, multiply };
	int x{}, y{}, choice{};

	std::cout << "Enter 2 Numbers";
	std::cin >> x >> y;

	std::cout << "Enter 0 to add, 1 to multiply";
	std::cin >> choice;

	std::cout << (*fp_arr[choice])(x, y) << std::endl;

	return EXIT_SUCCESS;
}


