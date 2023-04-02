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

void merge(int list[], int left, int right, int mid)
{
    int num1 = 0, num2 = 0;
    int i = 0, j = 0, k = 0;
    num1 = mid - left + 1;
    num2 = right - mid;

    int L[num1], R[num2];

    for(i = 0; i<num1;i++)
    {
        L[i] = list[left+i];
    }

    for(j = 0; j<num2;j++)
    {
        R[j] = list[mid+j+1];
    }

    i = 0, j = 0, k = left;
    while(i < num1 && j < num2)
    {
        if(L[i] < R[j])
        {
            list[k] = L[i];
            i++;
        }
        else
        {
            list[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < num1)
    {
        list[k] = L[i];
        i++;
        k++;
    }

    while(j < num2)
    {
        list[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int list[], int left, int right)
{
    int mid = 0;

    if(left < right)
    {
        mid = left + (right - left)/2;

        mergeSort(list, left, mid);
        mergeSort(list, mid+1, right);

        merge(list, left, right, mid);
    }
}

int partition(int list[], int low, int high)
{
    int pivot = 0, i = 0, j = 0;

    pivot = list[high];
    i = low - 1;

    for(j = low; j < high; j++)
    {
        if(list[j] < pivot)
        {
            i++;
            swap(&list[i], &list[j]);
        }
    }

    swap(&list[i+1], &list[high]);

    return (i+1);
}

void quickSort(int list[], int low, int high)
{
    int pivot = 0;
    if(low < high)
    {
        pivot = partition(list, low, high);

        quickSort(list, low, pivot-1);
        quickSort(list, pivot+1, high);
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
    //selectionSort(arr, sizeof(arr)/sizeof(int));

    /*mergeSort*/
    //mergeSort(arr,0, sizeof(arr)/sizeof(int) - 1);

    /*quickSort*/
    quickSort(arr,0, sizeof(arr)/sizeof(int) - 1);

    /*TESTING*/
    for(i = 0; i < sizeof(arr)/sizeof(int); i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
