class Solution {
public:
    string getSmallestString(int n, int k) {
        string ans = string(n,'a');
        k-=n;
        for(int i = n-1;i>=0 && k > 0;i--){
            int give = min(k,25);
            k-=give;
            ans[i]+= give;
        }
        return ans;
    }
};