class Solution {
public:
long long totalneeded(vector<int>&piles , int k){
    long long totalH=0;
    for(int i=0; i<piles.size();i++){
totalH += ceil( (double)piles[i]/ (double)k);
    }
    return totalH;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxel = *max_element(piles.begin(), piles.end());
        int low=1;
        int high= maxel;
        while(low<=high){
            int mid= low+(high-low)/2;
            long long totalH= totalneeded(piles,mid);
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