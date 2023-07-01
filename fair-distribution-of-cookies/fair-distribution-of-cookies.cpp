class Solution {
public:
    vector<int>c;
int dc(int i, vector<int>& v) {
  // v.size == k
  if (i == c.size() - 1) {
    int c1 = *max_element(v.begin(), v.end());
    int c2 = *min_element(v.begin(), v.end()) + c[i];
    return max(c1, c2);
  }
  int unfairness = INT_MAX;
  for (int x = 0;x < v.size();x++) {
    v[x] += c[i];
    unfairness = min(unfairness, dc(i + 1, v));
    v[x] -= c[i];
  }
  return unfairness;
}
int distributeCookies(vector<int>& cookies, int k) {
  c = cookies;
  vector<int>v(k, 0);
  return dc(0, v);
}
};