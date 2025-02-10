class Solution {
public:
    string clearDigits(string s) {
         string sa;
         for(auto &c:s){
            if(c  >= 'a' && c <= 'z') sa += c;
            else {
                if(sa.size())sa.pop_back();
            }
         }   
         return sa;
    }
};