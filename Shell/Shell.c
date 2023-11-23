#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%2d ", arr[i]);
    }
    printf("\n");
}

void shellSort(int arr[], int size) {
    int comparisons = 0;
    int moves = 0;

    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int key = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > key) {
                comparisons++;
                arr[j] = arr[j - gap];
                j -= gap;
                moves++;
            }

            arr[j] = key;
            moves++;
        }

        printf("Number of comparisons: %d\n", comparisons);
        printf("Number of moves: %d\n", moves);
        printf("Output: ");
        printArray(arr, size);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int numbers[SIZE];
    int totalComparisons = 0;
    int totalMoves = 0;

    for (int iteration = 1; iteration <= 20; iteration++) {
        printf("Iteration %d:\n", iteration);

        printf("Original array: ");
        for (int i = 0; i < SIZE; i++) {
            numbers[i] = rand() % 100; // Generate random numbers between 0 and 99
            printf("%2d ", numbers[i]);
        }
        printf("\n\n");

        int tempNumbers[SIZE];
        for (int i = 0; i < SIZE; i++) {
            tempNumbers[i] = numbers[i];
        }

        printf("Shell Sort:\n");
        shellSort(tempNumbers, SIZE);

        totalComparisons += tempNumbers[SIZE / 2]; // Using the middle value for average
        totalMoves += tempNumbers[SIZE / 2 + 1]; // Using the value next to the middle for average

        printf("\n");
    }

    printf("Average number of comparisons: %.2f\n", (float)totalComparisons / 20);
    printf("Average number of moves: %.2f\n", (float)totalMoves / 20);

    return 0;
}