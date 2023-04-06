#include <iostream>
#include <vector>

using namespace std;

void print(vector<int>& arr, int length)
{
    int i = 0;

    for(i = 0; i < length; i++)
    {
        cout<< arr[i];
    }
    cout<<endl;
}

/*Solution 1*/
void generateBinary(vector<int>& arr, int length, int index)
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

/*Solution 2*/
void generateBinary(vector<int>& arr, int length)
{
    int i = 0;

    do
    {
        print(arr, length);
        i = length - 1;

        while(i>=0 && arr[i]==1)
        {
            i--;
        }

        if(i>=0)
        {
            arr[i] = 1;
            if(arr.begin()+i < arr.end()-1)
                fill(arr.begin()+i+1, arr.end(), 0);
        }
    }
    while(i>=0);
}

int main()
{
    int n;

    cout<<"Input length:";
    cin>>n;

    vector<int>arr(n);

    /*Solution 1*/
    //generateBinary(arr, n, 0);

    /*Solution 2*/
    generateBinary(arr, n);
    return 0;
}
