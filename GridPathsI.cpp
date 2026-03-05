// include tebular approach

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> dp;
int n;
const int MOD = 1e9 + 7;

int top_down_approach(vector<vector<char>> &grid, int x, int y) {
  if (x < 0 || x >= n || y < 0 || y >= n)
    return 0;
  else if (grid[x][y] == '*')
    return 0;
  else if (x == (n - 1) && y == (n - 1))
    return 1;
  if (dp[x][y] != -1)
    return dp[x][y];
  int right = top_down_approach(grid, x, y + 1);
  int down = top_down_approach(grid, x + 1, y);
  return dp[x][y] = (right + down) % MOD;
}

int main() {
  cin >> n;
  dp.assign(n, vector<int>(n, -1));
  vector<vector<char>> grid;
  for (int i = 0; i < n; i++) {
    vector<char> temp;
    for (int j = 0; j < n; j++) {
      char x;
      cin >> x;
      temp.push_back(x);
    }
    grid.push_back(temp);
  }
  cout << top_down_approach(grid, 0, 0);
  return 0;
}
