class Solution {
public:
    int numRabbits(vector<int>& answers) {
       map<int,int>mp;
       int ans = 0;
       for(auto &x:answers){
        if(mp.count(x) && mp[x] > 0){
            mp[x]--;
        }else{
            mp[x] = x;
            ans += x + 1;
        }
       } 
       return ans;
    }
};