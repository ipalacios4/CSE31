
#include <stdio.h>
#include <malloc.h>

int** matMult(int **a, int **b, int size){
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
	int **mult = (int**)malloc(size*sizeof(int*));
	int i =0, j = 0, k = 0;

	for(i = 0; i<size; i++){
		*(mult+i) = (int*)malloc(size*sizeof(int));
		for(j = 0; j<size; j++){
			*(*(mult+i)+j) = 0;
			for(k = 0; k<size; k++){
				*(*(mult+i)+j) += *(*(a+i)+k)* (*(*(b+k)+j));
			}
		}
	}
	return mult;


}

void printArray(int **arr, int n){
	// (2) Implement your printArray function here
	int i = 0, j = 0;

	for(i = 0; i<n; i++){
		for(j = 0; j<n; j++){
			printf("%d\t",*(*(arr+i)+j));
		}
		printf("\n");
	}
	printf("\n");

}

int main() {
	int n = 3, i = 0, j = 0;
	int **matA, **matB, **matC;
	// (1) Define 2 n x n arrays (matrices). 
	matA = (int**)malloc(n * sizeof(int*));
	matB = (int**)malloc(n * sizeof(int*));
	for(i = 0; i<n; i++){
		*(matA+i) = (int*)malloc(n * sizeof(int));
		*(matB+i) = (int*)malloc(n * sizeof(int));
		for(j = 0; j<n; j++){
			*(*(matA+i)+j) = (rand() % n)+1;
			*(*(matB+i)+j) = (rand() % n)+1;
		}
	}
	

	// (3) Call printArray to print out the 2 arrays here.
	printArray(matA, n);
	printArray(matB, n);
	
	//(5) Call matMult to multiply the 2 arrays here.
	matC = matMult(matA, matB, n);

	//(6) Call printArray to print out resulting array here.
	printArray(matC, n);


    return 0;
}