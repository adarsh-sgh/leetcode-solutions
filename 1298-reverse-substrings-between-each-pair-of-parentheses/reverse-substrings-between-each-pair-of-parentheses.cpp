class Solution {
public:
    string reverseParentheses(string s) {
       string res;
       for(auto &c:s) {

        if(c==')'){
            string rev;
            while(res.back() != '('){
                rev.push_back(res.back());
                res.pop_back();
            }
            res.pop_back();
            res+=rev;
        }else{
            res.push_back(c);
        }
       }
       return res;
    }
};