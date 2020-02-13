#include<stdio.h>
#include<string.h>

void printArr(int *a, int size){
	//Your code here
    printf("printArr: ");
    for(int i = 1; i<size+1; i++){
        printf("%d ", *(a+i));
    }
    printf("\n");
}

int* arrCopy(int *a, int size){
	//Your code here
    int tmp_arr [size];
    int *temp_arr = tmp_arr;
    for(int i = 1; i<size+1; i++){
        tmp_arr[i] = *(a+i);
    }
    return temp_arr;
}

int main(){
    int n;
    int *arr;
    int *arr_copy;
    int i;
    int p;
    printf("Enter size of array: \n");
    scanf("%d",&n);

    //Dynamically create an int array of n items
    //Your code here
    arr[n];

    //Ask user to input content of array
	//Your code here
    for(i = 1; i<n+1; i++){
        printf("Enter array content # %d: ", i);
        scanf("%d",&p);
        //increment position of mem location
        *(arr + i) = p;
    }
	
/*************** YOU MUST NOT MAKE CHANGES BEYOND THIS LINE! ***********/
	
	//Print original array
    printArr(arr, n);


	//Copy array
    arr_copy = arrCopy(arr, n);

	//Print new array
    printArr(arr_copy, n);

    return 0;
}