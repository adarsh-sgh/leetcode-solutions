class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
  int n = deck.size();
  int index = 0;
  bool fill = true;
  vector<int>ind(n, -1);
  while (index < deck.size())  for (int i = 0;i < n;i++) {
    if (ind[i] != -1)continue;
    if (fill)ind[i] = index++;
    fill = !fill;
  }
  sort(deck.begin(), deck.end());
  vector<int>ans(n);
  for (int i = 0;i < n;i++) {
    ans[i] = deck[ind[i]];
  }
  return ans;
}

};