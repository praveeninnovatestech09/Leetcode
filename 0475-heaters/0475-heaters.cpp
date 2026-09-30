class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
       sort(heaters.begin(), heaters.end());
        int ans = 0;
        for (int i = 0; i < houses.size(); i++) {
            int house = houses[i];
            auto pos = lower_bound(heaters.begin(), heaters.end(), house);
            int right = INT_MAX;
            int left = INT_MAX;
            if (pos != heaters.end()) {
                right = *pos - house;
            }
            if (pos != heaters.begin()) {
                left = house - *(pos - 1);
            }
            
            int nearest =min(left,right);
            ans=max(ans,nearest);
        }
        return ans;
    }
};