class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        if(n<3||k==n)return 0;
        vector<int>candidates;
        for(int i = 0;i<n-1;i++){
            candidates.push_back(weights[i]+weights[i+1]);
        }
        sort(candidates.begin(),candidates.end());
        long long mxsum;
        long long minsum = mxsum = weights[0] + weights.back();

        for(int i = 0;i<k-1;i++)minsum += candidates[i];
        for(int i = n-2;i>=n-k;i--)mxsum += candidates[i];
        return mxsum - minsum;
    }
};