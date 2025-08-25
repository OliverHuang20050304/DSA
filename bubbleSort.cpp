#include <iostream>
#include <utility>
using namespace std;

void bubbleSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        bool swapped = false;
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}

void bubbleSortDesc(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        bool swapped = false;
        for (int j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;
    }
}


void printArray(int arr[], int len)
{
    for (int i = 0;i < len; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

int main()
{
    int arr[6];
    cout << "請輸入六個數字，每輸入完一個數字就按enter:" << endl;
    for (int i = 0;i < 6; ++i)
    {
        int temp;
        cin >> temp;
        arr[i] = temp;
    }

    printArray(arr, 6);
    bubbleSortDesc(arr, 6);
    printArray(arr, 6);

    return 0;
}


