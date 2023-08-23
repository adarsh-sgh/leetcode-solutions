class Solution {
public:
    int longestEqualSubarray(vector<int>& v, int k) {
        int n = v.size();
        vector<vector<int>> pref(n + 1);
        for(int i = 0; i < n; ++i) {
            pref[v[i]].push_back(i);
        }

        int ans = 0;
        for(int ii = 1; ii <= n; ++ii) {
            vector<int>& temp = pref[ii];
            int i = 0, j = 0;
            int elem = k;
            int m = temp.size();
            while(j < m) {
                while(j + 1 < m && temp[j + 1] - temp[j] - 1 <= elem) {
                    elem -= temp[j + 1] - temp[j] - 1;
                    ++j;
                }
                ans = max(ans, j - i + 1);
                if(i + 1 < m) {
                    elem += temp[i + 1] - temp[i] - 1;
                }
                elem = min(elem, k);
                ++i;
                j = max(j, i);
            }
        }
        return ans;
    }
};