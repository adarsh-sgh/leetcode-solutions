class Solution {
public:
#define dbg(...) 42;
   struct cmp {
  bool operator()(const vector<int>& a, const vector<int>& b) {
    return a[0] + a[1] > b[0] + b[1];
  }
};

vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
  //priority queue of array of size 3
  priority_queue<vector<int>, vector<vector<int>>, cmp> pq;

  for (int i = 0;i < k && i < nums1.size();i++) {
    vector<int>arr = { nums1[i], nums2[0], 0 };
    pq.push(arr);
  }
  // while (!pq.empty()) {
  //   dbg(pq.top());
  //   pq.pop();
  // }
  vector<vector<int>>ans;
  while (!pq.empty() && k-- > 0) {
    auto t = pq.top();
    dbg(t);
    pq.pop();
    ans.push_back({ t[0],t[1] });
    if (t[2] + 1 >= nums2.size())continue;
    vector<int>arr{ t[0],nums2[t[2] + 1],t[2] + 1 };
    pq.push(arr);
  }
  return ans;

}
};