#include <stdio.h>
#include <malloc.h>

void printArray(int**, int);

int main() {
	int i = 0, j = 0, n = 5;
	int **arr = (int**)malloc(n * sizeof(int*));

	// (3) Add your code to complete allocating and initializing the 2-D array here. The content should be all 0.



    // This will print our your array
	printArray(arr, n);

    // (6) Add your code to make arr a diagonal matrix
    
	
	
	// (7) All printArray to print array
    printArray(arr, n);

	return 0;
}

void printArray(int ** array, int size){
    // (5) Implement your printArr here:



}
