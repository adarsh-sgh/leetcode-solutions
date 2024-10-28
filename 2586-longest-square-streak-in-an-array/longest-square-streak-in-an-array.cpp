class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       map<int,int>ans;
       int a = -2;
       for(auto &x:nums){
        if(x < 1e3)ans[x * x] = max(ans[x*x], ans[x] + 1);
        if(ans[x] > 0)a = max(a, ans[x]);
       } 
    //    for(auto &[x,y]:ans)cout<<x<<' '<<y<<endl;
       return a + 1;
    }
};