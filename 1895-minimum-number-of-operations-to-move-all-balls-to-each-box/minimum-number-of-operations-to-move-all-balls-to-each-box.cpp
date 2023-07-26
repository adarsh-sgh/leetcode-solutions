class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>v(n);
        int sum = 0,cnt = 0;
        for(int i = 0;i<n;i++){
            v[i]+= sum;
            if(boxes[i]-'0')cnt++;
            sum+=cnt;
        }
        sum = 0;cnt = 0; 
        for(int i = n-1;i>=0;i--){
            v[i]+= sum;
            if(boxes[i]-'0')cnt++;
            sum+=cnt;
        }
        return v;
    }
};