#include <bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int s, int e)
{
    int pivot = arr[s];
    int count = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
        {
            count++;
        }
    }

    // placing pivot at right position
    int pivotIndex = s + count;
    swap(arr[pivotIndex], arr[s]);

    // sorting left hand side
    int i = s, j = e;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quicksort(vector<int>& arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    int p = partition(arr, s, e);

    // left side sort
    quicksort(arr, s, p - 1);

    //  right side sort
    quicksort(arr, p + 1, e);
}

void display(vector<int>& arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int> arr = { 2, 4, 1, 6, 9 , 4 };
    int n = arr.size();

    quicksort(arr, 0, n - 1);

    display(arr);

    return 0;
}
