class Solution {
public:
    int maxDifference(string s) {
        vector<int>v(26);
        for(auto &c:s){
            v[c-'a']++;
        }
        int emin = s.size(), omax = 0;
        for(int i = 0;i < 26;i++){
            if(!v[i])continue;
            if(v[i] % 2 == 0){
                emin = min(emin, v[i]);
            }else{
                omax = max(omax, v[i]);
            }
        }
        cout<<omax<<' '<<emin;
        return omax - emin;
    }
};