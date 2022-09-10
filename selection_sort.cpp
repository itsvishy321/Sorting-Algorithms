#include <bits/stdc++.h>
using namespace std;
void selectionsort(vector<int>& A, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[minIndex])
                minIndex = j;
        }
        swap(A[i], A[minIndex]);
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
    vector<int> A = { 64, 25, 12, 22, 11 };
    int n = A.size();
    selectionsort(A, n);
    display(A);
    return 0;
}
