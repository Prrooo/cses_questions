#include <bits/stdc++.h>
#include <climits>
using namespace std;

int MOD = 1e9 + 7;

void brute_force_solution() {
  int n;
  cin >> n;

  vector<int> arr(n);
  for (auto &x : arr)
    cin >> x;

  vector<bool> vis(n, false);
  long long lcm = 1;

  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      int curr = i;
      int len = 0;

      while (!vis[curr]) {
        vis[curr] = true;
        curr = arr[curr] - 1;
        len++;
      }

      lcm = (lcm / gcd(lcm, (long long)len)) * len;
    }
  }

  cout << lcm % MOD << "\n";
}

int main() {
  brute_force_solution();
  return 0;
}
