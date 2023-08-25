class Solution {
public:
 
bool isInterleave(string s1, string s2, string s3)
{

  if (s1.length() + s2.length() != s3.length())
  {
    return false;
  }
  if (s1 == "" && s2 == "")
    return true;
  vector<vector<int>> v(s1.size() + 1, vector<int>(s2.size() + 1, 0));

  for (int i = 0; i <= s1.size(); i++)
  {
    for (int j = 0; j <= s2.size(); j++)
    {
      if (i == 0 && j == 0)
        v[i][j] = 1;
      else if (i == 0)
      {
        v[i][j - 1] && s2[j - 1] == s3[i + j - 1] && (v[i][j] = 1);
      }
      else if (j == 0)
        v[i - 1][j] && s1[i - 1] == s3[i + j - 1] && (v[i][j] = 1);
      else
        (v[i][j - 1] && s2[j - 1] == s3[i + j - 1] && (v[i][j] = 1)) || (v[i - 1][j] && s1[i - 1] == s3[i + j - 1] && (v[i][j] = 1));
    }
  }
  // cout << v;
  return v[s1.length()][s2.length()];
}

};