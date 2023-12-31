class Solution {
public:
    int maximumLength(string s) {
         int n = s.size();
  // map<string, int>mp;
  string x;
  vector<vector<int>>v(26);
  for (int i = 0;i < n;i++) {
    if (x.empty() || s[i] == x.back()) {
      x.push_back(s[i]);
    }
    else {
      //mp[x]++;
      int index = x[0] - 'a';
      v[index].push_back(x.size());
      x = s[i];
    }
  }
  // mp[x]++;
  int index = x[0] - 'a';
  // dbg(index, x);
  v[index].push_back(x.size());
  for (auto& x : v)sort(x.rbegin(), x.rend());
  // dbg(v);
  // return -1;
  auto good = [&](int l) {
    for (int i = 0;i < 26;i++) {
      int req = 3;
      for (int j = 0;j < min(3, (int)v[i].size());j++) {
        if (v[i][j] < l)break;
        req -= (1 + v[i][j] - l);
      }
      if (req <= 0) return true;
    }
    return false;
    };
  int l = 1, r = n;
  while (l < r) {
    int m = (l + r + 1) >> 1;
    if (good(m)) {
      l = m;
    }
    else {
      r = m - 1;
    }
  }
  if (good(l)) {
    return l;
  }
  else {
    return -1;
  } 
    }
};