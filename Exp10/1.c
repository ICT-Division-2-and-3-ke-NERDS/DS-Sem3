#include <stdio.h>

int linearSearch(int arr[10], int x)
{
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == x)
        {
            printf("%d found in the array.\n", x);
            return i;
        }
    }
    return -1;
}

int main()
{
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");

    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x;

    printf("Enter any number to search: ");
    scanf("%d", &x);

    int index = linearSearch(arr, x);

    if (index == -1)
    {
        printf("Value not found in the array.\n");
    }
    else
    {
        printf("Value found at index %d.\n", index);
    }

    return 0;
}
