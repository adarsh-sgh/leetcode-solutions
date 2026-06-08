class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
       map<int,int>mp; 
       int ans = 0;
       for(auto &x:time){
        int r = x % 60;
        // find count of (60-r) % 60
        ans += mp[(60 - r) % 60];
        mp[r]++;
       }
       return ans;
    }
};