class Solution {
public:
    #define dbg(...) 42;
    long long subArrayRanges(vector<int>& v){
  stack<int>md;
  int n = v.size();
  vector<int>nge(n, n), pge(n, -1);
  vector<int>nse(n, n), pse(n, -1);
  for (int i = 0;i < v.size();i++) {
    while (md.size() && v[md.top()] < v[i]) {
      nge[md.top()] = i;
      md.pop();
    }
    if (md.size()) {
      pge[i] = md.top();
    }
    md.push(i);
  }
  stack<int>mi;
  for (int i = 0;i < v.size();i++) {
    while (mi.size() && v[mi.top()] > v[i]) {
      nse[mi.top()] = i;
      mi.pop();
    }
    if (mi.size()) pse[i] = mi.top();
    mi.push(i);
  }
  dbg(nge, pge);
  dbg(nse, pse);
  long long ans = 0;
  for (int i = 0;i < n;i++) {

    int l1 = i - pge[i], r1 = nge[i] - i;
    int l2 = i - pse[i], r2 = nse[i] - i;
    long long inr =1ll * l1 * r1 * v[i];
    long long dec = 1ll * l2 * r2 * v[i];

    // dbg(l1, r1, v[i], l2, r2, inr, dec);
    dbg(r1 * l1, r2 * l2, inr, dec);

    ans += inr - dec;
  }
  return ans;
}
};