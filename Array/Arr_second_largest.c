#include <stdio.h>
int main()
{   int n;
    printf("Size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("\nEnter the elements:\t");
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Elements are: \n");
    for(int i=0;i<n;i++)
    {
        printf("%d ", arr[i]);
    }

    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(max<arr[i])
        {
            max=arr[i];
        }
    }
    printf("\nMax element is: %d ", max);

    int max2=arr[0];
    for(int i=1;i<n;i++)
    {
        if(max2<arr[i] && arr[i] != max)
        /*imp to note that arr[i]!=max | max2 != max are completely different thing. max2!=max wont work as in max2 the previous element will be stored and hence !=
         condition will be satisfied and hence both max and max2 will be same numbers!*/ 
        {
            max2=arr[i];
        }
    }

    printf("\nSecond largest element is: %d", max2);
}