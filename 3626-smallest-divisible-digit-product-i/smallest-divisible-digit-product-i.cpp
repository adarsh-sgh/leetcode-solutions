class Solution {
public:
    int smallestNumber(int n, int t) {
       do{
        // find pod
        long long p = 1;
        int x = n;
        while(x){
            int d = x % 10;
            p*=d;
            x/=10;
        }
        if(p % t == 0)return n;
       }while(n++);
       return -1;
    }
};