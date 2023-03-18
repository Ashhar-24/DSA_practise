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

    int dupli;
    int pos, pos1;
    int flag=0;
    for(int i=0;i<n;i++)
    {
        dupli=arr[i];
        for(int j=0;j<n;j++)
        {   
        if(dupli == arr[j] && i != j)
            {
            flag++;
            pos=i;
            pos1=j;
            break;
            }
        
        }
    }

    if(flag != 0)
    {
        printf("Duplicate Exists at: %d and %d", pos1, pos);
    }
    else{
        printf("No duplicate found!");
    }
}
