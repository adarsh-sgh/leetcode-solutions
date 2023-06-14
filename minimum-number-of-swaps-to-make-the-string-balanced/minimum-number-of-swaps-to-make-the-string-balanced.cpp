class Solution {
public:
    int minSwaps(string s) {
        int ans = 0;
        int o = 0,c = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]=='[')o++;
            else c++;
            // ans = max(ans,c-o);
            if(c>o){
                swap(c,o);
                ans++;
            }
        }
        return ans;
    }
};