class Solution {
public:
    int countPalindromicSubsequence(string s) {
       // ans <= 26 * 26  
       // note first and last index for each char say i1, i2
       // check all chars that exist bw these indices and they'll be part of pal.
       set<string>pals;
       vector<vector<int>>pf(s.size() + 1, vector<int>(26));
       vector<array<int,2>>oc(26,{-1,-1});
       for(int i = 0;i < s.size();i++){
        int ci = s[i] - 'a';
        for(int j = 0;j<26;j++){
          pf[i+1][j] = pf[i][j] + (j == ci);
        }
        if(oc[ci][0] == -1)oc[ci][0] = i;
        oc[ci][1] = i;
       }
       for(int i = 0;i<26;i++){
        auto [i1,i2] = oc[i];
        if(i1 == -1 || i2 == -1 || abs(i1 - i2) < 2)continue;
        for(int j = 0;j< 26;j++){
            // [i1 + 1 se i2 - 1] ke beech j aaya hai agar
            if(pf[i2][j] != pf[i1+1][j]){
                string x;
                x += 'a' + i;
                x+= 'a' + j;
                pals.insert(x);
            }
        }
       }
    //    for(auto &p:pals)cout<<p<<' ';
       return pals.size();
    }
};