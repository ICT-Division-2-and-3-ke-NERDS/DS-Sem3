#include <stdio.h>

int binarySearch(int arr[10], int size, int x)
{
    int st = 0;
    int end = size - 1;
    int mid;

    while (st <= end)
    {
        mid = (st + end) / 2;

        if (arr[mid] == x)
        {
            printf("Value found at index %d\n", mid);
            return mid;
        }
        else if (x < arr[mid])
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }

    return -1;
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");

    int arr[10] = {10, 20, 30, 40, 50, 60, 69, 70, 80, 96};
    int x;

    printf("Enter the value you want to find: ");
    scanf("%d", &x);

    int index = binarySearch(arr, 10, x);

    if (index == -1)
    {
        printf("Value not found in the array.\n");
    }

    return 0;
}
