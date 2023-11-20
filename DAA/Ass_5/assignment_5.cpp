// QuickSort by using deterministic and randomized variant.

#include <bits/stdc++.h>
using namespace std;

// Partition function for Quick Sort
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Deterministic Quick Sort
void deterministicQuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);

        deterministicQuickSort(arr, low, pivot - 1);
        deterministicQuickSort(arr, pivot + 1, high);
    }
}

// Randomized Quick Sort
int randomPartition(vector<int> &arr, int low, int high)
{
    int randomPivotIndex = low + rand() % (high - low + 1);
    swap(arr[randomPivotIndex], arr[high]);
    return partition(arr, low, high);
}

void randomizedQuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pivot = randomPartition(arr, low, high);

        randomizedQuickSort(arr, low, pivot - 1);
        randomizedQuickSort(arr, pivot + 1, high);
    }
}

int main()
{
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    srand(time(0)); // Seed for randomization

    cout << "Enter " << n << " integers:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> deterministicArr = arr;
    vector<int> randomizedArr = arr;

    deterministicQuickSort(deterministicArr, 0, n - 1);
    randomizedQuickSort(randomizedArr, 0, n - 1);

    cout << "Deterministic Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << deterministicArr[i] << " ";
    }
    cout << endl;

    cout << "Randomized Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << randomizedArr[i] << " ";
    }
    cout << endl;

    return 0;
}
