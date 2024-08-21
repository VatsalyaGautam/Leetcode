#include <iostream>
#include <vector>
#include <algorithm> // For std::swap

using namespace std;

// Function to perform selection sort
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    int minIndex, i, j;

    for (i = 0; i < n - 1; i++)
    {
        minIndex = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}

// Driver function to test selectionSort
int main()
{
    // Example array to be sorted
    vector<int> arr = {64, 25, 12, 22, 11};

    cout << "Original array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    // Call the function to sort the array
    selectionSort(arr);

    // Print the sorted array
    cout << "Sorted array: ";
    for (int num : arr)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}