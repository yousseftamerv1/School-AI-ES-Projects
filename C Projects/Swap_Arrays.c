#include <stdio.h>

int main()
{
    int arr[5] , arr1[5];

    for (int i = 1; i <= 5; i++)
    {
        printf("Enter The Value Number '%d' of The First Array :" , i);
        scanf("%d" , &arr[i]);
        fflush(stdin);
        
    }
    printf("\n");
    for (int i = 1; i <= 5; i++)
    {
        
        printf("Enter The Value Number '%d' of The Second Array :" , i);
        scanf("%d" , &arr1[i]);
        fflush(stdin);
    
        
    }    
    printf("Before Swapping\n");
    printf("First Array Equals: ");
    for (int i = 1; i <= 5; i++)
    {
        printf("%d " , arr[i]);    
    } 
    
    printf("\nSecond Array Equals: ");
    for (int i = 1; i <= 5; i++)
    {
        printf("%d " , arr1[i]);    
    }    
    
    for (int i = 1; i <= 5; i++)
    {
        int tmp[i];

        tmp[i] = arr[i];
        arr[i] = arr1[i];
        arr1[i] = tmp[i];
    }
        

    printf("\nAfter Swapping\n");
    
    printf("First Array Equals: ");
    for (int i = 1; i <= 5; i++)
    {
        printf("%d " , arr[i]);    
    } 
    
    printf("\nSecond Array Equals: ");
    for (int i = 1; i <= 5; i++)
    {
        printf("%d " , arr1[i]);    
    }  
    
}
