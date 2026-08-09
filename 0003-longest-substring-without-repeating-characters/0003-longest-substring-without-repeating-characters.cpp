class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int>mp;
        int left =0;
        int ans=0;
        int n=s.size();
        for(int right=0;right<n;right++){
            if(mp.find(s[right])!=mp.end() && mp[s[right]]>=left ){
                left= mp[s[right]]+1;
            }
            mp[s[right]]=right;
            int maxLen= right-left+1;
            ans= max(maxLen,ans);
        }
        return ans;
    }
};