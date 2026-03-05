// There are n concert tickets available, each with a certain price. Then, m
// customers arrive, one after another. Each customer announces the maximum
// price they are willing to pay for a ticket, and after this, they will get a
// ticket with the nearest possible price such that it does not exceed the
// maximum price. Input The first input line contains integers n and m: the
// number of tickets and the number of customers. The next line contains n
// integers h_1,h_2,\ldots,h_n: the price of each ticket. The last line contains
// m integers t_1,t_2,\ldots,t_m: the maximum price for each customer in the
// order they arrive. Output Print, for each customer, the price that they will
// pay for their ticket. After this, the ticket cannot be purchased again. If a
// customer cannot get any ticket, print -1. Constraints
//
// 1 \le n, m \le 2 \cdot 10^5
// 1 \le h_i, t_i \le 10^9
//
// Example
// Input:
// 5 3
// 5 3 7 8 5
// 4 8 3
//
// Output:
// 3
// 8
// -1

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
