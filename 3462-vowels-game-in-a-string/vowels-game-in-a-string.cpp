class Solution {
public:
    set<char> v = {'a','e','i','o','u','A','E','I','O','U'};
    bool doesAliceWin(string s) {
        for(auto &c:s){
            if(v.count(c))return true;
        }
        return false;
    }
};