class Solution {
public:
    string reorganizeString(string s) {
        vector<int>f(26);
        for(auto &&c:s){
            f[c-'a']++;
        }
        int mfc = 0;
        for(int i = 0;i<26;i++){
            if(f[i] > f[mfc]) mfc = i;
        }
        if(f[mfc] > (s.size()+1)>>1) return "";
        for(int i =0 ;;){
            if(i>=s.size()){
                if(i & 1) break;
                i = 1;
            }
            if(!f[mfc]){
                mfc++;
                mfc %= 26;
            }else{
            s[i] = 'a' + mfc;
            f[mfc]--;
            i+=2;
            }
        }
       
        return s;


    }
};