// Best case O(N)
// Average case O(log(N))
// Space O(1)

#include <iostream>
#include <chrono>

using namespace std;

int binary_search(int arr[], int key, int l, int r)
{
    int m = (l + r) / 2;

    if(l <= r)
    {
        if(arr[m] == key)
        {
            return m;
        }
        else if(arr[m] > key)
        {
            return binary_search(arr, key, l, m - 1);
        }
        else
        {
            return binary_search(arr, key, m + 1, r);
        }
    }

    return -1;
}

int main()
{
    int n;
    cout << "Enter the number of elements in array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }  

    int key;
    cout << "Enter the element to be searched: ";
    cin >> key;
    auto start = chrono::high_resolution_clock::now();  
    
    int result = binary_search(arr, key, 0, n - 1);
    
    auto end = chrono::high_resolution_clock::now();
    auto total_duration = chrono::duration_cast<chrono::nanoseconds>(end - start);
    cout << "Search Time: " << total_duration.count() << " nanoseconds" << std::endl;

    cout << "Element is present at index: " << result << endl;
}