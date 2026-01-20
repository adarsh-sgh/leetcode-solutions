class Solution {
public:
    int sos(int x){
        int sum = 0;
        while(x){
            int d =  x % 10;
            x/=10;
            sum += d * d;
        }
        return sum;
    }
    map<int,bool> mp = {{1,true}};
    bool isHappy(int n) {
        if(n==1) return true;
        if(mp.count(n))return mp[n];
        mp[n] = false;
       return mp[n] = isHappy(sos(n));
    }

};