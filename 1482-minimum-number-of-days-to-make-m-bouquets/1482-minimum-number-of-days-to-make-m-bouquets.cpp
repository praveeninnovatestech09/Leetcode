class Solution {
public:
bool canMake(vector<int> &bloomDay ,int m , int k ,int day){
int f=0;
int b=0;
for(int i =0;i<bloomDay.size();i++){
    if(bloomDay[i]<=day){
        f++;
    }
    else{
        b+=(f/k);
        f=0;
    }
}
b+=f/k;
return b>=m;

}
    int minDays(vector<int>& bloomDay, int m, int k) {
        if(1LL*m*k>bloomDay.size()){
            return -1;
        }
        int low= *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low<=high){
        int mid= low+(high-low)/2;
        if(canMake(bloomDay,m,k,mid)){
            high=mid-1;
        }
        else{
            low=mid+1;
        }}
        
return low;
    }
};