class Solution {
public:
#define dbg(...) 3;
vector<int> parent;
int find(int x) {
  while (parent[x] != x) {
    x = parent[x];
  }
  return x;
}
void Union(int x, int y) {
  parent[find(x)] = find(y);
}

long long int costToEqual(vector<int>& v) {
  sort(v.begin(), v.end());
  int m1 = v[v.size() / 2];
  int m2 = v[(v.size() - 1) / 2];

  long long cst1 = 0;
//   long long cst2 = 0;
  dbg(m1, m2);
  for (auto&& x : v) {
    cst1 += 1ll * abs(x - m1);
    // cst2 += 1ll * abs(x - m2);
    // dbg(cst1, cst2);
  }
//   return min(cst1, cst2);
return cst1;
}

long long makeSubKSumEqual(vector<int>& arr, int k) {
  int n = arr.size();
  parent.resize(n);
  for (int i = 0;i < n;i++) parent[i] = i;
  for (int i = 0;i < n;i++) {
    // dbg(i, (i + k) % n);
    Union(i, (i + k) % n);
  }
  map<int, vector<int>>m;
  for (int i = 0;i < n;i++) {
    m[find(i)].push_back(arr[i]);
  }
  long long ans = 0;
  // dbg(m);
  // dbg(costToEqual({ 1,3 }));
  for (auto&& x : m) {
    long long cst = costToEqual(x.second);
    // dbg(x, cst);
    ans += cst;
  }
  return ans;
}

};