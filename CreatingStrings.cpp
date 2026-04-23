#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

void using_inBuild_function() {
  string s;
  cin >> s;
  sort(s.begin(), s.end());

  // perms is a sorted list of all the permutations of the given string
  vector<string> perms;
  do {
    perms.push_back(s);
  } while (next_permutation(s.begin(), s.end()));

  cout << perms.size() << endl;
  for (const string &perm : perms) {
    cout << perm << endl;
  }
}

void solve(vector<int> &count, int index, int n, string s) {
  if (index >= n) {
    ans.push_back(s);
  }
  for (int i = 0; i < 26; i++) {
    if (count[i] != 0) {
      s.push_back(i + 'a');
      count[i]--;
      solve(count, index + 1, n, s);
      count[i]++;
      s.pop_back();
    }
  }
}

void brute_force_solution() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> count(26, 0);
  for (auto i : s)
    count[i - 'a']++;
  solve(count, 0, n, "");
  cout << ans.size() << endl;
  for (auto i : ans) {
    cout << i << endl;
  }
}

int main() {
  brute_force_solution();
  return 0;
}
