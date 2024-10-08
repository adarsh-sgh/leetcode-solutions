class Solution {
public:
    int minSwaps(string s) {
        int o = 0;
        int ans = 0;
        for(auto &c:s){
            if(c == '[') o++;
            else o--;
            if(o < 0){
                o+=2;
                ans++;
            }
        }    
        return ans;
    }
};