#include <bits/stdc++.h>
using namespace std;

void solveWithSort(int n) {
  vector<int> nums(n, 0);
  for (int i = 1; i < n; i++) {
    int x;
    cin >> x;
    nums[i] = x;
  }
  sort(nums.begin(), nums.end());
  for (int i = 0; i < n; i++) {
    if (nums[i] != i) {
      cout << i;
      return;
    }
  }
  cout << n;
}

void solveWithOutSorting(int n) {
  long long sum = (n * (n + 1)) / 2, tempSum = 0;
  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    tempSum += x;
  }
  cout << sum - tempSum;
}

int main() {
  int n;
  cin >> n;
  solveWithSort(n);
  // solveWithOutSorting(n);
  return 0;
}
