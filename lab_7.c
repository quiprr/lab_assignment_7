/*
  COP3502C-0024
  7 March 2024
  Lab Assignment 7
*/

#include <stdio.h>
#include <stdlib.h>


// Function prototypes
void printArray(int arr[], int size);
void bubbleSortAndTrackSwaps(int arr[], int size);
void selectionSortAndTrackSwaps(int arr[], int size);
void resetSwapCounts(int *swaps, int size);


// Global variables for tracking swaps
int swapCounts[100]; // Max 100 values


void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d: %d\n", arr[i], swapCounts[arr[i]]);
    }
}

void resetSwapCounts(int *swaps, int size)
{
    for (int i = 0; i < size; i++)
    {
        swaps[i] = 0;
    }
}

// Interpreted from Sorting/BubbleSort.c in COP3502C-0003 Modules
void bubbleSortAndTrackSwaps(int arr[], int size)
{
    int totalSwaps = 0;
    resetSwapCounts(swapCounts, 100);
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap and track
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapCounts[arr[j]]++;
                swapCounts[arr[j + 1]]++;
                totalSwaps++;
            }
        }
    }
    printArray(arr, size);
    printf("%d\n", totalSwaps);
}

// Interpreted from Sorting/SelectionSort.c in COP3502C-0003 Modules
void selectionSortAndTrackSwaps(int arr[], int size)
{
    int totalSwaps = 0;
    resetSwapCounts(swapCounts, 100);
    for (int i = 0; i < size - 1; i++)
    {
        int minIdx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
        }
        if (minIdx != i)
        {
            // Swap and track
            int temp = arr[minIdx];
            arr[minIdx] = arr[i];
            arr[i] = temp;
            swapCounts[arr[i]]++;
            swapCounts[arr[minIdx]]++; // This should ideally count once for swap
            totalSwaps++;
        }
    }
    printArray(arr, size);
    printf("%d\n", totalSwaps);
}

int main()
{
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    // Bubble sort
    printf("array1 bubble sort:\n");
    bubbleSortAndTrackSwaps(array1, size1);
    printf("\narray2 bubble sort:\n");
    bubbleSortAndTrackSwaps(array2, size2);

    // Resetting arrays to original state for selection sort
    int array1Original[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2Original[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};

    // Selection sort
    printf("\narray1 selection sort:\n");
    selectionSortAndTrackSwaps(array1Original, size1);
    printf("\narray2 selection sort:\n");
    selectionSortAndTrackSwaps(array2Original, size2);

    return 0;
}