#include <bits/stdc++.h>
using namespace std;

// time complexity O(nlogn) space complexity O(1)

void solve() {
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> arr;
  for (int i = 0; i < n; i++) {
    int temp;
    cin >> temp;
    arr.push_back({temp, i});
  }
  sort(arr.begin(), arr.end());
  int left = 0, right = n - 1;
  while (left < right) {
    int sum = arr[left].first + arr[right].first;
    if (sum == x) {
      cout << arr[left].second + 1 << " " << arr[right].second + 1;
      return;
    } else if (sum > x) {
      right--;
    } else {
      left++;
    }
  }
  cout << "IMPOSSIBLE";
}

int main() { solve(); }
