class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi= INT_MIN;
    int prefix=1;
    int sufix=1;

        for(int i=0;i<nums.size(); i++){
            if(prefix==0){
                prefix=1;
            }
            if(sufix==0){
                sufix=1;
            }
            prefix= prefix*nums[i];
            sufix= sufix*nums[nums.size()-i-1];
            maxi = max( maxi , max(prefix,sufix));
            
        }
        return maxi;
    }
};