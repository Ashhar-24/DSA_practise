#include <stdio.h>
#include <math.h>

int main()
{
    int n;
    printf("Enter the number of digits: ");
    scanf("%d", &n);

    printf("Enter the numbers: \t");

    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d", &arr[i]);
    }

    int num=0;
    for(int i=0;i<n;i++)
    {
        num= num+ arr[i]* pow(10,i);
        //for printing in same order, use 'n-i-1' instead of 'i';
    }

    printf("The number is: %d", num);
}