class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
       // 1e3 tak jakar saare pn. identify kar sakte upto 1e6
        // p -> prime list sorted
        vector<int>isPrime(right+1, true);
        for(int i = 2;i * i <= right;i++){
            if(!isPrime[i])continue;
            for(int j = 2 * i;j <= right;j+=i){
                isPrime[j] = false;
            }
        }
        vector<int>p;
        for(int i = 2;i< isPrime.size();i++){
            if(isPrime[i]){
                p.push_back(i);
            }
        }
        vector<int>ans = {-1,1000000000};
        for(int i = 1;i< p.size();i++){
            if(p[i] >= left && p[i] <= right && p[i-1] <= right && p[i-1]>= left){
                if(ans[1] - ans[0] > p[i] - p[i-1]){
                    ans = {p[i-1], p[i]};
                }
            }
        }
        if(ans[0] == -1) ans[1] = -1;
        return ans;
    }
};