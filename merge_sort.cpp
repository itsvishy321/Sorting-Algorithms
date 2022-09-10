#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int s, int e)
{
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* first = new int[len1];
    int* second = new int[len2];

    // copy values in first

    int mainarrayIndex = s;
    for (int i = 0; i < len1; i++)
    {
        first[i] = arr[mainarrayIndex++];
    }

    // copy values in second

    mainarrayIndex = mid + 1;
    for (int i = 0; i < len2; i++)
    {
        second[i] = arr[mainarrayIndex++];
    }

    // merge 2 sorted arrays

    int index1 = 0;
    int index2 = 0;
    mainarrayIndex = s;

    while (index1 < len1 && index2 < len2)
    {
        if (first[index1] <= second[index2])
        {
            arr[mainarrayIndex++] = first[index1++];
        }
        else
        {
            arr[mainarrayIndex++] = second[index2++];
        }
    }

    while (index1 < len1)
    {
        arr[mainarrayIndex++] = first[index1++];
    }

    while (index2 < len2)
    {
        arr[mainarrayIndex++] = second[index2++];
    }

    // clearing heap memory
    delete[] first;
    delete[] second;
}

void mergesort(vector<int>& arr, int s, int e)
{
    // base case
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;

    // left side sort krna
    mergesort(arr, s, mid);

    // right side sort krna
    mergesort(arr, mid + 1, e);

    merge(arr, s, e);
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
    vector<int> arr = { 38, 27, 43, 3, 3, 82, 10 };
    int n = arr.size();

    mergesort(arr, 0, n - 1);

    display(arr);

    return 0;
}