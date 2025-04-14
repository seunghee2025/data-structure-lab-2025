#include <cstdio>

int findArrayMax(int score[], int n) {

	int tmp = score[0];
	for (int i = 0; i < n; i++) {
		if (score[i] > tmp) {
			tmp = score[i];
		}
	}
	return tmp;
}

void main() {
	int A[6] = { 3,7,2,9,10,5 },
		B[3] = { -10,-5,-3 },
		C[5] = { 100,200,300,50,400 },
		D[4] = { 0,0,-2,0 },
		E[1] = { 10000 };

	int out;
	out = findArrayMax(A, 6);
	printf("%d\n", out);
	out = findArrayMax(B, 6);
	printf("%d\n", out);
	out = findArrayMax(C, 6);
	printf("%d\n", out);
	out = findArrayMax(D, 6);
	printf("%d\n", out);
	out = findArrayMax(E, 6);
	printf("%d\n", out);
}