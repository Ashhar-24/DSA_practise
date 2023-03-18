#include <stdio.h>
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter the elements: \t");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    int num,posn;
    printf("Enter the number: \t");
    scanf("%d", &num);
    printf("Enter the position: \t");
    scanf("%d", &posn);

    for(int i=n-1;i>=posn;i--)
    {   //moving all the elements to right and creating a space for new element
        arr[i+1]=arr[i];
    }

    arr[posn]=num;
    n=n+1;
    //if size is not increased last element won't be printed!

    printf("Array after insertion becomes: \t");
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
}