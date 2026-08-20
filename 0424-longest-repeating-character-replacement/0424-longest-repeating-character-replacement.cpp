class Solution {
public:
    int characterReplacement(string s, int k) {
        int l = 0;
        int maxlen = 0;
        int maxf=0;
        unordered_map<char, int> mpp;
       for(int r=0;r<s.size();r++){
        mpp[s[r]]++;
        maxf=max(maxf,mpp[s[r]]);
        int changes= (r-l+1)-maxf;
        if(changes>k){
        mpp[s[l]]--;
        l++;
        changes=(r-l+1)-maxf;
        }
    
maxlen=max(maxlen,(r-l+1));
       }
       return maxlen;
    }
};