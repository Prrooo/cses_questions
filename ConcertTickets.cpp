#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &price, int target, int n) {
  int left = 0, right = n - 1, ans = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (price[mid] <= target) {
      ans = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }
  return ans;
}

void TLE_solution() {
  int n, m;
  cin >> n >> m;
  vector<int> price(n);
  vector<int> customer(m);
  for (auto &i : price)
    cin >> i;
  for (auto &i : customer)
    cin >> i;
  sort(price.begin(), price.end());
  vector<int> vis(n, 0);
  for (int i = 0; i < m; i++) {
    int index = solve(price, customer[i], n);
    while (index >= 0 && vis[index] == 1) {
      index--;
    }
    if (index >= 0) {
      cout << price[index] << endl;
      vis[index] = 1;
    } else {
      cout << -1 << endl;
    }
  }
}

int main() {
  // work fine no TLE
  int n, m;
  cin >> n >> m;
  multiset<int> price;
  vector<int> customer(m);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    price.insert(x);
  }
  for (auto &i : customer)
    cin >> i;

  for (int i = 0; i < m; i++) {
    auto it = price.upper_bound(customer[i]);
    if (it == price.begin()) {
      cout << -1 << endl;
    } else {
      it--;
      cout << *it << endl;
      price.erase(it);
    }
  }

  return 0;
}
