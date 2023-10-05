class Solution {
public:
    int countPairs(vector<vector<int>>& coordinates, int k) {
        // int mp[100][100];
        unordered_map<int,unordered_map<int,int>>mp;
        int ans = 0;
        for(auto &x:coordinates){
            for(int xx = 0;xx<=100;xx++){
                if(mp.count(xx^x[0]) && mp[xx^x[0]].count((k-xx)^x[1]))ans += mp[xx^x[0]][(k-xx)^x[1]];
            }
            mp[x[0]][x[1]]++;
        }
        return ans;
    }
};