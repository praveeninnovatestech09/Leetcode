class Solution {
public:
    
        int DayNeed(vector<int>& weights , int capacity){
            int days=1;
          long long  currentLoad=0;
          for(int w=0;w<weights.size();w++){
            if(weights[w]+currentLoad>capacity){
                days++;
                currentLoad=weights[w];
            }
            else{
                currentLoad+=weights[w];
            }
          }
          return days;
        }
int shipWithinDays(vector<int>& weights, int days) {
    long long left=*max_element(weights.begin(), weights.end());
    long long right=accumulate(weights.begin(), weights.end(),0LL);
    while(left<=right){
        int mid= left+(right-left)/2;
        int needed= DayNeed(weights,mid);
        if(needed<=days){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
        return left;
    }
};