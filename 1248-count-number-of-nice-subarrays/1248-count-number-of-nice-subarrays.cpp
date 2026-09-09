class Solution {
public:
    int atMostOdd(vector<int>& nums, int k) {
        int l = 0;
        int sum = 0;
        int count = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r] % 2;
            while (sum > k){
                sum-=nums[l]%2;
                l++;
            }
            count += r-l+1;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
         return atMostOdd(nums,k)-atMostOdd(nums,k-1);
    }
};