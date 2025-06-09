class Solution {
public:
int tripsCount(int cap, vector<int>weights){
  int load = 0;
  int trips =1;
  for(int i =0;i< weights.size();i++){
    if(load+weights[i]>cap){
      trips+=1;
      load =weights[i];
    }
    else{
      load+=weights[i];
    }
  }
  return trips;
}


int shipWithinDays(vector<int>& weights, int trips) 
{
    // vector<int>weights = {3,2,2,4,1,4};
    // int trips = 3;
    int sum = 0;
    int maxi = INT_MIN;
    for(int i =0;i<weights.size();i++){
      sum+=weights[i];
      if(maxi<weights[i]){
        maxi = weights[i];
      }
    }
    while(maxi<=sum){
      int mid = (maxi+sum)/2;
      int req_trips = tripsCount(mid, weights);
      if (req_trips<= trips){
        sum = mid -1;
      }
      else{
        maxi = mid +1;
      }
    }
    return maxi;

}
};