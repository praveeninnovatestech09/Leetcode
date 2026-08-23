class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();
        int s1 = 0, s2 = 0;
        int q1 = 0, q2 = 0;
        
        // Process left half
        for(int i = 0; i < n / 2; i++) {
            if(num[i] == '?') q1++;
            else s1 += (num[i] - '0');
        }
        
        // Process right half
        for(int i = n / 2; i < n; i++) {
            if(num[i] == '?') q2++;
            else s2 += (num[i] - '0');
        }
        
        // If total '?' is odd, Alice always wins
        if ((q1 + q2) % 2 != 0) return true;
        
        // Check Bob's winning condition
        if (2 * (s1 - s2) == 9 * (q2 - q1)) {
            return false; // Bob wins
        }
        
        return true; // Alice wins
        
    }
};