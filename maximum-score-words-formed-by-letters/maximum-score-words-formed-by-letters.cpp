class Solution {
public:
  vector<int>sc;
vector<string>w;
int msw(int wi, vector<int> le) {
  if (wi == w.size())return 0;
  int res = msw(wi + 1, le);
  int curr = 0;
  for (auto&& c : w[wi]) {
    le[c - 'a']--;
    curr += sc[c - 'a'];
    if (le[c - 'a'] < 0)return res;
  }
  res = max(res, curr + msw(wi + 1, le));
  return res;
}

int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
  w = words;
  sc = score;
  vector<int>le(26);
  for (auto&& c : letters) {
    le[c - 'a']++;
  }
  return msw(0, le);
}
};