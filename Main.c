#include "Test_Gauss.h"
#include "stdio.h"
#include "Gauss.h"
#include <malloc.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>


void printAns(double* array, int size) {
	for (int i = 0; i < size; i++)
		printf("%.10lf ", array[i]);
	printf("\n\n");
}


int main() {
	printf("Enter the matrix size:");
	int n;
	scanf_s("%d", &n);
	double *array= malloc(sizeof(double)*(uint64_t)n* ((uint64_t)n+1));
	struct matrix a = {n+1, n, array};
	double* Ans = malloc(sizeof(double) * n );
	double* aNS = malloc(sizeof(double) * n);
	aNS = real_answer(aNS, n, 670);
	new_matrix(&a, aNS, 677);
	//printTEST(a);
	printf("\n");
	//printAns(aNS, n);
	clock_t speed = clock();
	Ans = gauss(&a, Ans);
	speed = clock() - speed;
	printf("Time kvants: %d\n", (int)speed);
	compare(aNS, Ans, n);
	//printAns(aNS, n);
	return 0;
}
