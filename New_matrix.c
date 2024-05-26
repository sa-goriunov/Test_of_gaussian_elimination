#include "Gauss.h"
#include "Test_Gauss.h"

double* real_answer(double* array, int size, int max) {
	for (int i = 0; i < size; i++)
		array[i] = UltimateRandom(max);
	return array;
}

void new_matrix(struct matrix* a, double* answer, int max) {
	for (int i = 0; i < a->strings; i++) {
		a->array[(i+1) * a->columns  - 1] = 0;
		for (int j = 0; j < a->columns - 1; j++) {
			a->array[i * a->columns + j] = UltimateRandom(max);
			a->array[(i + 1) * a->columns - 1] += a->array[i * a->columns + j] * answer[j];
		}
	}
}