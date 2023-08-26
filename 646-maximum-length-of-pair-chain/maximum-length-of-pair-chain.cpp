class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](auto p1,auto p2){
            return p1[1] < p2[1];
        });
        int ans = 0,lastEnd = INT_MIN;
        for(int i = 0;i<pairs.size();i++){
            if(pairs[i][0] > lastEnd){
                ans++;
                lastEnd = pairs[i][1];
            }
        }
        return ans;
    }
};