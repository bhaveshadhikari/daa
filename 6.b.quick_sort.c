#include<stdio.h>

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1; // Size of left subarray
    int n2 = r - mid;     // Size of right subarray

    int left[n1], right[n2]; // Temporary arrays

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        left[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into the original array
    int i = 0, j = 0, k = l; 
    while (i < n1 && j < n2) {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // Copy any remaining elements of left[]
    while (i < n1)
        arr[k++] = left[i++];

    // Copy any remaining elements of right[]
    while (j < n2)
        arr[k++] = right[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2; // Find the midpoint
        mergeSort(arr, l, mid);    // Sort the left half
        mergeSort(arr, mid + 1, r);// Sort the right half
        merge(arr, l, mid, r);     // Merge the sorted halves
    }
}

void traverse(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {2, 3, 14, 15, 9, 16, 37, 27};
    int size = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, size - 1);
    printf("sorted array: ");
    traverse(arr, size);
    return 0;
}
