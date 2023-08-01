class Solution {
public:
    
vector<int> findPeakGrid(vector<vector<int>>& mat) {
  // target row
  int tr = 0;
  
  int n = mat[0].size();
  int l = 0, r = n - 1;
  while (l <= r) {
    int peak = false;
    int m = (l + r) / 2;

    for (int i = 0;i < mat.size();i++) {
    if (mat[i][m] > mat[tr][m])tr = i;
    }  
    if (m == 0)peak = mat[tr][1] < mat[tr][0];
    else if (m == n - 1) return {tr,m}; 
    else peak = mat[tr][m - 1] < mat[tr][m] && mat[tr][m + 1] < mat[tr][m];
    if (peak) {
      return { tr,m };
    }
    else if (mat[tr][m] < mat[tr][m+1] ) {
      l = m+1;
    }else{
      r = m -1;
    }
  }
  return {tr,l};
}
};