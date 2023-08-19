class Solution {
public:
    vector<int>parent;

int find(int a) {
  if (parent[a] == a) return a;
  return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
  parent[find(a)] = find(b);
}
int inf = 1e9 + 5;

int MST(vector<vector<int>>& edges, int n, int mi = -1) {
  // wt, n1 n2

  priority_queue <vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
  for (auto& e : edges) {
    pq.push({ e[2],e[0],e[1] });
  }
  parent.clear();
  parent.resize(n);
  for (int i = 0;i < n;i++)parent[i] = i;
  int res = 0;

  if (mi != -1) {
    Union(edges[mi][0], edges[mi][1]);
    res += edges[mi][2];
  }
  for (int i = 0;i < n - 1 - (mi != -1);) {
    if (pq.empty())return inf;
    auto t = pq.top();
    pq.pop();
    if (find(t[1]) == find(t[2])) continue;
    i++;
    Union(t[1], t[2]);
    res += t[0];
  }
  return res;
}

vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
  int wi = MST(edges, n);
  vector<set<int>>ans(2);
  for (int i = 0;i < edges.size();i++) {
    vector<vector<int>>ec;
    //remove ith edge
    for (int j = 0;j < edges.size();j++) {
      if (j != i) ec.push_back(edges[j]);
    }
    int wn = MST(ec, n);
    if (wn > wi)ans[0].insert(i);
  }
  for (int mi = 0;mi < edges.size();mi++) {
    if (ans[0].count(mi))continue;
    int gg = MST(edges, n, mi);
    if (gg == wi)ans[1].insert(mi);
  }
  vector<vector<int>>res;
  res.push_back(vector<int>(ans[0].begin(), ans[0].end()));
  res.push_back(vector<int>(ans[1].begin(), ans[1].end()));
  return res;
}
};