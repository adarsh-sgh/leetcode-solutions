class Solution {
public:
    bool isValid(string s) {
       string st;
       map<char,char>mp = {
        {'{','}'},
        {'(',')'},
        {'[',']'}
       };
       for(auto &c:s) {
        if(c == '(' || c == '[' || c == '{'){
            st.push_back(c);
        }else{

            if(st.empty() || mp[st.back()] != c){
                return false;
            }
            st.pop_back();
        }
       }
       return st.empty();
    }
};