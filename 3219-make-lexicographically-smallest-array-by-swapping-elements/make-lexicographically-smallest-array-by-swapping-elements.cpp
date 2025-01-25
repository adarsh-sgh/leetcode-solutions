class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
       // divide array into groups
       // all elements in a group can be rearranged 
       vector<array<int,2>>v;
       for(int i = 0;i< nums.size();i++){
        v.push_back({nums[i], i});
       } 
       sort(v.begin(), v.end());

      vector<vector<array<int,2>>>vg = {
        {v[0]}
      };

      for(int i = 1;i< v.size();i++){
        if(v[i][0] - v[i-1][0] > limit){
            vg.push_back({});
        }
        vg.back().push_back(v[i]);
      }
      for(auto &g:vg){
        vector<int>indices;
        for(auto &e:g){
            indices.push_back(e[1]);
        }
        sort(indices.begin(), indices.end());
        for(int i = 0;i< g.size();i++){
            g[i][1] = indices[i];
        }
      }
      vector<int>ans(nums.size());
      for(auto &g:vg){
        for(auto &e:g){
            ans[e[1]] = e[0];
        }
      }
      return ans;
    }
};