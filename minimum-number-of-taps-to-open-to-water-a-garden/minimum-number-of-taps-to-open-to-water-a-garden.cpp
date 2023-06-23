class Solution {
public:
#define dbg(...) 42;
    int minTaps(int n, vector<int>& ranges) {
  vector<pair<int, int>>rng(n + 1);
  for (int i = 0;i <= n;i++) {
    rng[i] = { i - ranges[i],i + ranges[i] };
  }
  sort(rng.begin(), rng.end());
  dbg(rng);
  int i = 0, cnt = 0, end = 0, endMax = 0;
  while (i < rng.size() && end < n) {
    while (i < rng.size() && rng[i].first <= end) {
      endMax = max(endMax, rng[i].second);
      i++;
    }
    dbg(end, endMax, i, cnt);
    if (end == endMax) return -1;
    end = endMax;
    cnt++;
  }
  dbg(end, cnt)
    if (end < n) return -1;
  return cnt;
}
};