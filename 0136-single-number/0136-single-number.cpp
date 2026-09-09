class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int resXor= 0;
        for(int i =0; i<nums.size();i++){
            resXor= resXor ^ nums[i];
        }
        return resXor;
    }
};