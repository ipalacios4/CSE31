
#include <stdio.h>
#include <malloc.h>

int** matMult(int **a, int **b, int size){
	// (4) Implement your matrix multiplication here. You will need to create a new matrix to store the product.
	int **mult;
	int i =0, j = 0;
	for(i; i<size; i++){
		for(j; j<size; j++){
			*(*(mult+i)+j) = (*(*(a+i)+j))*(*(*(b+i)+j));
		}
	}
	return mult;


}

void printArray(int **arr, int n){
	// (2) Implement your printArray function here
	int i = 0, j = 0;
	for(i; i<n; i++){
		for(j; j<n; j++){
			printf("%d\t",*(*(arr+i)+j));
		}
		printf("\n");
	}
	printf("\n");

}

int main() {
	int n = 5;
	int **matA, **matB, **matC;
	// (1) Define 2 n x n arrays (matrices). 
	matA = (int**)malloc(n * sizeof(int*));
	matB = (int**)malloc(n * sizeof(int*));

	// (3) Call printArray to print out the 2 arrays here.
	printArray(matA, n);
	printArray(matB, n);
	
	//(5) Call matMult to multiply the 2 arrays here.
	matC = matMult(matA, matB, n);

	//(6) Call printArray to print out resulting array here.
	printArray(matC, n);


    return 0;
}