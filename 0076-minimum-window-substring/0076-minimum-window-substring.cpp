class Solution {
public:
    string minWindow(string s, string t) {
        int l = 0;
        int minlen = INT_MAX;
        int count = 0;
        int start = 0;
        unordered_map<int, int> mp;
        for (char c : t) {
            mp[c]++;
        }
        for (int r = 0; r < s.size(); r++) {
            if (mp[s[r]] > 0) {
                count++;
            }
            mp[s[r]]--;
            while (count == t.size()) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    start = l;
                }
                mp[s[l]]++;
                if (mp[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            }
             if (minlen == INT_MAX) {
            return "";
        }
        return s.substr(start, minlen);
    }
};