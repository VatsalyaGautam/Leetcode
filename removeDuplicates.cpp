int removeDuplicates(vector<int> &arr, int n) {
  int first = 0;
  int move = 1;
  int cnt = 1;
  while (move < n) {
    if (arr[first] != arr[move]) {
      ++first;
      arr[first] = arr[move];
      cnt++;
      move++;
    } else {
      move++;
    }
  }
  return cnt;
}
