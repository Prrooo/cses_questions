#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int ans = 1, temp = 1;
  for (int i = 1; i < s.size(); i++) {
    if (s[i] == s[i - 1]) {
      temp++;
      ans = max(ans, temp);
    } else {
      temp = 1;
    }
  }
  cout << ans;
  return 0;
}
