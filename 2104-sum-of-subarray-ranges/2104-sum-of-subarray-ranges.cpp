class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n= nums.size();
        long long sumMax= 0;
        long long sumMin= 0;
        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;
        //contribution as minimums bro
        //nse
        for(int i=n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>=nums[i] ){
                st.pop();
            }
            if(st.empty()){
                right[i]= n-i;
            }
            else{
                right[i]=st.top()-i;
            }
            st.push(i);
            
        }
        // Clear stack
        while (!st.empty()) {
            st.pop();
        }
        //pse
        for(int i=0;i<n;i++){
            while(!st.empty()&& nums[st.top()]>nums[i]){
                st.pop();
            }
            if(st.empty()){
                left[i]=i+1;
            }
            else{
                left[i]=i-st.top();
            }
            st.push(i);
        }
        //sum of minimums
        for(int i=0;i<n;i++){
            long long contro = 1LL*left[i]*right[i]*nums[i];
            sumMin +=contro;
        }
          // Clear stack and reuse arrays
        while (!st.empty()) {
            st.pop();
        }

        // Find contribution as maximum
        // Previous Greater Element
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                left[i] = i + 1;
            } else {
                left[i] = i - st.top();
            }

            st.push(i);
        }

        // Clear stack
        while (!st.empty()) {
            st.pop();
        }

        // Next Greater Element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }

            if (st.empty()) {
                right[i] = n - i;
            } else {
                right[i] = st.top() - i;
            }

            st.push(i);
        }

        // Calculate sum of maximums
        for (int i = 0; i < n; i++) {
            long long contro =
                1LL * nums[i] * left[i] * right[i];

            sumMax += contro;
        }
        return sumMax- sumMin;
    }
};