#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
using ll = long long;

int n;
vector<long long> weights;

// also important solution
void bitmask_solution() {
  int n;
  cin >> n;
  vector<ll> weights(n);
  for (ll &w : weights) {
    cin >> w;
  }

  ll ans = INT64_MAX;
  for (int mask = 0; mask < (1 << n); mask++) {
    ll sum1 = 0;
    ll sum2 = 0;
    for (int i = 0; i < n; i++) {
      // Check if the ith bit is toggled
      if (mask & (1 << i)) {
        // If it is, the apple is included in sum1
        sum1 += weights[i];
      } else {
        sum2 += weights[i];
      }
    }
    ans = min(ans, abs(sum1 - sum2));
  }

  cout << ans << endl;
}

// using both set
// another way to solve this problem
ll recurse_apples(int index, ll sum1, ll sum2) {
  // We've added all apples- return the absolute difference
  if (index == n) {
    return abs(sum1 - sum2);
  }

  // Try adding the current apple to either the first or second set
  return min(recurse_apples(index + 1, sum1 + weights[index], sum2),
             recurse_apples(index + 1, sum1, sum2 + weights[index]));
}

void solve(vector<int> &arr, int n, long long total, long long curr,
           long long &ans, int i) {
  if (i >= n) {
    long long second = total - curr;
    ans = min(ans, llabs(second - curr));
    return;
  }
  solve(arr, n, total, curr, ans, i + 1);
  solve(arr, n, total, curr + arr[i], ans, i + 1);
}

void brute_force_soltuion() {
  int n;
  cin >> n;
  vector<int> arr;
  long long total = 0;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
    total += x;
  }

  long long ans = INT_MAX, curr = 0;

  solve(arr, n, total, 0, ans, 0);
  cout << ans;
}

int main() {
  brute_force_soltuion();
  return 0;
}
