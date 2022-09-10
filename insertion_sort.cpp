#include <bits/stdc++.h>
using namespace std;

void insertionsort(vector<int>& arr)
{
    // base case
    for (int i = 1; i < arr.size(); i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = temp;
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
    vector<int> arr = { 4,8,5,7,2,9,6,5 };
    insertionsort(arr);
    cout << "After Sorting" << endl;
    display(arr);

    return 0;
}
