class Solution {
public:
  int videoStitching(vector<vector<int>>& clips, int time) {
  sort(clips.begin(), clips.end());
  vector<vector<int>>ans{{0, 0}};
  for (int i = 0;i < clips.size();i++) {
    int x = clips[i][0], y = clips[i][1];
    int px = ans.back()[0], py = ans.back()[1];

    if (x > py)return -1;
    if (y <= py)continue;
    while (ans.size() > 1 && x <= ans.back()[0])ans.pop_back();
    ans.push_back({ ans.back()[1],y });
    if(ans.back()[1]>=time) return ans.size()-1;
  }
  // dbg(clips, ans);
  if (ans.back()[1] < time) return -1;
  return ans.size() - 1;
}
};