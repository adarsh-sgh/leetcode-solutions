class Solution {
public:
#define dbg(...) 42;
    long long countOfSubstrings(string word, int k) {
  map<char, int> mp = { {'a', 0}, {'e', 1}, {'i', 2}, {'o', 3}, {'u', 4} };
  int n = word.size();
  dbg(word);
  vector<vector<int>> pf(6, vector<int>(n + 1, -1));
  pf[5][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      if (mp.count(word[i]) && mp[word[i]] == j) {
        pf[j][i + 1] = i;
      }
      else {
        pf[j][i + 1] = pf[j][i];
      }
    }
    dbg(mp.count(word[i]));
    pf[5][i + 1] = pf[5][i] + (mp.count(word[i]) ? 0 : 1);
  }
  long long ans = 0;
  for (auto& v : pf) { dbg(v); };
  map<int, int>cc;
  for (int i = 0; i < n; i++) {
    int imin = n;
    for (int j = 0; j < 5; j++) {
      imin = min(imin, pf[j][i + 1]);
    }

    if (imin == -1)continue;

    if (pf[5][i + 1] >= k && pf[5][i + 1] - pf[5][imin] <= k) {
      // in p[5] find no. of indices less than imin with value = k 
      auto it = lower_bound(pf[5].begin(), pf[5].begin() + imin + 1, pf[5][i + 1] - k);
      auto it2 = upper_bound(pf[5].begin(), pf[5].begin() + imin + 1, pf[5][i + 1] - k);
      ans += it2 - it;
    }
  }
  return ans;
    }
};