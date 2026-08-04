class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];

        for(int i = 1; i < nums.size(); i++) {

            if(nums[i] < mini)
                mini = nums[i];

            if(nums[i] > maxi)
                maxi = nums[i];
        }

        unordered_set<int> st;

        for(int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }

        vector<int> ans;

        for(int i = mini; i <= maxi; i++) {

            if(st.find(i) == st.end()) {
                ans.push_back(i);
            }

        }

        return ans;
    }
};