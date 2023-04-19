class Solution {
public:
    bool isValidIp(string& s) {
  if (s.empty()) return false;
  if(s.size() > 3) return false;

  if (s[0] == '0' && s.size() > 1) return false;
  int n = stoi(s);
  if (n > 255 || n < 0) return false;
  return true;
}
vector<string> restoreIpAddresses(string s) {
  long long n = s.length();
  vector<string>ans;
  for (int i = 0;i < (1 << n);i++) {
    if (__builtin_popcount(i) != 3) continue;
    string current = "";
    string ip = "";
    for (int x = 0;x < n;x++) {

      if (i & (1 << x)) {
        if (!isValidIp(current)) break;
        ip += current + '.';
        current = "";
      }
      current += s[x];
      if (x == n - 1) {
        if (!isValidIp(current)) break;
        ip += current;
        ans.push_back(ip);
      }
    }
  }
  return ans;
}
};