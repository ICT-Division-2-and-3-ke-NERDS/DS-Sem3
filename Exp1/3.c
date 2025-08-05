#include <stdio.h>
int main(){
    printf("Student Name: Ronit Kundnani");
    printf("Student RollNo: 24BIT100");
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int largest=arr[0] , secondLarge=arr[0];
    int smallest=arr[0] , secondSmall=arr[0];

    for(int i=0;i<n;i++){
        if(arr[i]>largest){
            secondLarge=largest;
            largest=arr[i];
        }
        else if(arr[i]>secondLarge && arr[i]<largest){
            secondLarge=arr[i];
        }

        if(arr[i]<smallest){
            secondSmall=smallest;
            smallest=arr[i];
        }
        else if(arr[i]<secondSmall && arr[i]>smallest){
            secondSmall=arr[i];
        }
    }

    printf("The smallest and Second smallest value of the array are %d and %d \n",smallest,secondSmall);
    printf("The largest and Second largest value of the array are %d and %d",largest,secondLarge);

    return 0;
}