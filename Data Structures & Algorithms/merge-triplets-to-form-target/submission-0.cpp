class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;
        for (int i = 0; i < triplets.size(); ++i) {
            if (triplets[i][0] > target[0]) continue;
            if (triplets[i][1] > target[1]) continue;
            if (triplets[i][2] > target[2]) continue;
            max1 = max(max1, triplets[i][0]);
            max2 = max(max2, triplets[i][1]);
            max3 = max(max3, triplets[i][2]);
        }
        if (max1 != target[0] || max2 != target[1] || max3 != target[2]) return false;
        return true;
    }
};
