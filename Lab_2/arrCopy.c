#include<stdio.h>
#include<string.h>

void printArr(int *a, int size){
	//Your code here
}

int* arrCopy(int *a, int size){
	//Your code here
}

int main(){
    int n;
    int *arr;
    int *arr_copy;
    int i;
    printf("Enter size of array:\n");
    scanf("%d",&n);

    //Dynamically create an int array of n items
    //Your code here

    //Ask user to input content of array
	//Your code here
	
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	//Print original array
    printArr(arr, n);


	//Copy array
    arr_copy = arrCopy(arr, n);

	//Print new array
    printArr(arr_copy, n);

    return 0;
}