class Solution {
public:
    int minimumLength(string s) { 
       vector<int>v(26); 
       for(int i = 0;i< s.size();i++){
          v[s[i] - 'a']++;
       }
       for(auto &x:v){
        while(x >= 3) x -= 2;
       }
       return accumulate(v.begin(), v.end(), 0ll);
    }
};