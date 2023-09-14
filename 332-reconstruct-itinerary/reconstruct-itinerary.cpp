class Solution {
public:
// euler tour 
    map<string, vector<string>>adj;
vector<string>tour;
void eulerTour(string node) {
  while (adj[node].size()) {
    string nxt = adj[node].back();
    adj[node].pop_back();
    eulerTour(nxt);
  }
  tour.push_back(node);
}

vector<string> findItinerary(vector<vector<string>>& tickets) {
  for (auto& t : tickets) {
    adj[t[0]].push_back(t[1]);
  }
  for (auto&& [x, v] : adj)sort(v.rbegin(), v.rend());
  eulerTour("JFK");
  reverse(tour.begin(), tour.end());
  return tour;
}
};