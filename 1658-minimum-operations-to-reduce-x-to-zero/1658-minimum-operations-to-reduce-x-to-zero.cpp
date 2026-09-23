class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n= nums.size();
        long long total=0;
for(int i=0;i<n;i++){
    total+=nums[i];
}
int target= total-x;
if(target==0) return n;
int left=0;
int maxlen=-1;
long long sum=0;
for(int right =0;right<n;right++){
    sum += nums[right];

    while(left<=right && sum>target){
        sum -= nums[left];
        left++;

    }
    if(sum==target){
        maxlen= max(maxlen,right-left+1);
    }
}
if(maxlen==-1) return -1;

 return n-maxlen;

    }
};