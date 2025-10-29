#include <stdio.h>

int firstOccurrence(int arr[], int size, int x)
{
    int st = 0;
    int end = size - 1;
    int result = -1;

    while (st <= end)
    {
        int mid = (st + end) / 2;

        if (arr[mid] == x)
        {
            result = mid;
            // Move right to find earlier occurrence in descending order
            st = mid + 1;
        }
        else if (arr[mid] < x)
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return result;
}

int lastOccurrence(int arr[], int size, int x)
{
    int st = 0;
    int end = size - 1;
    int result = -1;

    while (st <= end)
    {
        int mid = (st + end) / 2;

        if (arr[mid] == x)
        {
            result = mid;
            // Move left to find later occurrence in descending order
            end = mid - 1;
        }
        else if (arr[mid] < x)
        {
            end = mid - 1;
        }
        else
        {
            st = mid + 1;
        }
    }
    return result;
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");

    int arr[] = {99, 90, 90, 80, 75, 60, 60, 45, 30, 10};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x;

    printf("Enter the value you want to find: ");
    scanf("%d", &x);

    int first = firstOccurrence(arr, size, x);
    int last = lastOccurrence(arr, size, x);

    if (first == -1 && last == -1)
    {
        printf("Value %d not found in the array.\n", x);
    }
    else
    {
        printf("First occurrence of %d is at index %d\n", x, first);
        printf("Last occurrence of %d is at index %d\n", x, last);
    }

    return 0;
}
