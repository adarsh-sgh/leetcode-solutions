class Solution {
public:
bool canCarry(int limit, vector<int> &weights, int trips) {
    int currWeight = 0;
    for(int i = 0; i < weights.size(); i++) {
        if (weights[i] + currWeight <= limit) {
            currWeight += weights[i];
        } else {
            trips--;
            currWeight = weights[i];
        }
    }
    return trips > 0;
}

int minWeight(vector<int> &weights, int trips) {
    int l = 0, h = 0, m, res;
    for (auto &w : weights) {
        l = max(w, l);
        h += w;
    }
    while (l <= h) {
        m = l + (h-l) / 2;
        if (canCarry(m, weights, trips)) {
            h = m - 1;
            res = m;
        } else {
            l = m + 1;
        }
    }
    return res;
}

    int shipWithinDays(vector<int>& weights, int days) {
        return minWeight(weights, days);
    }
};