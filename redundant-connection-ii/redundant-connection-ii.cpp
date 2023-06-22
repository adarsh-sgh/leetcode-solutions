class Solution {
public:
    #define dbg(...) 42;
    vector<int>parent;
    int find(int a){
        while(parent[a] != a){
            a = parent[a];
        }
        return a;
    }

    void Union(int a,int b){
        parent[find(a)] = find(b);
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
  int n = edges.size();
  parent.resize(n + 1);
  for (int i = 1;i <= n;i++) parent[i] = i;
  vector<int>p(n + 1, -1);
  vector<vector<int>>can;
  for (auto&& e : edges) {
    if (p[e[1]] != -1) {
      can.push_back({ p[e[1]],e[1] });
      can.push_back(e);
    }
    p[e[1]] = e[0];
  }
//   swap(can[0],can[1]);
  dbg(can);
  assert(can.size() <= 2);
  for (auto&& x : edges) {
    if (find(x[0] == find(x[1]))) {
    //   assert(can.empty());
      if(can.empty())return x;
      else return can[0];
    }
    if (can.empty() || ( x != can[1]))Union(x[0], x[1]);
    // if (can.size() &&find(x[0]) == find(can[0][0])) {
    //   return can[0];
    // }
    // if (can.size()&& find(x[0]) == find(can[1][0])) return can[1];
  }
  if (can.size())return can[1];
  return { -1,-1 };
}
};