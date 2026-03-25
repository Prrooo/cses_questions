#include <bits/stdc++.h>
using namespace std;

void best_solution() {
  // write tommorow
}

void brute_force_solution() {
  int n;
  cin >> n;
  int count = 0;
  for (int i = 1; i * i <= n; i++) {
    if (n % i == 0)
      count += i * i == n ? 1 : 2;
  }
  cout << count << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    brute_force_solution();
  }
  return 0;
}
