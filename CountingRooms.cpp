// You are given a map of a building, and your task is to count the number of
// its rooms. The size of the map is n \times m squares, and each square is
// either floor or wall. You can walk left, right, up, and down through the
// floor squares. Input The first input line has two integers n and m: the
// height and width of the map. Then there are n lines of m characters
// describing the map. Each character is either . (floor) or # (wall). Output
// Print one integer: the number of rooms.
// Constraints
//
// 1 \le n,m \le 1000
//
// Example
// Input:
// 5 8
// ########
// #..#...#
// ####.#.#
// #..#...#
// ########
//
// Output:
// 3

#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> nums;
vector<pair<int, int>> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

void solve(vector<vector<char>> &nums, vector<vector<bool>> &vis, int i, int j,
           int n, int m) {
  if (i < 0 || i >= n || j < 0 || j >= m)
    return;
  else if (vis[i][j] || nums[i][j] == '#')
    return;
  vis[i][j] = true;
  solve(nums, vis, i, j - 1, n, m);
  solve(nums, vis, i, j + 1, n, m);
  solve(nums, vis, i - 1, j, n, m);
  solve(nums, vis, i + 1, j, n, m);
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

  vector<vector<bool>> vis(n, vector<bool>(m, false));
  int count = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (nums[i][j] == '.' && !vis[i][j]) {
        count++;
        solve(nums, vis, i, j, n, m);
      }
    }
  }
  cout << count;
}

void dfs(int i, int j, int n, int m) {
  if (i < 0 || j < 0 || i >= n || j >= m)
    return;
  else if (nums[i][j] == '#')
    return;
  nums[i][j] = '#';
  for (auto [x, y] : direction) {
    dfs(i + x, j + y, n, m);
  }
}

void better_solution() {
  int n, m;
  cin >> n >> m;
  // vector<vector<char>> nums;
  for (int i = 0; i < n; i++) {
    vector<char> temp;
    for (int j = 0; j < m; j++) {
      char x;
      cin >> x;
      temp.push_back(x);
    }
    nums.push_back(temp);
  }

  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (nums[i][j] == '.') {
        count++;
        dfs(i, j, n, m);
      }
    }
  }
  cout << count;
}

int main() { better_solution(); }
