class Solution {
public:
#define dbg(...) 42;
    vector<int>parent;
int find(int n) {
  while (parent[n] != n) n = parent[n];
  return n;
  // if (parent[n] == n) return n;
  // return parent[n] = find(parent[n]);
}
void Union(int a, int b) {
  dbg(a, b);
  parent[find(a)] = find(b);
  // dbg(parent);
}
int largestComponentSize(vector<int>& nums) {
  map<int, int>ind;
  for (int i = 0;i < nums.size();i++) {
    ind[nums[i]] = i;
  }
  int n = nums.size();
  parent.resize(n);
  for (int i = 0;i < n;i++)parent[i] = i;
  dbg(parent, ind);
  int mxn = *max_element(nums.begin(), nums.end());
  vector<int>prime(mxn + 1, true);
  map<int, int>lead;
  for (int i = 2;i <= mxn;i++) {
    if (!prime[i])continue;
    for (int x = i;x <= mxn;x += i) {
      prime[x] = false;
      if (ind.count(x)) {
        if (lead.count(i))Union(ind[x], ind[lead[i]]);
        else lead[i] = x;
      }
    }
  }
  dbg(lead);
  map<int, int>sz;
  int ans = 0;
  dbg(parent, mxn, prime);
  for (int i = 0;i < n;i++) {
    sz[find(i)]++;
    ans = max(ans, sz[find(i)]);
  }
  return ans;
}
};