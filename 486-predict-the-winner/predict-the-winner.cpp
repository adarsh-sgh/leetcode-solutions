class Solution {
public:
vector<int>v;
int vsum = 0;
bool awins(int i, int j, int ascr, bool turnA) {
  if(i>j) return 2 * ascr >= vsum;
  if(turnA){
    return awins(i+1,j,ascr + v[i],!turnA)|| awins(i,j-1,ascr+v[j],!turnA);
  }else{
    return awins(i+1,j,ascr ,!turnA) && awins(i,j-1,ascr,!turnA);
  }
}

bool PredictTheWinner(vector<int>& nums) {
  v = nums;
  vsum = accumulate(v.begin(), v.end(), 0);
  return awins(0, v.size() - 1, 0,true);
}
};