class Solution {
public:
    string shiftingLetters(string &s, vector<vector<int>>& shifts) {
        int n = s.size();
       vector<int>v(n+1);
       for(auto &&x:shifts){
        int dir = x[2] == 0 ? -1 : 1;
        v[x[0]]+=dir;
        v[x[1]+1]-= dir;
       }
       int sft = 0;
       for(int i = 0;i<n;i++){
        sft += v[i];
        sft %= 26;
        s[i] = 'a' + ((s[i] - 'a' + sft + 26) % 26);
       }
       return s;
    }
};