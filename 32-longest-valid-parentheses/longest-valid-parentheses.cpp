class Solution {
public:
    int longestValidParentheses(string s) {
        // index of last unhappy index who was never matched
        vector<int>st = {-1};
        int ans = 0;
        for(int i = 0;i < s.size();i++){
            char c = s[i];
            if(c == '('){
                st.push_back(i);
            }else{
                // if matching opening bracket is there -> pop it and the boundary before it to here is valid
                // say ()() , i = 3so pop the bracket at i = 2 and boundary should be -1

                if(st.back() != -1 && s[st.back()] == '('){
                    st.pop_back();
                    ans = max(ans, i - st.back());
                }else{
                    st.push_back(i);
                }
            }
        }
        return ans;
   }
};

// O(n)

// s[i][j] is valid iff
// open and close brackets are equal
// open <= close at each point