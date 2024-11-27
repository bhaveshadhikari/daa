#include <stdio.h>
void swap(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}
void fractionalKnapsack(int n, float weights[], float profits[], float capacity) {
    float ratio[n], totalProfit = 0.0;
    int i, j;
    for (i = 0; i < n; i++)
        ratio[i] = profits[i] / weights[i]; // P/W ratio

    // Sort ratio in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                // Swap ratio, weights, and profits
                swap(&ratio[j], &ratio[j + 1]);
                swap(&weights[j], &weights[j + 1]);
                swap(&profits[j], &profits[j + 1]);
            }
        }
    }
    for (i = 0; i < n; i++) {   // kanpsack filling
        if (weights[i] <= capacity) {
            totalProfit += profits[i];
            capacity -= weights[i];
        } else {  //fractional fill
            totalProfit += ratio[i] * capacity; 
            break;
        }
    }
    printf("Maximum profit: %.2f\n", totalProfit);
}


int main() {

    int n = 3;
    float weights[] = {10, 20, 30};
    float profits[] = {60, 100, 120};
    float capacity = 50;
    fractionalKnapsack(n, weights, profits, capacity);
    return 0;
}

/*
Output:

Maximum profit: 240.00
*/
