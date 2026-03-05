#include <bits/stdc++.h>
using namespace std;

// time complexity O(n^2)

void brute_force_solution(vector<pair<int, int>> &arr, int n) {
  sort(arr.begin(), arr.end(),
       [](pair<int, int> a, pair<int, int> b) { return a.second < b.second; });

  int ans = 0;

  for (int i = 0; i < n; i++) {
    int count = 1, temp = arr[i].second;
    for (int j = i + 1; j < n; j++) {
      if (arr[j].first >= temp) {
        temp = arr[j].second;
        count++;
      }
    }
    ans = max(ans, count);
  }
  cout << ans;
}

int main() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  vector<pair<int, int>> arr;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    arr.push_back({x, y});
  }
  // effective solution
  // time complexity O(nlogn)
  sort(arr.begin(), arr.end(), [](pair<int, int> &a, pair<int, int> &b) {
    return a.second < b.second;
  });
  int count = 1, temp = arr[0].second;
  for (int i = 1; i < n; i++) {
    if (arr[i].first >= temp) {
      count++;
      temp = arr[i].second;
    }
  }
  cout << count;
  return 0;
}
