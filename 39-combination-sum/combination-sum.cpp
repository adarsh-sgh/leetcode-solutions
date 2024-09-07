class Solution {
public:
    void solve(int i, int tleft, vector<int>& cand, vector<vector<int>>& ans,
               vector<int>& curr) {
        if (i == cand.size()) {
            if (tleft == 0) {
                vector<int> ccp = curr;
                ans.push_back(ccp);
            }
            return;
        }
        solve(i + 1, tleft, cand, ans, curr);

        if (tleft >= cand[i]) {
            curr.push_back(cand[i]);
            solve(i, tleft - cand[i],cand, ans, curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>curr = {};
        solve(0,target,candidates,ans,curr);
        return ans;
    }
};