#include <iostream>
using namespace std;

int getInversionCount(int *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
                count++;
        }
    }
    return count;
}

int main()
{
    int arr[] = {3, 6, 4, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << getInversionCount(arr, n) << endl;

    return 0;
}