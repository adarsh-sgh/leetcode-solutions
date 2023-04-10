class Solution {
public:
  string removeDuplicateLetters(string s) {
  map<char, int>m;
  // for (auto&& c : s) {
  //   m[c]++;
  // }
  vector<int>lastIndex(128);
  int n = s.size();
  for (int i = 0;i < n;i++) {
    lastIndex[s[i]] = i;
  }
  stack<char>st;
  set<char>sc;
  for (int i = 0;i < n;i++) {
    auto& x = s[i];
    if (sc.count(x)) continue;
    while (!st.empty() && st.top() > x && lastIndex[st.top()] > i) {
      m[st.top()]--;
      sc.erase(st.top());
      st.pop();
    }
    sc.insert(x);
    st.push(x);
  }
  // while (!st.empty() && m[st.top()] > 1) {
  //   m[st.top()]--;
  //   st.pop();
  // }
  stack<int>rev;
  while (!st.empty()) {
    rev.push(st.top());
    st.pop();
  }
  string ans = "";
  while (!rev.empty()) {
    ans += rev.top();
    rev.pop();
  }
  return ans;
}
};