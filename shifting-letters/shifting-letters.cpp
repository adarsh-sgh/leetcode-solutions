class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
  int sft = 0;
  for (int i = s.size() - 1;i >= 0;i--) {
    sft += shifts[i];
    sft %= 26;
    int code = s[i] - 'a';
    code += sft;
    code %= 26;
    s[i] = 'a' + code;
  }
  return s;
}
};