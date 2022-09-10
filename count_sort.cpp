#include <bits/stdc++.h>
using namespace std;

vector<int> countsort(vector<int> arr, int min, int max)
{
    int range = max - min + 1;
    vector<int> farr(range, 0);

    // Creating frequency array

    for (int i = 0; i < arr.size(); i++)
    {
        int findex = arr[i] - min;
        farr[findex]++;
    }

    // Making prefix sum array

    for (int i = 1; i < range; i++)
    {
        farr[i] += farr[i - 1];
    }

    vector<int> ans(arr.size());

    for (int i = arr.size() - 1; i >= 0; i--)
    {
        int val = arr[i];
        int pos = farr[val - min];
        int idx = pos - 1;
        ans[idx] = val;
        farr[val - min]--;
    }

    return ans;
}

void display(vector<int> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{

    vector<int> arr = {9, 6, 3, 5, 3, 4, 3, 9, 6, 4, 6, 5, 8, 9, 9};

    int min = *std::min_element(arr.begin(), arr.end());
    int max = *std::max_element(arr.begin(), arr.end());

    arr = countsort(arr, min, max);

    display(arr);

    return 0;
}