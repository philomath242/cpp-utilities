#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5;

vector<pair<int, int>> nodes[N];

int in[100000], out[100000];

// memoization of in array

void dfs1(int node, int parent) {
  int count = 0;
  for (int i = 0; i < nodes[node].size(); ++i) {
    int child = nodes[node][i].first;
    int value = nodes[node][i].second;
    if (child == parent)
      continue;

    count++;
    dfs1(child, node);

    in[node] = min(in[node], value + in[child]);
  }

  if (count == 0)
    in[node] = 0;
}

void dfs2(int node, int parent, map<pair<int, int>, int> &edges) {
  int max1 = INT_MAX, max2 = INT_MAX;

  for (int i = 0; i < nodes[node].size(); ++i) {
    int child = nodes[node][i].first;
    int value = nodes[node][i].second;
    if (child == parent)
      continue;
    if (in[child] + value <= max1)
      max2 = max1, max1 = in[child] + value;
    else if (in[child] + value < max2)
      max2 = in[child] + value;
  }

  for (int i = 0; i < nodes[node].size(); ++i) {
    int child = nodes[node][i].first;
    int value = nodes[node][i].second;
    if (child == parent)
      continue;
    int store = max1;
    if (max1 == in[child] + value)
      store = max2;
    out[child] = edges[{child, node}] + min(out[node], store);
    dfs2(child, node, edges);
  }
}

signed main() {

  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    in[i] = INT_MAX;
    out[i] = INT_MAX;
  }
  map<pair<int, int>, int> edges;

  for (int i = 0; i < n - 1; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    nodes[u].push_back({v, w});
    nodes[v].push_back({u, 0});
    edges[{u, v}] = w;
    edges[{v, w}] = 0;
  }
  dfs1(1, 0);
  dfs2(1, 0, edges);
  int res = INT_MAX;
  for (int i = 1; i <= n; ++i) {
    res = min(res, in[i] + out[i]);
  }

  cout << res << "\n";

  return 0;
}