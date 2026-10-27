class Solution {
public:
    vector<string> createGrid(int m, int n) {
       vector<string>v(m, string(n,'#'));
       v[0] = string(n, '.');
       for(auto &s:v){
        s.back() = '.';
       }
       return v;
    }
};