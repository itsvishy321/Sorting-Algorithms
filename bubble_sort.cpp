#include <iostream>
using namespace std;

void bubblesort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        bool swapped = false;
        for (int j = 0; j < n - i; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                swapped = true;
            }
        }
        if (swapped = false)
        {
            break;
        }
    }
}

void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}

int main()
{

    int A[] = {13, 5, 7, 8, 2, 8, 4, 9, 6};
    int n = sizeof(A) / sizeof(A[0]);
    bubblesort(A, n);

    cout << "After Sorting" << endl;
    display(A, n);

    return 0;
}
