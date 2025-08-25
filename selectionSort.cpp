#include <iostream>
#include <utility> // for swap
using namespace std;

void selectionSort(int arr[], int length)
{
    for(int i = 0; i < length - 1; i++)
    {
        int minIndex = i;
        for(int j = i + 1; j < length; j++)
        {
            if(arr[j] < arr[minIndex])
            {
                minIndex = j;
            }

        }

        if(minIndex != i)
        {
            swap(arr[minIndex], arr[i]);
        }
    }
}


int main()
{
    int arr[] = {4,5,3,2,6,1,7,8,-1};
    int len = sizeof(arr) / sizeof(arr[0]); 
    selectionSort(arr, len);

    for(int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}