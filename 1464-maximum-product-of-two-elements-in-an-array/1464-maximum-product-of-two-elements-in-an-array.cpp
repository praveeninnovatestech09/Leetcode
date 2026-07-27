class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int product= (nums[i]-1)*(nums[j]-1);
                maxi = max(maxi,product);
            }
        }
        return maxi;
    }
};