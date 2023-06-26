class Solution {
public:
#define dbg(...) 42;
    long long totalCost(vector<int>& costs, int k, int candidates) {
  priority_queue<int, vector<int>, greater<int>>q1, q2;
  int p1 = 0, p2 = 0;
  for (;p1 < min(candidates, (int)costs.size());p1++) {
    q1.push(costs[p1]);
    costs[p1] = -1;
  }
  for (p2 = costs.size() - 1;p2 >= max(0, (int)costs.size() - candidates) && costs[p2] != -1;p2--) {
    q2.push(costs[p2]);
    costs[p2] = -1;
  }
  dbg(p1, p2)

    long long ans = 0;
  for (int i = 0;i < k;i++) {
     if (q2.empty() || (q1.size() && q1.top() <= q2.top())) {
      ans += q1.top();
      q1.pop();
      if (p1 < costs.size() && costs[p1] != -1) {
        q1.push(costs[p1]);
        costs[p1] = -1;
        p1++;
      }
    }
    else {
      ans += q2.top();
      q2.pop();
      if (p2 >= 0 && costs[p2] != -1) {
        q2.push(costs[p2]);
        costs[p2] = -1;
        p2--;
      }
    }
  }
  // cout << ans;
  return ans;
}
};