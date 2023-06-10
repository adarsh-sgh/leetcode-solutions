class Solution {
public:
    int n,i,ms;
    bool good(long long x){
        long long l = max(x-i, 1ll);
        long long r = max(x-(n-1-i),1ll);
        // numbers in the mountain 
        int n1 =  x - l + 1 + x - r;
        long long s1 = (x - l + 1)*(l + x) / 2;
        long long s2 = (x - r + 1)*(r + x)/2 - x;
        s2 += (n-n1);
        if(s1 > ms || s2 > ms || s1 + s2 > ms) return false;
        return true;
    }
    int maxValue(int N, int index, int maxSum) {
        n = N;
        i = index; 
        ms = maxSum;
        long long l = 0, r = maxSum;
        while(l < r){
            long long mid = (l + r + 1)/2;
            if(good(mid)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return l;
    }
};