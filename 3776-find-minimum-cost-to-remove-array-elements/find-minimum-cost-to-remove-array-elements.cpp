class Solution {
public:
    vector<int>v;
    vector<vector<int>>dp;
    // min cost to kill all elements on and after i
    // if ext is also sitting there to kill
    int inf = 1e9;
    int mc(int ext, int i){
        int vext = v[ext];
       if(i == v.size())return vext; 
       if(i == v.size() - 1) return max(vext, v.back());
       int &cst = dp[ext][i];
       if(cst != -1) return cst;
       cst = inf;
       // kill i and ext
       cst = min(max(vext, v[i]) + mc(i+1, i+2), cst);
       // kill i and i + 1 (not i can't be last element, we handled that above)
       cst = min(cst, max(v[i], v[i+1]) + mc(ext, i+2));
       // kill ext and i + 1
       cst = min(cst, max(vext, v[i+1]) + mc(i, i + 2));
       return cst;
    }
    int minCost(vector<int>& nums) {
       v = nums; 
       int n = nums.size();
       dp.resize(n+1, vector<int>(n+1, -1));
       return mc(0, 1);
    }
};