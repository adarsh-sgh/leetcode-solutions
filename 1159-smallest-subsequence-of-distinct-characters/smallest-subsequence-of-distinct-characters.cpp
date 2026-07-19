class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        vector<int>lastIndex(128);
        set<char>se;
        for(int i = 0;i<n;i++){
            se.insert(s[i]);
            lastIndex[s[i]] = i;
        }
        string st;
        // st is monotonically increasing
        // when you get a char smaller than st.back() keep popping
        // but never pop someone who might not come later
        for(int i = 0;i<s.size();i++){
            if(!se.count(s[i]))continue;
            while(!st.empty()&&st.back()>s[i]&&lastIndex[st.back()]>i){
                se.insert(st.back());
                st.pop_back();
            }
            st.push_back(s[i]);
            se.erase(s[i]);
        }
        return st;
    }
};