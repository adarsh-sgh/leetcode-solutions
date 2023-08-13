class Solution {
public:
   bool parseBoolExpr(string expression) {
  stack<char>st;
  for (auto&& c : expression) {
    if (c == ')') {
      bool hasT = false, hasF = false;
      while (st.top() == 't' || st.top() == 'f') {
        hasT |= st.top() == 't';
        hasF |= st.top() == 'f';
        st.pop();
      }
      auto op = st.top();
      st.pop();
      char res;
      if (op == '&') {
        if (hasF)res = 'f';
        else res = 't';
      }
      else if (op == '|') {
        if (hasT) res = 't';
        else res = 'f';
      }else if (op=='!'){
          if(hasT) res ='f';
          else res = 't';
      }
      st.push(res);
    }
    else if (c != ',' && c != '(') {
      st.push(c);
    }
  }
  return st.top() == 't';
}
};