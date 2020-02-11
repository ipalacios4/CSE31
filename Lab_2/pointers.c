#include <stdio.h>
int main(){
    int x, y, *px, *py;
    int arr[10];
    // printf("%d", x);
    // printf("%d", y);
    // printf("%d", arr[0]);

    // printf("%p \n", &x);
    // printf("%p \n", &y);

    // px = &x;
    // py = &y;

    // printf("%p\n", px);
    // printf("%d\n", *px);
    // printf("%p\n", py);
    // printf("%d\n", *py);

    for(int i = 0; i<10; i++){
        printf("%d\n", *(arr+i) );
        printf("%p\n", arr + i);
    }

    printf("%p\n", arr);

    return 0;
}