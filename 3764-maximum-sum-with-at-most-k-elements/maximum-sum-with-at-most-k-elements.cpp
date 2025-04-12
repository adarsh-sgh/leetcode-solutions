class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
       vector<int>v;
       for(int i = 0;i< grid.size();i++){
        sort(grid[i].rbegin(), grid[i].rend());
        for(int j = 0;j < grid[0].size();j++){
           if(limits[i]-- > 0){
            v.push_back(grid[i][j]);
           } 
        }
       } 
       sort(v.rbegin(), v.rend());
       long long ans = 0;
       for(int i = 0;i< k;i++){
        ans += v[i];
       }
       return ans;
    }
};