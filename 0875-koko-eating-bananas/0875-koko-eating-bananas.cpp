class Solution {
public:
  long long hoursNeed(vector<int> &piles ,int k){
long long totalH= 0;
for(int banana: piles){
    totalH += ceil((double)banana/k);
}
return totalH;

  }

    int minEatingSpeed(vector<int>& piles, int h) {
int low=1;
int high=*max_element(piles.begin(),piles.end());
while(low<=high){
    int mid= low+(high-low)/2;
    long long totalH=hoursNeed(piles,mid);
    if(totalH<=h){
        high=mid-1;
    }
    else{
        low=mid+1;
    }
}
      return low;  
    }
};