class Solution {
public:
    string reverseParentheses(string s) {
  string st;
  queue<char>q;
  int n = s.size();
  for (int i = 0;i < n;i++) {
    if (s[i] == ')') {
      while (st.back() != '(') {
        q.push(st.back());
        st.pop_back();
      }
      st.pop_back();
      while (!q.empty()) {
        st.push_back(q.front());
        q.pop();
      }
    }
    else {
      st.push_back(s[i]);
    }
  }
  return st;
}
};