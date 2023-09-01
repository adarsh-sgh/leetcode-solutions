class Solution {
public:
   #define dbg(...) 42;
vector<int>parent;
int find(int n) {
  if (parent[n] == n) return n;
  return parent[n] = find(parent[n]);
}
void Union(int a, int b) {
  parent[find(a)] = find(b);
}

int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
  vector<array<int, 2>>both, bob, alice;
  for (auto& e : edges) {
    e[1]--, e[2]--;
    if (e[0] == 3) {
      both.push_back({ e[2],e[1] });
    }
    else if (e[0] == 2) {
      bob.push_back({ e[2],e[1] });
    }
    else {
      alice.push_back({ e[2],e[1] });
    }
  }
  vector<int>pcommon;
  for (int i = 0;i < n;i++)parent.push_back(i);
  int cnt = 0;
  for (auto&& e : both) {
    if (find(e[1]) == find(e[0]))continue;
    Union(e[0], e[1]);
    cnt++;
  }
  pcommon = parent;
  dbg(parent);
  dbg(both, alice, bob);
  for (auto& e : alice) {
    if (find(e[1]) == find(e[0]))continue;
    Union(e[0], e[1]);
    cnt++;
  }
  dbg(parent);
  for(int i = 1;i<n;i++){
      if(find(i) != find(0))return -1;
  }
  parent = pcommon;
  for (auto& e : bob) {
    if (find(e[1]) == find(e[0]))continue;
    Union(e[0], e[1]);
    cnt++;
  }
  for(int i = 1;i<n;i++){
      if(find(i) != find(0))return -1;
  }
  dbg(cnt);

  return edges.size() - cnt;

}
};