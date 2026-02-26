// https://cses.fi/problemset/task/1635/

// Consider a money system consisting of n coins. Each coin has a positive
// integer value. Your task is to calculate the number of distinct ways you can
// produce a money sum x using the available coins. For example, if the coins
// are \{2,3,5\} and the desired sum is 9, there are 8 ways:
//
// 2+2+5
// 2+5+2
// 5+2+2
// 3+3+3
// 2+2+2+3
// 2+2+3+2
// 2+3+2+2
// 3+2+2+2
//
// Input
// The first input line has two integers n and x: the number of coins and the
// desired sum of money. The second line has n distinct integers
// c_1,c_2,\dots,c_n: the value of each coin. Output Print one integer: the
// number of ways modulo 10^9+7. Constraints
//
// 1 \le n \le 100
// 1 \le x \le 10^6
// 1 \le c_i \le 10^6
//
// Example
// Input:
// 3 9
// 2 3 5
//
// Output:
// 8

#include <bits/stdc++.h>
#include <climits>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
  int n, x;
  cin >> n >> x;
  vector<int> coins(n);
  for (auto &i : coins)
    cin >> i;
  vector<long long> dp(x + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= x; i++) {
    for (int j = 0; j < n; j++) {
      if (coins[j] <= i) {
        // dp[i] += dp[i - coins[j]];
        dp[i] = (dp[i] + dp[i - coins[j]]) % MOD;
      }
    }
  }
  cout << dp[x];
  return 0;
}
