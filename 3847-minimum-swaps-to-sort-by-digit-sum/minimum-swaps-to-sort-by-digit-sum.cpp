class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
       vector<array<int,3>>v(n);
       for(int i = 0;i < n;i++){
        int sum = 0;
        int x = nums[i];
        while(x){
            sum += x % 10;
            x/=10;
        }
        v[i] = {sum, nums[i], i};
       }
       sort(v.begin(), v.end());
       int ans = 0;
       int loops = 0;
       vector<int>vis(n);
    //    for(int i = 0;i < n;i++){
    //     cout<<v[i][1]<<' '<<v[i][2]<<'\n';
    //    }
       for(int i = 0; i < n;i++){
        if(vis[i]) continue;
        loops++;
        int j = i;
        while(!vis[j]){
            cout<<j<<' ';
            vis[j] = true;
            j = v[j][2];
        }
       }

       return n - loops;
    }
};


//  18, 43, 34, 16
// 16, 34, 43, 18
// loops = 2