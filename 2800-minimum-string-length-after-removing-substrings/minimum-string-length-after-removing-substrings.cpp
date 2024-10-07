class Solution {
public:
    int minLength(string s) {
        // if(s.size() < 2) return s;
        if(s.empty()) return 0;
       for(int i = 0;i<s.size() - 1;i++){
        auto sub = s.substr(i,2);
        if(sub == "AB" || sub == "CD"){
            return minLength(s.substr(0,i) + (i + 2 < s.size() ? s.substr(i+2):""));
        }
       } 
       return s.size();
    }
};