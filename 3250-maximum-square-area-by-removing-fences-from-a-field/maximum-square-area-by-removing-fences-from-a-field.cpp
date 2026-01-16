class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
       // nh, nv < 600
        // n sq. = 3e5 (n cube TLE)
        // set<int> dx -> in n sq finds all delta of positions in x
        // set<int> dy 
        // largest x which is in both return x* x
        set<int>dx, dy;
        hFences.push_back(m);
        vFences.push_back(n);
        hFences.insert(hFences.begin(), 1);
        vFences.insert(vFences.begin(), 1);
        sort(vFences.begin(), vFences.end());
        sort(hFences.begin(), hFences.end());
        for(int i = 0; i < hFences.size();i++){
          for(int j = i+1; j < hFences.size();j++){
            dx.insert(hFences[j] - hFences[i]);
            }
        }

        long long ans = 0;
        int mod = 1e9 + 7;
        for(int i = 0; i < vFences.size();i++){
          for(int j = i+1; j < vFences.size();j++){
            int y = vFences[j] - vFences[i];
            if(dx.count(y))ans = max(ans, 1ll * y * y );
            }
        }
        if(ans == 0 )ans--;
        return ans % mod;
    }
};

// 1 2 3
// 