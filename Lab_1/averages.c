#include <stdio.h>
#include <stdlib.h>
int main(){
    int pos_avg = 0;
    int num_pos = 0;
    int neg_avg = 0;
    int num_neg = 0;
    int neg_sum = 0;
    int pos_sum = 0;
    int num = 1;

    while(num != 0){
        printf("Please enter an interger: ");
        scanf("%d", &num);
        if(num < 0){
            num_neg++;
            neg_sum= neg_sum + num;
        }
        else if(num > 0){
            num_pos++;
            pos_sum = pos_sum + num;
        }
    }

    if(num_pos == 0){
        neg_avg = neg_sum/num_neg;
        printf("Negative average: %d", neg_avg);
    }
    else if(num_neg == 0){
        pos_avg = pos_sum/num_pos;
        printf("Postive average: %d", pos_avg);
    }
    else{
        pos_avg = pos_sum/num_pos;
        neg_avg = neg_sum/num_neg;
        printf("Postive average: %d \n", pos_avg);
        printf("Negative average: %d \n", neg_avg);
    }

    return 0;
}