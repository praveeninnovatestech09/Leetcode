class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n =arr.size();
        const int MOD=1e9+7;
        vector<int>left(n);
        vector<int>right(n);
        stack<int>st;
        //for pse
        for(int i =0; i<n;i++){
            while(!st.empty()&& arr[st.top()]>arr[i]){
                st.pop();
            }
            if(st.empty()){
                left[i]= i+1;
            }
            else{
                left[i]= i-st.top();
            }
            st.push(i);
        }
        //emptystack
        while(!st.empty()){
            st.pop();
        }
        // for nse
        for(int i = n-1; i>=0;i--){
            while(!st.empty()&& arr[st.top()]>=arr[i]){
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

        long long ans=0;
        for(int i=0;i<n;i++){
            long long contro = 1LL*left[i]*right[i]*arr[i];
            ans= (ans+contro)%MOD;
        }
        return ans;
    }
};