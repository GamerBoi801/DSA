#include <bits/stdc++.h>
using namespace std;

int linear_search(vector<int> a, int n) {
  // n, is the element to be found this returns the index only
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == n) {
      return i;
    }
  }
  return -1;
}

int binary_search(vector<int> a, int n) {
  // key takeaway: that the array must be sorted before searching
  a = sort(a.begin(), a.end());
  int left = 0, right = a.size() - 1;

  while (left < right) {

    int mid = (right-left)/2;

    if (a[mid] == target) {
      return mid;
    } else if (a[mid] < target) {
      // if target is greater ignore the left half
      left = mid + 1;
    } else {
      // if target is smaller then ignore the right half
      right = mid + 1;
    }
  }
}

int main() {
  vector<int> a = {9, 8, 1, 5, 2, 26, 14, 59, 99, 300};
  int n = a.size();
  return 0;
}
