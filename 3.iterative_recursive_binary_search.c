#include <stdio.h>

int binarySearchIterative(int array[], int key, int low, int high){

    while (low <= high){
        int mid = (low+high) / 2;

        if (array[mid] == key)
            return mid;

        if (array[mid] < key)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;
}


int binarySearchRecursive(int a[], int key, int i, int j){

    int m = (i + j) / 2;

    if (a[m] == key)
        return m;

    if (key < a[m] && i < m)
        return binarySearchRecursive(a, key, i, m - 1);

    if (key > a[m] && j > m)
        return binarySearchRecursive(a, key, m+1, j);

    return -1;

}

int main(){
    int n;
    printf("enter # of elements: ");
    scanf("%d", &n);
    int arr[n], key;
    printf("enter %d sorted elements : ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("enter key to search : ");
    scanf("%d", &key);
    int resultItr = binarySearchIterative(arr,key,0,n-1);

    (resultItr == -1) ? printf("Element not found") : printf("element found at index: %d", resultItr);
    
    int resultRec = binarySearchRecursive(arr,key,0,n-1);

    (resultRec == -1) ? printf("\nElement not found") : printf("\nelement found at index: %d", resultRec);

    return 0;

}

/*
enter # of elements: 6
enter 6 sorted elements : 15 45 67 79 84 94
enter key to search : 67
element found at index: 2
element found at index: 2
*/
