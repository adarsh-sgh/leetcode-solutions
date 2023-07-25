class Solution {
public:
#define dbg(...) 42;
vector<int>parent;
int find(int a) {
  if (parent[a] == a)return a;
  return parent[a] = find(parent[a]);
}

void Union(int a, int b) {
  parent[find(a)] = find(b);
}
   string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
  int n = s.size();
  parent.resize(n);
  for (int i = 0;i < n;i++)parent[i] = i;
  for (auto&& p : pairs) {
    Union(p[0], p[1]);
  }
  map<int, vector<int>> m;
  for (int i = 0;i < n;i++) {
    m[find(i)].push_back(s[i]);
  }
  dbg(m);
  for (auto&& [x, y] : m) {
    sort(y.begin(), y.end(), greater<int>());
  }
  string ans;
  for (int i = 0;i < s.size();i++) {
    ans.push_back(m[find(i)].back());
    m[find(i)].pop_back();
  }
  return ans;
}
};