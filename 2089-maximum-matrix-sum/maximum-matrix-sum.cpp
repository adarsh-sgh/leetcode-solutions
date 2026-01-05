class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        // smallest number - in worst case
        // all + in best case (when even number of negs or negs + 0 are there)
        int negs = 0, z = 0;
        long long sum = 0;
        int minAbs = 1e6;
        for(auto &x:matrix){
            for(auto &y:x){
                sum += abs(y);
                negs += y < 0;
                z += y == 0;
                minAbs = min(minAbs, abs(y));
            }
        }
        if(~negs & 1 || ~(negs + z) &1) return sum;
        return sum - 2 * minAbs;
    }
};