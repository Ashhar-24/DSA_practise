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

    int num;
    printf("Enter the number: \t");
    scanf("%d", &num);

    for(int i=0;i<n;i++)
    {
        if(arr[i]>num)
        {
            for(int j=n-1;j>=i;j--)
            {
                arr[j+1]=arr[j];
            }
            arr[i]=num;
            break;
        }
    }
    n=n+1;

    printf("Array after insertion becomes: \t");
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }
}