#include <bits/stdc++.h>
using namespace std;

bool valid(int length, string s, int k) {
  int n = s.length();
  int num_zeros = 0, num_ones = 0;
  int nsubsequences = 0, res = 0;

  for (int i = 0; i < length; ++i) {
    if (s[i] == '0') {
      num_zeros++;

    } else {
      nsubsequences += num_zeros;
      num_ones++;
    }
  }

  res = nsubsequences;

  for (int j = length; j < n; ++j) {
    int removed_index = j - length;
    if (s[removed_index] == '0') {
      nsubsequences -= num_ones;
      num_zeros--;
    } else {
      num_ones--;
    }
    if (s[j] == '1') {
      nsubsequences += num_zeros;
      num_ones++;
    } else {
      num_zeros++;
    }
    res = max(res, nsubsequences);
  }
  if (res >= k)
    return true;
  else
    return false;
}

int main() {

  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;

  string s;
  cin >> s;
  // `ans` will store the  length of shortest such substring
  int start = 0, end = n, ans = 1;

  // binary search in range [0, s.size()]
  while (start <= end) {
    int mid = start + (end - start) / 2;

    // if a substring of length mid has `k` '01' subsequences
    // update `ans` and look in [start, mid - 1]
    if (valid(mid, s, k))
      ans = mid, end = mid - 1;
    // else look in [mid + 1, end]
    else
      start = mid + 1;
  }

  cout << ans << "\n";

  return 0;
}