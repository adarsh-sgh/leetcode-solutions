class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans{{1}};
        for(int i = 1;i<numRows;i++){
            vector<int>curr;
            auto &v = ans.back();
            curr.push_back(v[0]);
            for(int i = 0;i<v.size() - 1;i++){
                curr.push_back(v[i] + v[i+1]);
            }
            curr.push_back(v.back());
            ans.push_back(curr);
        }
        return ans;
    }
};