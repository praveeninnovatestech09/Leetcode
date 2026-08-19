class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k){
        int left=0;
        int n  = cardPoints.size();
        int right = n-1;
        long long maxSum= 0;
        long long leftsum=0;
        long long rightsum=0;
        for(int i =0; i<k;i++){
            leftsum=leftsum+cardPoints[i];
            maxSum=leftsum;
        }
        for(int i = k-1; i>=0;i--){
            leftsum= leftsum- cardPoints[i];
            rightsum = rightsum+ cardPoints[right];
            right= right-1;
            maxSum= max(maxSum,(leftsum+rightsum));
        }

return int(maxSum);
    }
};