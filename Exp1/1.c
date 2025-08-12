#include <stdio.h>

void add(int arr1[3][3],int arr2[3][3],int res[3][3]){
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            res[i][j]=arr1[i][j]+arr2[i][j];
        }
    }
}

int main(){
    printf("Student Name: Ronit Kundnani\n");
    printf("Student RollNo: 24BIT100\n");
    int arr1[3][3];
    int arr2[3][3];
    int res[3][3];

    printf("Enter the Elements of the matrix 1 \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("Enter %d %d th element:",i,j);
            scanf("%d",&arr1[i][j]);  
        }
        printf("\n");
    }
    printf("Enter the Elements of the matrix 2: \n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("Enter %d %d th element:",i,j);
            scanf("%d",&arr2[i][j]);  
        }
        printf("\n");
    }
    
    add(arr1,arr2,res);

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d \t",res[i][j]);
        }
        printf("\n");
    }
    return 0;
}