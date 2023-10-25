class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        set<int>q(queries.begin(),queries.end());
        sort(intervals.begin(),intervals.end(),[](auto a,auto b){return a[1]-a[0] < b[1] - b[0];});
        map<int,int>mp;
        for(auto &z:intervals){
            auto x = z[0], y = z[1];
            auto it = q.lower_bound(x);
            while(it != q.end() && *it <= y){
                mp[*it] = y-x + 1;
                it = q.erase(it);
            }
        }
        vector<int>ans;
        for(auto &q:queries)ans.push_back(mp.count(q)?mp[q]:-1);
        return ans;
    }
};