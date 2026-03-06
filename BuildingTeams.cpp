// There are n pupils in Uolevi's class, and m friendships between them. Your
// task is to divide the pupils into two teams in such a way that no two pupils
// in a team are friends. You can freely choose the sizes of the teams. Input
// The first input line has two integers n and m: the number of pupils and
// friendships. The pupils are numbered 1,2,\dots,n. Then, there are m lines
// describing the friendships. Each line has two integers a and b: pupils a and
// b are friends. Every friendship is between two different pupils. You can
// assume that there is at most one friendship between any two pupils. Output
// Print an example of how to build the teams. For each pupil, print "1" or "2"
// depending on to which team the pupil will be assigned. You can print any
// valid team. If there are no solutions, print "IMPOSSIBLE". Constraints
//
// 1 \le n \le 10^5
// 1 \le m \le 2 \cdot 10^5
// 1 \le a,b \le n
//
// Example
// Input:
// 5 3
// 1 2
// 1 3
// 4 5
//
// Output:
// 1 2 2 1 2

#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> conn;
vector<bool> vis;
vector<int> team;

bool dfs(int node, int color) {
  vis[node] = true;
  team[node] = color;

  for (auto child : conn[node]) {

    if (!vis[child]) {
      if (!dfs(child, color == 1 ? 2 : 1))
        return false;
    } else if (team[child] == team[node]) {
      return false;
    }
  }

  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  conn.resize(n + 1);
  vis.assign(n + 1, false);
  team.resize(n + 1, 0);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    conn[x].push_back(y);
    conn[y].push_back(x);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i] && !dfs(i, 1)) {
      cout << "IMPOSSIBLE";
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << team[i] << " ";
  }
  return 0;
}
