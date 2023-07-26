class Solution {
public:
    vector<int>d;
    double h;
    int ceil(int x,int y){
        if(x==0) return 0;
        return (x+y-1)/y;
    }

    bool canReachWith(int speed){
        int time = 0;
        for(int i = 0;i<d.size() - 1;i++) {
            time += ceil(d[i],speed);
            if(time > h) return false;
            }
    if((double)time + (double)d.back()/speed <= h)return true;
    return false;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        d = dist;
        h = hour;
        int l = 1, r = 1e7;
        while(l<r){
            int mid = (l+r)/2;
            if(canReachWith(mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        if(!canReachWith(l))return -1;
        return l;
    }
};