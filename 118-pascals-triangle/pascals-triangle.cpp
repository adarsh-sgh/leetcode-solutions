class Solution {
public:
    vector<vector<int>> generate(int numRows) {
       vector<vector<int>>ans = {{1}};
       for(int i = 1;i < numRows;i++){
        vector<int>curr;
        curr.push_back(1);
        for(int i = 0;i < ans.back().size() - 1;i++){
            curr.push_back(ans.back()[i] + ans.back()[i+1]);
        }
        curr.push_back(1);
        ans.push_back(curr);
       } 
       return ans;
    }
};