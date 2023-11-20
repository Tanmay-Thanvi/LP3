// https://www.youtube.com/watch?v=7h1s2SojIRw
// https://www.youtube.com/watch?v=-qOVVRIZzao
// https://www.youtube.com/watch?v=WIrA4YexLRQ
// https://www.youtube.com/watch?v=nUlEfx-HgII

// https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/

// QuickSort by using deterministic and randomized variant.

#include <bits/stdc++.h>
using namespace std;

// Partition function for Quick Sort
int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
        {
            i++;
        }

        while (arr[j] > pivot && j >= low + 1)
        {
            j--;
        }
        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

// Deterministic Quick Sort
void deterministicQuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int partitionIndex = partition(arr, low, high);

        deterministicQuickSort(arr, low, partitionIndex - 1);
        deterministicQuickSort(arr, partitionIndex + 1, high);
    }
}

// Randomized Quick Sort
void randomizedQuickSort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int randomPivotIndex = low + rand() % (high - low + 1);
        swap(arr[randomPivotIndex], arr[low]);

        int partitionIndex = partition(arr, low, high);

        randomizedQuickSort(arr, low, partitionIndex - 1);
        randomizedQuickSort(arr, partitionIndex + 1, high);
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


// The time complexity of the deterministicQuickSort function is determined by the 
// time complexity of the partition function and the number of recursive calls made. 


// 1. **Partition function:**
//    - The partition function uses a while loop that iterates through the array elements once.
//    - In each iteration, it performs a constant amount of 
//      work (comparisons, increments, and swaps).
//    - In the worst case, the while loop may run in O(n) time, 
//      where n is the size of the array.
//    - The swap(arr[low], arr[j]) operation outside the loop takes constant time.

//    Therefore, the partition function has a time complexity of O(n), 
//    where n is the size of the array.

// 2. **DeterministicQuickSort function:**
//    - The function makes two recursive calls on smaller subproblems.
//    - The recurrence relation for the time complexity T(n) can be expressed as follows:
//      ```
//      T(n) = 2 * T(n/2) + O(n)
//      ```
//      This is because there are two recursive calls, each operating on 
//      roughly half of the array, and the partition function takes O(n) time.

//    - By applying the Master Theorem, the time complexity of 
//      deterministicQuickSort is O(n log n), which is the same as 
//      the average case time complexity of standard quicksort.

// 3. **Space Complexity:**
//    - The space complexity is determined by the recursion stack during the recursive calls.
//    - In the worst case, the depth of the recursion stack is log(n) (base 2), 
//      where n is the size of the array.
//    - Each recursive call requires a constant amount of space for variables, 
//      so the overall space complexity is O(log n).

// In summary, the time complexity of the deterministicQuickSort function is O(n log n), 
// and the space complexity is O(log n). 
// The partition function contributes to the overall time complexity.