/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int peakIn = -1;
        // if(mountainArr.get(0) > mountainArr.get(1))peakIn = 0;
        // else 
        if(mountainArr.get(n-1)>mountainArr.get(n-2))peakIn = n-1;
        else{
            //find peak index
            int l = 0, r = n-2;
            while(l<r){
                int mid = (l+r)/2;
                if(mountainArr.get(mid)>mountainArr.get(mid+1)){
                    r = mid;
                }else{
                    l = mid+1;
                }
            }
            peakIn = l;
        }
        assert(peakIn >= 0 && peakIn < n);
        int l = 0, r = peakIn;
        while(l<r){
            int mid = (l+r)/2;
            if(mountainArr.get(mid)>=target){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        if(mountainArr.get(l)==target)return l;
        l = peakIn, r= n - 1;
        while(l<r){
            int mid = (l+r)/2;
            if(mountainArr.get(mid)<=target){
                r = mid;
            }else{
                l = mid+1;
            }
        }
      if(mountainArr.get(l)==target) return l;
      return -1;
    }
};