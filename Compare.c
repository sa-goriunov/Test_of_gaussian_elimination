#include "Test_Gauss.h"
#include <math.h>
#include <stdio.h>

int compare(double* arr1, double* arr2, int number) {
	double max = 0, sum = 0;
	//FILE* stream; errno_t err;
	//err = fopen_s(&stream, "Test.txt", "w");
	for (int i = 0; i < number; i++) {
		double error = arr2[i] - arr1[i];
		//fprintf(stream, "%40.30le %40.30le %40.30le\n", arr1[i], arr2[i], error);
		//printf("%le %le\n", arr1[i], arr2[i]);
		sum += error;
		if (error > max) max = error;
	}
	printf("Mean error: %40.30le\nMax error: %40.30lf", sqrt(sum/number), max);
	return 0;
}