class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        vector<int>f(26);
        int mfi = 0;
        for(int i = 0;i<n;i++){
            if(++f[s[i] - 'a'] > f[s[mfi]-'a']){
                mfi = i;
            }
        }
        if(f[s[mfi] - 'a'] > (n + 1)/2) return "";
        vector<char> ans(n);
        int in = 0;
        int i;
        for(i = 0;i<n;){
            if(f[s[mfi]-'a']-- > 0){ans[i] = s[mfi];}
            else if(f[in]-->0) ans[i] = in + 'a';
            else {
                in++;
                continue;
            }
            i+=2;
        }
        int fin = 0;
        for(int i = 1;i<n;){
            if(f[fin]-- >0){
                ans[i] = fin + 'a';
                i+=2;
            }else{
                fin++;
            }
        }
        
        return string(ans.begin(),ans.end());

    }
};