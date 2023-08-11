class Solution {
public:
    int inf  = 1e9 + 5;
    int minFlips(string s) {
        s+=s;
        int toflip = inf;
        string c1,c2;
        for(int i = 0;i<s.size();i++){
            int p = i & 1;
            c1 += p + '0';
            c2 +=  '1' - p;
        }
        int f1= 0, f2 = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i]!=c1[i])f1++;
            if(s[i] != c2[i]) f2++;

            int j = i - s.size()/2;
            if(j>=0)if(s[j] != c1[j])f1--;
            if(j>=0)if(s[j] != c2[j])f2--;
            if(j+1>=0){
                toflip = min({toflip,f1,f2});
            }
        }
        return toflip;
       
    }
};