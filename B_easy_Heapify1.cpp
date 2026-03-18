#include <bits/stdc++.h>
using namespace std;

void brute_force() {
  int n;
  cin >> n;
  vector<int> nums;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    nums.push_back(x);
  }
  bool flag = true;
  for (int i = n / 2; i < n; i++) {
    if ((i + 1) % 2 != 0 && nums[i] != (i + 1)) {
      flag = false;
    }
  }
  if (flag) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    brute_force();
  }
  return 0;
}
