#include <stdio.h>

void swap(int *a, int *b)
{
    int tmp = 0;

    tmp = *a;
    *a = *b;
    *b = tmp;
}

void interchangeSort(int list[], int len)
{
    int i = 0, j = 0;

    for(i = 0; i < len - 1; i++)
    {
        for(j = i+1; j < len; j++)
        {
            if(list[i] > list[j])
                swap(&list[i], &list[j]);
        }
    }
}

void bubbleSort(int list[], int len)
{
    int i = 0, j = 0;

    for(i = 0; i < len - 1; i++)
    {
        for(j = len - 1; j > i; j--)
        {
            if(list[j] < list[j-1])
                swap(&list[j-1], &list[j]);
        }
    }
}

void insertSort(int list[], int len)
{
    int i = 0, pos = 0;
    int tmp = 0;

    for(i = 1; i < len; i++)
    {
        tmp = list[i];
        pos = i;

        while(pos > 0 && tmp < list[pos-1])
        {
            swap(&list[pos-1], &list[pos]);
            pos--;
        }
    }
}

void selectionSort(int list[], int len)
{
    int i = 0, j = 0;
    int min = 0;

    for(i = 0; i < len - 1; i++)
    {
        min = i;
        for(j = i+1; j < len; j++)
        {
            if(list[j] < list[min])
                min = j;
        }
        
        if(i != min)
            swap(&list[i], &list[min]);
    }
}

int main()
{
    int arr[5] = {7,5,9,1,10};
    int i = 0;

    /*interChangeSort*/
    //interchangeSort(arr, sizeof(arr)/sizeof(int));

    /*bubbleSort*/
    //bubbleSort(arr, sizeof(arr)/sizeof(int));

    /*insertSort*/
    //insertSort(arr, sizeof(arr)/sizeof(int));
    
    /*selectionSort*/
    selectionSort(arr, sizeof(arr)/sizeof(int));

    /*TESTING*/
    
    for(i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
