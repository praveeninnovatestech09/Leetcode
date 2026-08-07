class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();

        int MOD = 1e9 + 7;

        // Stores number of choices on left
        vector<int> left(n);

        // Stores number of choices on right
        vector<int> right(n);

        stack<int> st;

        // ---------- Previous Smaller ----------
        for(int i = 0; i < n; i++) {

            // Remove all greater elements
            while(!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            // No previous smaller
            if(st.empty())
                left[i] = i + 1;

            // Distance from previous smaller
            else
                left[i] = i - st.top();

            // Store current index
            st.push(i);
        }

        // Empty stack
        while(!st.empty())
            st.pop();

        // ---------- Next Smaller or Equal ----------
        for(int i = n - 1; i >= 0; i--) {

            // Remove greater or equal elements
            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            // No next smaller
            if(st.empty())
                right[i] = n - i;

            // Distance from next smaller
            else
                right[i] = st.top() - i;

            // Store current index
            st.push(i);
        }

        long long ans = 0;

        // Calculate contribution of every element
        for(int i = 0; i < n; i++) {

            long long contribution =
                (1LL * arr[i] * left[i] * right[i]) % MOD;

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};