#include <iostream>
#include <utility>
#include <math.h>
using namespace std;

bool miller_rabin(int a, int nk, int n) {
	if (n < 1) {
		return false;
	}
	else if ((pow(a, nk) != -1) || (pow(a, nk) != 1)) {
		return false;
	}
	else if ((pow(a, nk) == 1) && fmod(nk,2) == 0) {
		return miller_rabin(a, nk / 2, n);
	}
	else return true;
}

bool primality_test(int n) {    // this algorithm works for n>3
	double a = 0;
	while (a < 2 || (fmod(a, n) == 0 && n > 4)) {
		a = rand() % (n-2);
	}
	int b = 0;
	b = fmod(pow(a, (n - 1)), n);
	if (n < 2 || n%2 ==0 || fmod(pow(a, (n - 1)), n) != 1) {
		return false;
	}
	else if (fmod(n, 2) == 0) {
		return miller_rabin(a, (n - 1)/2, n);
	}
	else return true;
}

int main() {
	double p = 15;

	cout << primality_test(p);
	return 0;
}
