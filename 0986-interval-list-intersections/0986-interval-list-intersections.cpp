class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>>ans;
        for(auto &&x:firstList){
            for(auto &&y:secondList){
                int st = max(x[0],y[0]);
                int en = min(x[1],y[1]);
                if(st<=en)ans.push_back({st,en});
            }
        }
        return ans;
    }
};