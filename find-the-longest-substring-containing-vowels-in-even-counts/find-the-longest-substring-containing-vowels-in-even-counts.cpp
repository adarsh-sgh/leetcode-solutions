class Solution {
public:
    //vowel index
map<char, int>vi{
  {'a', 0},
  { 'e',1 },
  { 'i',2 },
  { 'o',3 },
  { 'u',4 }
};
int findTheLongestSubstring(string s) {
  map<int, int>maskIndex;
  int bm = 0;
  int ans = 0;
  maskIndex[bm] = -1;
  for (int i = 0;i < s.size();i++) {
    if (vi.count(s[i])) {
      bm = bm ^ (1 << vi[s[i]]);
    }
    if (!maskIndex.count(bm)) {
      maskIndex[bm] = i;
    }
    ans = max(ans, i - maskIndex[bm]);
  }
  return ans;
}
};