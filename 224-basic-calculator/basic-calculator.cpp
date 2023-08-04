class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        int num = 0;
        int sign = 1;
        int res = 0;
        for(int i = 0;i<s.size();i++){
            if(s[i] <= '9' && s[i] >= '0'  ){
                num = num * 10 + (s[i] - '0');
            }else if(s[i]=='+' || s[i]=='-'){
                res += num * sign;
                num = 0;
                sign = s[i] == '+'?1:-1;
            }else if(s[i]=='('){
                st.push(res);
                st.push(sign);
                assert(!num);
                res = 0;
                sign = 1;
            }else if(s[i]==')'){
                res += num * sign;
                res = res * st.top();
                st.pop();
                res += st.top();
                st.pop();
                sign = 1;
                num = 0;
            }
        }
        res += num * sign;
        return res;
    }
};