class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
  // indices of cars with monotonic dec. collision time
  vector<int>st;
  int n = cars.size();
  vector<double>ans(n, -1);
  for (int i = n - 1;i >= 0;i--) {
    while (st.size()) {
      int j = st.back();
      int pj = cars[j][0], sj = cars[j][1];
      int pi = cars[i][0], si = cars[i][1];
      // wouldn't collide with j
      if (si <= sj || (ans[j] > 0 && ans[j] <= (double)(pj - pi) / (si - sj))) {
        st.pop_back();
      }
      else {
        break;
      }
    }
    if (st.size()) {
      //i will collide with st.top and disappear 
      auto j = st.back();
      int pj = cars[j][0], sj = cars[j][1];
      int pi = cars[i][0], si = cars[i][1];
      ans[i] = (double)(pj - pi) / (si - sj);
    }
    st.push_back(i);
  }
  return ans;
}
};