class Solution {
public:
   int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
  vector<pair<int, int>>v(n);
  for (int i = 0;i < n;i++) {
    v[i] = { efficiency[i],speed[i] };
  }
  sort(v.begin(), v.end(), greater());
  priority_queue<int, vector<int>, greater<int>>q;
  long long spsum = 0;
  long long ans = 0;
  for (int i = 0;i < n;i++) {
    q.push(v[i].second);
    spsum += v[i].second;
    if (q.size() > k) {
      spsum -= q.top();
      q.pop();
    }
    ans = max(ans, spsum * v[i].first);
  }
  int mod = 1e9 + 7;
  return ans%mod;
}
};