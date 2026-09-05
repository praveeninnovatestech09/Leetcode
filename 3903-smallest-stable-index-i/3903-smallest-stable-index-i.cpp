class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        for (int i = 0; i < nums.size(); i++) {
            int leftmax = *max_element(nums.begin(), nums.begin()+i+1);
            int rightmin = *min_element(nums.begin()+i, nums.end());
            int instability=leftmax-rightmin;
            if( instability<=k ){
                
                return i;
            }
        }
        return -1;
    }
};