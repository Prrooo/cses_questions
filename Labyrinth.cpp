#include <bits/stdc++.h>
#include <climits>
using namespace std;

vector<pair<int, int>> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
vector<char> dir_char = {'L', 'R', 'U', 'D'};

pair<int, string> solve(vector<vector<char>> &nums, int i, int j, int n, int m,
                        vector<vector<pair<int, string>>> &dp) {
  if (i < 0 || j < 0 || i >= n || j >= m)
    return {INT_MAX, ""};
  else if (nums[i][j] == '#')
    return {INT_MAX, ""};
  else if (nums[i][j] == 'B') {
    return {0, ""};
  }
  if (dp[i][j].first != INT_MAX)
    return dp[i][j];
  nums[i][j] = '#';
  pair<int, string> ans = {INT_MAX, ""};
  for (int k = 0; k < 4; k++) {
    int x = direction[k].first;
    int y = direction[k].second;
    pair<int, string> temp = solve(nums, i + x, j + y, n, m, dp);
    if (temp.first != INT_MAX) {
      temp.first++;
      temp.second = dir_char[k] + temp.second;
      if (temp.first < ans.first) {
        ans = temp;
      }
    }
  }
  nums[i][j] = '.';
  return dp[i][j] = ans;
}

void brute_force_solution() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> nums;
  for (int i = 0; i < n; i++) {
    vector<char> temp;
    for (int j = 0; j < m; j++) {
      char x;
      cin >> x;
      temp.push_back(x);
    }
    nums.push_back(temp);
  }

  vector<vector<pair<int, string>>> dp(
      n, vector<pair<int, string>>(m, {INT_MAX, ""}));

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (nums[i][j] == 'A') {
        pair<int, string> ans = solve(nums, i, j, n, m, dp);
        if (ans.first == INT_MAX) {
          cout << "NO";
        } else {
          cout << "YES" << endl;
          cout << ans.first << endl;
          cout << ans.second;
        }
        return;
      }
    }
  }
}

int main() {
  brute_force_solution();
  return 0;
}
