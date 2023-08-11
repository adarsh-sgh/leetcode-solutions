class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // multiset<int>ms;
        int j = 0;
        int ans = 0;
        for(int i = 0;i<s.size();i++){
            maxCost -= abs(s[i]-t[i]);
            while(maxCost < 0){
                maxCost += abs(s[j]-t[j]);
                j++;
            }
            ans = max(ans,i-j+1);
        }
        return ans;
    }
};