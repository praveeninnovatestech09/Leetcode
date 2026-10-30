class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n= arr.size();
        priority_queue<pair<int,int>> pq;
    for(int i=0;i<n;i++){
        int distance = abs(arr[i]-x);
        pq.push({distance,arr[i]});
        if(pq.size()>k){
            pq.pop();
        }
    }
    vector<int>ans;
    while(!pq.empty()){
        ans.push_back(pq.top().second);
        pq.pop();
    }
        sort(ans.begin(),ans.end());
        return ans;
    }
};