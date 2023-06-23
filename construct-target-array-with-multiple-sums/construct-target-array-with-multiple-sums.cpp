class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long n = target.size();
        if(n==1) return target[0]==1;
        priority_queue<long long>q;
        long long sum = 0;

        for(int i =0;i<n;i++){
            sum+=target[i];
            q.push(target[i]);
        }

        while(sum > n){
            auto t = q.top();
            q.pop();
            sum-=t;
            int tn = t % sum;
            if(sum==1) return true;
            if(tn==t) break;
            if(tn < 1) return false;
            q.push(tn);
            sum += tn;
        }
        return sum == n;
    }
};