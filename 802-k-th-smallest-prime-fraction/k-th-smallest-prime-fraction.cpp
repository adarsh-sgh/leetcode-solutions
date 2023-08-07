class Solution {
public:
struct comp {
  bool operator()(const vector<int>& a, const vector<int>& b) {
    return a[0] * b[1] > a[1] * b[0];
  }
};

   vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
  int n = arr.size();
  priority_queue < vector<int>, vector<vector<int>>, comp>pq;
  for (int i = 0;i < arr.size();i++) {
    pq.push({ arr[i],arr.back(), n - 1 });
  }
  while (--k) {
    // dbg(pq.top());
    auto t = pq.top();
    pq.pop();
    if (t[2] == 0)continue;
    pq.push({ t[0],arr[t[2] - 1],t[2] - 1 });
  }
  return { pq.top()[0],pq.top()[1] };
}
};