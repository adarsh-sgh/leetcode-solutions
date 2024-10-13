class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
          vector<array<int, 2>>v;
  for (int i = 0;i < nums.size();i++) {
    for (auto& x : nums[i]) {
      v.push_back({ x,i });
    }
  }
  sort(v.begin(), v.end());
  map<int, int>mp;
  int j = 0;
//   dbg(v);
  vector<int>av = { (int)-1e5,(int)1e5 };
  for (int i = 0;i < v.size();i++) {
    mp[v[i][1]]++;

    while (mp.size() >= nums.size()) {
      // valid window
    //   dbg(mp, j, i);

      if (av[1] - av[0] > v[i][0] - v[j][0]) {
        av = { v[j][0],v[i][0] };
      }
      // ans = min(ans,v[i][0] - v[j][0]);
      if (--mp[v[j][1]] == 0) {
        mp.erase(v[j][1]);
      }
      j++;
    }
  }
  return av;
    }
};