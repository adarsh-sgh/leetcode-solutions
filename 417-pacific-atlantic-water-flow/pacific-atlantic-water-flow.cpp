class Solution {
public:
#define dbg(...) 42
 // repeated submission
vector<vector<int>> h;
vector<int> d = {-1, 0, 1, 0, -1};
// bool pacific = true;
int m, n;
void dfs(int i, int j, vector<vector<int>> &g)
{
  if (i < 0 || j < 0 || i >= g.size() || j >= g[0].size() || g[i][j] >= 1)
  {
    return;
  }
  // dbg(i, j);

  g[i][j]++;
  for (int k = 0; k < 4; k++)
  {
    // check segmentation fault

    if (i + d[k] >= 0 && i + d[k] < m && j + d[k + 1] >= 0 && j + d[k + 1] < n && h[i + d[k]][j + d[k + 1]] >= h[i][j])
      dfs(i + d[k], j + d[k + 1], g);
  }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
  h = heights;
  m = heights.size();
  n = heights[0].size();
  vector<vector<int>> pacific(m, vector<int>(n));
  vector<vector<int>> atlantic(m, vector<int>(n));
  // g.resize(m, vector<int>(n));
  // g = &pacific;

  for (int i = 0; i < m; i++)
  {
    dfs(i, 0, pacific);
    // pacific = false;
    // dfs(i, n - 1);
  }
  for (int j = 0; j < n; j++)
  {
    // dfs(m - 1, j);
    // pacific = true;
    dfs(0, j, pacific);
  }
  // cout << g << endl;
  // g = &atlantic;
  for (int i = 0; i < m; i++)
  {
    dfs(i, n - 1, atlantic);
  }
  for (int j = 0; j < n; j++)
  {
    dfs(m - 1, j, atlantic);
  }

  vector<vector<int>> ans;
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (pacific[i][j] >= 1 && atlantic[i][j])
      {
        ans.push_back({i, j});
      }
    }
  }
  // cout << g << endl;
//   cout << pacific << endl;
//   cout << atlantic << endl;
  dbg(ans.size());
  return ans;
}
};