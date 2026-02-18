#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> app(n);
  vector<int> apt(m);
  for (auto &i : app) {
    cin >> i;
  }
  for (auto &i : apt) {
    cin >> i;
  }
  sort(app.begin(), app.end());
  sort(apt.begin(), apt.end());

  int i = 0, j = 0, ans = 0;
  while (i < n && j < m) {
    if (abs(app[i] - apt[j]) <= k) {
      ans++;
      i++;
      j++;
    } else if (app[i] < apt[j] + k) {
      i++;
    } else {
      j++;
    }
  }
  cout << ans;
  return 0;
}
