#include<stdio.h>

int main(){
    int n;
    printf("enter # of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter %d elements : ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    int max = arr[0], min = arr[0];
    
    for( int i = 0; i < n; i++){
        min = arr[i] < min ? arr[i] : min ;
        max = arr[i] > max ? arr[i] : max ;
    }
    printf("minimun : %d\nmaximum : %d",min,max);
    return 0;
}


/*
enter # of elements: 8
enter 8 elements : 15 81 61 58 2 03 47 25
minimun : 2
maximum : 81
*/
