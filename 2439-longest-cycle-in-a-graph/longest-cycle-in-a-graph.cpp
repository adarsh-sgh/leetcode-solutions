class Solution {
public:
#define dbg(...) 42;
    vector<array<int, 2>>tm;
int n;
int ans = -1;
vector<int>ed;
void dfs(int x, int t) {
  dbg(x, t, tm);
  if(x==-1) return;
  if (tm[x][0] != -1) {
    if (tm[x][1] != -1) return;
    int clen = t - tm[x][0];
    dbg(clen);
    ans = max(ans, clen);
    return;
  }
  tm[x][0] = t;
  dfs(ed[x], t + 1);
  tm[x][1] = 1;
}

int longestCycle(vector<int>& edges) {
  n = edges.size();
  ed = edges;
  tm = vector<array<int, 2>>(n, { -1,-1 });
  for (int i = 0;i < n;i++) {
    dfs(i, 0);
  }
  return ans;
}

};