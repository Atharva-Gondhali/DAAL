#include <iostream>

using namespace std;

int partition(int arr[], int l, int r)
{
    int pivot = arr[r];
    int p_index = l;

    for(int i = l; i < r; i++)
    {
        if(arr[i] <= pivot)
        {
            swap(arr[i], arr[p_index]);
            p_index ++;
        }
    }

    swap(arr[r], arr[p_index]);
    return p_index;
}

void sort(int arr[], int l, int r)
{
    if(r > l)
    {
        int p = partition(arr, l, r);
        sort(arr, l, p - 1);
        sort(arr, p + 1, r);
    }
}

int main()
{
    int n;
    cout << "Enter no of elements in array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}