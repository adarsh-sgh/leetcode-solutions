class Solution {
public:

bool check(int val,vector<int>weights,int trips)
{
    int n=weights.size();
    int count=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
       if(sum+weights[i]<=val)
       {
           sum+=weights[i];
       }
       else
       {
           count++;
           sum=weights[i];
       }
    }
    return count<trips;
}


int binarySearch(int low,int high,vector<int>weights,int trips)
{
    while(low<high)
    {
        int mid=(low+high)/2;
        bool b=check(mid,weights,trips);

         //cout<<low<<" "<<mid<<" "<<high<<endl;

        if(b)
        {
           high=mid;
        }
        else
        {
            low=mid+1;
        }
    }
    return low;
}

int solve(vector<int>&weights, int trips){
   int low=0;
   int high=0;
   for(auto it:weights)
   {
       if(it>low)
       low=it;
       high+=it;
   }
   return binarySearch(low,high,weights,trips);
}

    int shipWithinDays(vector<int>& weights, int days) {
        return solve(weights, days);
    }
};