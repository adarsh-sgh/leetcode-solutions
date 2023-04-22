class Solution {
public:
    bool isVowel(char c){
        return c=='a' || c=='e'||c=='i'||c=='o'||c=='u';
    }
    int maxVowels(string s, int k) {
        int n = s.size();
        int cnt = 0;
        int ans = cnt;
        for(int i = 0;i<n;i++){
           cnt+=isVowel(s[i]);
           if(i-k >= 0){
               cnt -= isVowel(s[i-k]);
           }
           ans = max(ans,cnt);
        }
        return ans;
    }
};