class Solution {
public:
int countSplits(vector<int>&nums, long long sum){
    int splits =1;
    long long subarraySum =0;
    for(int i =0;i<nums.size();i++){
        if(subarraySum +nums[i]<=sum){
            subarraySum +=nums[i];
        }
        else{
            splits++;
            subarraySum = nums[i];
        }
    }
    return splits;
}
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size()) return -1;
        long long low= *max_element(nums.begin(),nums.end());
        long long high= accumulate(nums.begin(),nums.end(),0LL);
        while(low<=high){
            int mid=low+(high-low)/2;
            int splits = countSplits(nums,mid);
            if(splits>k){
                low= mid+1;
            }
            else{
                high= mid-1;
            }
        }
        return low;
    }
};