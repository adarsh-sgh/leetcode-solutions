class Solution {
public:

bool good(int k, int h,vector<int> &p){
    int sum = 0;
    for(auto i:p){
        sum += (i + k - 1) / k;
        // sum += ceil((float)i/k);
    }
    return sum <= h;
}

int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(),piles.end());
        while(l<r){
            int mid = l + (r-l)/2;
            if(good(mid,h,piles)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;

    }
};