class Solution {
public:
#define dbg(...) 42;
    
vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
  int n = people.size();
  for (auto&& x : flowers) {
    for (auto&& y : x)
      y--;
  }
  vector<int>times;

  for (int i = 0;i < n;i++) {
    times.push_back(--people[i]);
  }
  sort(times.begin(), times.end());
  dbg(flowers, people);
  vector<int>v(n);
  for (auto&& x : flowers) {
    int i = lower_bound(times.begin(), times.end(), x[0]) - times.begin();
    int j = upper_bound(times.begin(), times.end(), x[1]) - times.begin();
    dbg(i, j, v);
    if (i >= n) continue;
    v[i]++;
    if (j >= n) continue;
    v[j]--;
  }
  dbg(v);
  for (int i = 1;i < n;i++) {
    v[i] += v[i - 1];
  }
  dbg(v);
  map<int, int>mp;
  for (int i = 0;i < times.size();i++) {
    mp[times[i]] = v[i];
  }
  dbg(mp);
  for (int i = 0;i < n;i++) {
    v[i] = mp[people[i]];
  }
  return v;
}
};