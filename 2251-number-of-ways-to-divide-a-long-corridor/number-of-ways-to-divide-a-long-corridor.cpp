class Solution {
public:
// copied from old submission
    int numberOfWays(string c) {
       vector<int>sofa;
       for(int i = 0;i<c.size();i++){
           if(c[i] == 'S') sofa.push_back(i);
       }
       if(sofa.size() % 2 || !sofa.size()) return 0;
       long long ways = 1;
       int MOD = 1e9 + 7;
       for(int i = 1;i<sofa.size() - 2;i+=2){
           ways *= sofa[i+1] - sofa[i];
           ways %= MOD;
       }
       return ways;
    }
};