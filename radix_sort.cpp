#include <bits/stdc++.h>
using namespace std;

void countsort(vector<int>& arr, int exp)
{

    vector<int> farr(10, 0);

    // Creating frequency array

    for (int i = 0; i < arr.size(); i++)
    {
        farr[(arr[i] / exp) % 10]++;
    }

    // Making prefix sum array

    for (int i = 1; i < farr.size(); i++)
    {
        farr[i] += farr[i - 1];
    }

    // Creating array for storing sorted elements
    vector<int> ans(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int val = (arr[i] / exp) % 10;
        int pos = farr[val];
        int idx = pos - 1;
        ans[idx] = arr[i];
        farr[val]--;
    }

    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = ans[i];
    }

}

void radixsort(vector<int>& arr)
{
    int max = *std::max_element(arr.begin(), arr.end());
    int exp = 1;
    while (exp <= max)
    {
        // Have to declare countsort() before using
        countsort(arr, exp);
        exp = exp * 10;
    }

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
    vector<int> arr = { 213,97,718,123,37,443,982,64,375,683 };
    radixsort(arr);
    display(arr);

    return 0;
}