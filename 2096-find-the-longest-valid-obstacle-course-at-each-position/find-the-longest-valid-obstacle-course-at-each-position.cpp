class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        //lis[x] -> longest subsequence ending at no. x
        vector<int>lis;
        vector<int>ans(n);
        for(int i = 0;i<obstacles.size();i++){
            auto in = upper_bound(lis.begin(),lis.end(),obstacles[i]) - lis.begin();
            if(in == lis.size())lis.push_back(obstacles[i]);
            else lis[in] = obstacles[i];
            ans[i] = in + 1;
        }
        return ans;
    }
};