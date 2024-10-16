
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

	void(*dis)(int x) = display;

	const int ARRSIZE = 5;
	int scores[ARRSIZE] = { 34,52,81 };
	printScores(scores, ARRSIZE, dis);

	return EXIT_SUCCESS;
}


