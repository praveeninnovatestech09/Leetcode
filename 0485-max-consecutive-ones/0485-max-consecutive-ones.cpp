class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxlen=0;
        int count=0;
        for(int r=0;r<nums.size();r++){
if(nums[r]==1) maxlen++;
else  maxlen=0;
count = max(maxlen,count);
        }
        return count;
    }
};