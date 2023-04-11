class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<vector<int>> bucket(nums.size() + 1);
    unordered_map<int, int> frequencyMap;

    for (int n : nums) {
        frequencyMap[n]++;
    }

    for (auto& p : frequencyMap) {
        int key = p.first;
        int frequency = p.second;
        bucket[frequency].push_back(key);
    }

    vector<int> res;

    for (int pos = bucket.size() - 1; pos >= 0 && res.size() < k; pos--) {
        if (!bucket[pos].empty()) {
            res.insert(res.end(), bucket[pos].begin(), bucket[pos].end());
        }
    }
    return res;
}

};