class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0;
        // int right=0;
        int maxlen=0;
        int zeros=0;
        int n= nums.size();
        for(int right=0;right<n;right++){
            if(nums[right]==0)
        zeros++;
        if(zeros>k){
            if(nums[left]==0) zeros--;
            left++;
        }
if(zeros<=k){
     int len=right-left+1;
    maxlen=max(maxlen,len);
}
    }
return maxlen;
    }
};