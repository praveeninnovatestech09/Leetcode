class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int l=0;
        int r=0;
        while(l<g.size()&&r<s.size()){
            if(g[l]<=s[r]){
                l=l+1;
            }
            r=r+1;
        }
        return l;
    }
};