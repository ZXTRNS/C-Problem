#include <stdio.h>

void merge(int arr[], int left, int mid, int right)
{
    int lenLeft = mid - left + 1;
    int lenRight = right - mid;

    int leftPart[lenLeft];
    int rightPart[lenRight];


    for(int i = 0; i < lenLeft; i++)
    {
        leftPart[i] = arr[left + i];
    }
    for(int i = 0; i < lenRight; i++)
    {
        rightPart[i] = arr[mid + 1 + i];
    }

    // The soul of sorting
    int pointerLeftPart = 0;
    int pointerRightPart = 0;
    int pointerArr = left;

    while(pointerLeftPart < lenLeft && pointerRightPart < lenRight)
    {
        if(leftPart[pointerLeftPart] <= rightPart[pointerRightPart])
        {
            arr[pointerArr] = leftPart[pointerLeftPart];
            pointerLeftPart++;
        }
        else
        {
            arr[pointerArr] = rightPart[pointerRightPart];
            pointerRightPart++;
        }
        pointerArr++;
    }

    while(pointerLeftPart < lenLeft)
    {
        arr[pointerArr] = leftPart[pointerLeftPart];
        pointerArr++;
        pointerLeftPart++;
    }
    while(pointerRightPart < lenRight)
    {
        arr[pointerArr] = rightPart[pointerRightPart];
        pointerArr++;
        pointerRightPart++;
    }
}

void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Dividing algorithm
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid); 
        mergeSort(arr, mid + 1, right); 

		// Merging algorithm
        merge(arr, left, mid, right);
    }
}

void printArray(int A[], int size) { for (int i = 0; i < size; i++) printf("%d ", A[i]); printf("\n");}

int main()
{
    int numList[10] = {3,2,6,1,8,7,0,5,9,4};
    int len = sizeof(numList)/sizeof(numList[0]);

    mergeSort(numList, 0, len - 1);
    printArray(numList, len);
}
