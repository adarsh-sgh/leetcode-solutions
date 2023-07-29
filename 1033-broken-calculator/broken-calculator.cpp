class Solution {
public:
    map<int,int>dp;
    int t ;
    int inf = 1e8;
    int bc(int s){
        if(s>=t)return s-t;
        if(s<=0)return inf;
        if(dp.count(s))return dp[s];
        dp[s] = inf;
        return dp[s] = 1 + min(bc(2*s),bc(s-1));
    }
    int brokenCalc(int startValue, int target) {
        t = target;
        int ans = 0;
        while(target!=startValue){
            if(target < startValue){
                ans += startValue - target;
                break;
            }
            if(target&1)target++;
            else target/=2;
            ans++;
        }
        return ans;


        // return bc(startValue);
    }
};