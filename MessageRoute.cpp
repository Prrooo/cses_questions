#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> connection(n + 1);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    connection[x].push_back(y);
    connection[y].push_back(x);
  }
  // i use parent to keep track of the parent element
  // so that i can backtrack from the n to 1
  // for the shortest path
  // i can also use vector<int> parent(n+1,-1);
  // use or try vector if try in future
  unordered_map<int, int> parent;
  vector<bool> vis(n + 1, false);
  queue<int> qu;
  qu.push(1);
  vis[1] = true;
  while (!qu.empty()) {
    int top = qu.front();
    qu.pop();
    for (auto i : connection[top]) {
      if (!vis[i]) {
        parent[i] = top;
        qu.push(i);
        vis[i] = true;
      }
      if (i == n)
        break;
    }
  }
  if (parent.find(n) == parent.end())
    cout << "IMPOSSIBLE";
  else {
    vector<int> nums;
    int start = n;
    while (parent.find(start) != parent.end()) {
      nums.push_back(start);
      start = parent[start];
    }
    int sz = nums.size();
    cout << sz + 1 << endl;
    cout << 1 << " ";
    for (int i = sz - 1; i >= 0; i--) {
      cout << nums[i] << " ";
    }
  }
  return 0;
}
