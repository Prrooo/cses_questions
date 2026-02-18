#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (auto &i : arr) {
    cin >> i;
  }

  sort(arr.begin(), arr.end());

  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (arr[i] != arr[i - 1]) {
      ans++;
    }
  }
  cout << ans;

  // one way using set
  // set<int> st;
  // for (int i = 0; i < n; i++) {
  //   int x;
  //   cin >> x;
  //   st.insert(x);
  // }
  // cout << st.size();
  return 0;
}
