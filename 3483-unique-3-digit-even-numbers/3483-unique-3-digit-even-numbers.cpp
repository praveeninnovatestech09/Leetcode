class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int freq[10] = {};
        for (int digit : digits) {
            freq[digit]++;
        }
        int count = 0;
        for (int a = 1; a <= 9; a++) {
            for (int b = 0; b <= 9; b++) {
                for (int c = 0; c <= 8; c += 2) {
                    int temp[10];
                    for (int i = 0; i < 10; i++) {
                        temp[i] = freq[i];
                    }
                    if (temp[a] == 0)
                        continue;
                    temp[a]--;
                    if (temp[b] == 0)
                        continue;
                    temp[b]--;
                    if (temp[c] == 0)
                        continue;
                    temp[c]--;
                    count++;
                }
            }
        }
        return count;
    }
};