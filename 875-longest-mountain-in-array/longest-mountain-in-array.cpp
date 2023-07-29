class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int inl = 0,decl = 0;
        int ans= 0;
        for(int i = 1;i<arr.size();i++){
            if(arr[i]==arr[i-1]){inl = 0;decl =0;}
            else if(arr[i]<arr[i-1])decl++;
            else {
                if(decl){
                    decl = 0;
                    inl = 0;
                }
                inl++;
            }
            if(inl && decl)ans = max(ans,inl+decl+1);
        }
        return ans<3?0:ans;
    }
};