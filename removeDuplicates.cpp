#include <iostream>
#include <vector>

using namespace std;

// Function to remove duplicates
int removeDuplicates(vector<int> &arr, int n);

int main()
{
  // Example array with duplicates
  vector<int> arr = {1, 1, 2, 3, 3, 4, 5, 5, 6};
  int n = arr.size();

  cout << "Original array: ";
  for (int num : arr)
  {
    cout << num << " ";
  }
  cout << endl;

  // Call the function to remove duplicates
  int newLength = removeDuplicates(arr, n);

  // Print the array after removing duplicates
  cout << "Array after removing duplicates: ";
  for (int i = 0; i < newLength; ++i)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Print the new length of the array
  cout << "New length of the array: " << newLength << endl;

  return 0;
}

// Function definition (provided)
int removeDuplicates(vector<int> &arr, int n)
{
  int first = 0;
  int move = 1;
  int cnt = 1;
  while (move < n)
  {
    if (arr[first] != arr[move])
    {
      ++first;
      arr[first] = arr[move];
      cnt++;
    }
    ++move;
  }
  return cnt;
}