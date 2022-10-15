#include <bits/stdc++.h>
using namespace std;

int main() {

  cin.tie(0);
  cout.tie(0);

  int n, k;
  cin >> n >> k;

  if (n < k)
    return -1;

  vector<pair<int, int>> pairs;
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    pairs.emplace_back(a, b);
  }

  sort(pairs.begin(), pairs.end(), [](pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
  });

  multiset<int> greater, smaller;

  int smaller_sum = 0, greater_sum = 0;
  for (int i = 0; i < k; ++i) {
    greater.insert(pairs[i].first);
    greater_sum += pairs[i].first;
  }

  while (smaller.size() < (k / 2)) {
    auto itr = greater.begin();
    smaller_sum += (*itr);
    greater_sum -= (*itr);
    smaller.insert(*itr);
    greater.erase(itr);
  }

  int res = (greater_sum - smaller_sum) * pairs[k - 1].second;
  for (int j = k; j < n; ++j) {
    auto itr1 = greater.begin();
    auto itr2 = smaller.end();
    itr2--;
    if (pairs[j].first < *itr1 && pairs[j].first > *itr2) {
      continue;
    }
    if (pairs[j].first > *itr1) {
      greater_sum += pairs[j].first - *itr1;
      greater.erase(*itr1);
      greater.insert(pairs[j].first);

    } else {
      smaller_sum += pairs[j].first - *itr2;
      smaller.erase(*itr2);
      smaller.insert(pairs[j].first);
    }
    res = max(res, (greater_sum - smaller_sum) * pairs[j].second);
  }

  cout << res << "\n";

  return 0;
}