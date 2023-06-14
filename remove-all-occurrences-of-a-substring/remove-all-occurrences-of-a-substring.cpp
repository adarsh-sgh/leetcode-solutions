class Solution {
public:
    string removeOccurrences(string s, string part) {
  int n = s.size();
  int pn = part.size();
  string st;
  for (int i = 0;i < n;i++) {
    st.push_back(s[i]);
    while (st.size() >= pn) {
      string sub = st.substr(st.size() - pn);
      if (sub != part)break;
      st.resize(st.size() - pn);
    }
  }
  return st;
}
};