#include <iostream>
using namespace std;

int binarySearch(int arr[], int len, int target)
{
    int left = 0, right = len - 1;

    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if(arr[mid] == target)
        {
            return mid;
        }else if(arr[mid] > target)
        {
            right = mid - 1;
        }else
        {
            left = mid + 1;
        }
    }

    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,4,5,6,7,17};
    int n = sizeof(arr) / sizeof(arr[0]);
    int tar = 17;
    int res = binarySearch(arr, n, tar);

    if(res != -1)
    {
        cout << "找到了！在" << res << endl;
    }else
    {
        cout << "找不到！" << endl;
    }
    return 0;
}