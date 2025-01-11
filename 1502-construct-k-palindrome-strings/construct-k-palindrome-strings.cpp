class Solution {
public:
    bool canConstruct(string s, int k) {
        // k <= s.length()
        // pairs -> pc
        // individual -> ic(<=26)
        // ic > k -> false
        vector<int>v(26);
        for(auto &c:s){
            v[c-'a']++;
        }
        int ic = 0;
        for(auto &x:v){
            ic += x % 2;
        }
        return ic <= k && s.size() >= k;
    }
};