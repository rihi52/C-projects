#include <stdio.h>
#include <stdlib.h>

// adding comment for testing
// another test comment

int main(void)
{
    int arr[10] = {7, 4, 5, 8 ,3 ,9 ,0 ,1, 2, 6}, n = 10, temp = 0;

    for(int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");

    for(int i = 0; i < n-1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            /* if (min != i)
            {
                temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }*/
        }
        // printf("%i ", arr[i]);
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
}