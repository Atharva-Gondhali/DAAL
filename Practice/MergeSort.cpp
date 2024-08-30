#include <iostream>
#include <chrono>

using namespace std;

void merge(int arr[], int l, int m, int r, int n)
{
    int i = l;
    int j = m + 1;
    int k = l;
    int temp_arr[n];

    while (i <= m && j <= r)
    {
        if(arr[i] <= arr[j])
        {
            temp_arr[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            temp_arr[k] = arr[j];
            j++;
            k++;
        }
    }

    while(i <= m)
    {
        temp_arr[k] = arr[i];
        i++;
        k++;
    }

    while(j <= r)
    {
        temp_arr[k] = arr[j];
        j++;
        k++;
    }

    for(int p = l; p <= r; p++)
    {
        arr[p] = temp_arr[p];
    }
}

void sort(int arr[], int l, int r, int n)
{
    if(r > l)
    {
        int m = (l + r) / 2;
        sort(arr, l, m, n);
        sort(arr, m + 1, r, n);
        merge(arr, l, m, r, n);
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

    auto start = chrono::high_resolution_clock::now();
    sort(arr, 0, n - 1, n);
    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::nanoseconds>(end - start);

    cout << "Total time taken is " << duration.count() << endl;

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << ' ';
    }
}