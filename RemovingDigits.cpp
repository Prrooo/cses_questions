#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  if (n == 0)
    return n;
  vector<int> dp(n + 1, 0);
  for (int i = 1; i <= n; i++) {
    int maxNo = 0, temp = i;
    while (temp > 0) {
      maxNo = max(maxNo, temp % 10);
      temp = temp / 10;
    }
    dp[i] = dp[i - maxNo] + 1;
  }
  cout << dp[n];
  return 0;
}
