#include <iostream>

using namespace std;

void print(int arr[], int length)
{
    int i = 0;

    for(i = 0; i < length; i++)
    {
        cout<< arr[i];
    }
    cout<<endl;
}

void generateBinary(int arr[], int length, int index)
{
    if(index == length)
    {
        print(arr, length);
        return;
    }

    arr[index] = 0;
    generateBinary(arr, length, index+1);
    arr[index] = 1;
    generateBinary(arr, length, index+1);
}

int main()
{
    int n;

    cout<<"Input length:";
    cin>>n;

    int arr[n];

    generateBinary(arr, n, 0);

    return 0;
}
