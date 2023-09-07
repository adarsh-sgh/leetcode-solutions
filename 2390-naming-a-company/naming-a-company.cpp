class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<unordered_set<string>>v(26);
        for(auto &s:ideas){
          v[s[0]-'a'].insert(s.substr(1));
        }
        long long res = 0;
        for(int i = 0;i<26;i++){
          for(int j = i + 1;j < 26;j++){
            int l1 = 0, l2 = 0;
            for(auto &p:v[i]){
              if(!v[j].count(p))l1++;
            }
             for(auto &p:v[j]){
              if(!v[i].count(p))l2++;
            }
            res += l1 * l2;
          }
        }
        return 2 * res;
    }
};