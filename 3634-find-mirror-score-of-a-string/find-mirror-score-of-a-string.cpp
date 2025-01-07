class Solution {
public:
    long long calculateScore(string s) {
        vector<vector<int>>v(26);
        long long ans = 0;
        for(int i = 0;i<s.size();i++){
            int ci = s[i] - 'a';
            int m = 'z' - s[i];
            if(v[m].empty()){
                v[ci].push_back(i);
            }else{
                ans += i - v[m].back();
                // v[m] = -1;
                v[m].pop_back();
            }
        }
        return ans;
    }
};