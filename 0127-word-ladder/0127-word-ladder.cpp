class Solution {
public:
#define dbg(...) 42;

bool isAdjacent(string& s1, string& s2) {
  int diff = false;
  for (int i = 0;i < s1.size();i++) {
    if (s1[i] != s2[i]) {
      if (diff) return false;
      diff = true;
    }
  }
  return true;
}
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
  auto it = find(wordList.begin(), wordList.end(), beginWord);
  if (it == wordList.end())wordList.push_back(beginWord);
  else swap(*it, *--wordList.end());
  int n = wordList.size();
  vector<vector<int>>adj(n);


  for (int i = 0;i < n;i++) {
    for (int j = i + 1;j < n;j++) {
      bool isAdj = isAdjacent(wordList[i], wordList[j]);
      // dbg(wordList[i], wordList[j], isAdj);
      if (isAdj) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }
  dbg(adj);
  queue<int>q;
  q.push(n - 1);
  int level = 0;
  vector<bool>vis(n);
  while (!q.empty()) {
    int n = q.size();
    level++;
    while (n--) {
      auto x = q.front();
      dbg(x);
      if (wordList[x] == endWord) return level;
      q.pop();
      for (auto&& x : adj[x]) {
        if (!vis[x]) {
          q.push(x);
          vis[x] = true;
        }
      }
    }
  }
  return 0;
}
};