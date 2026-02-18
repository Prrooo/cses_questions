#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> weight(n);
  for (auto &i : weight) {
    cin >> i;
  }
  sort(weight.begin(), weight.end());
  int i = 0, j = n - 1, ans = 0;
  while (i < j) {
    if (weight[i] + weight[j] <= x) {
      ans++;
      i++;
      j--;
    } else {
      ans++;
      j--;
    }
  }
  if (i == j)
    ans++;
  cout << ans;
  return 0;
}
