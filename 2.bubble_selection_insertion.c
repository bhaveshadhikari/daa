#include<stdio.h>

void bubbleSort(int arr[],int size){
    for (int i = 0; i < size; i++){ 
        int altered = 0 ; 
        for (int j = 0; j < size-i-1; j++)
            if (arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                altered = 1;
            }
        if (altered==0)
            break;
    }
    printf("\nBubble Sort : ");
    for (int i = 0; i < size; i++)
        printf("%d  ", arr[i]);
}

void selectionSort(int arr[],int size){
    for (int i = 0; i < size-1; i++)
    {
        int min_index = i;
        for (int j = i+1; j < size; j++)
            if (arr[j]<arr[min_index])
                min_index = j;

        if (min_index != i){
            int temp = arr[i];
            arr[i]=arr[min_index];
            arr[min_index]=temp;
        }    
    }
    printf("\nSelection Sort : ");
    for (int i = 0; i < size; i++)
        printf("%d  ", arr[i]);
}

void insertionSort(int arr[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int temp = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
    printf("\nInsertion Sort : ");
    for (int i = 0; i < size; i++)
        printf("%d  ", arr[i]);
}

int main(){
    int n;
    printf("enter # of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("enter %d elements : ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    bubbleSort(arr,n);
    selectionSort(arr,n);
    insertionSort(arr,n);
    return 0;

/*
enter # of elements: 7
enter 7 elements : 58 14 82 1 51 84 12

Bubble Sort : 1  12  14  51  58  82  84  
Selection Sort : 1  12  14  51  58  82  84  
Insertion Sort : 1  12  14  51  58  82  84  
}
*/
