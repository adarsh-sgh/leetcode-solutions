class Solution {
public:
#define dbg(...) 42;
   vector<int> diffWaysToCompute(string expression) {
  dbg(expression);
  int n = expression.size();
  if (n == 0) return {};
  vector<int>ans;
  for (int i = 0;i < n;i++) {
    char c = expression[i];
    string ops = "*+-";
    if (ops.find(expression[i]) != string::npos) {
      vector<int> l = diffWaysToCompute(expression.substr(0, i));
      vector<int>r = diffWaysToCompute(expression.substr(i + 1, expression.size() - i));
      for (auto&& x : l) {
        for (auto&& y : r) {
          if (c == '+') ans.push_back(x + y);
          else if (c == '-') ans.push_back(x - y);
          else ans.push_back(x * y);
        }
      }
    }
  }
  if (ans.empty()) {
    ans.push_back(stoi(expression));
  }
  return ans;
}
};