class Solution {
public:
    int minMoves(vector<int>& nums) {
        int diff =0;
        int  ans=0;
        int maxi = *max_element(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            diff = maxi-nums[i];
            ans += diff;
        }
        return ans;
    }
};