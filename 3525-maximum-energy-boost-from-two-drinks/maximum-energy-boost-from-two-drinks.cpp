class Solution {
public:
    long long maxEnergyBoost(vector<int>& ea, vector<int>& eb) {
        int n = ea.size();
        vector<long long>a(n), b(n);
        a[0] = ea[0], a[1] = ea[0] + ea[1];
        b[0] = eb[0], b[1] = eb[0] + eb[1];
        for(int i = 2;i<n;i++){
            a[i] = max(a[i-1], b[i-2]) + ea[i];
            b[i] = max(b[i-1], a[i-2]) + eb[i];
        }
        return max(a.back(), b.back());
    }
};