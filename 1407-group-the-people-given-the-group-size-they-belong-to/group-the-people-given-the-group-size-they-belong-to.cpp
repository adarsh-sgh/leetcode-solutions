class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        int n = groupSizes.size();
        vector<vector<vector<int>>>mp(n+1);
        for(int i = 0;i< groupSizes.size();i++){
            int &gsi = groupSizes[i];
            if(mp[gsi].empty()||mp[gsi].back().size()==gsi){
                mp[gsi].push_back({});
            }
            mp[gsi].back().push_back(i);
        }
        vector<vector<int>>ans;
        for(auto &&v:mp){
            for(auto &&x:v)
                ans.push_back(x);
        }
        return ans;
    }
};