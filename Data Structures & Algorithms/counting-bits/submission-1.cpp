class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        result.push_back(0);
        for (int i = 1; i <= n; ++i) {
            // odds are the only time you can add more
            if (i % 2 == 0) {
                result.push_back(result[i / 2]);
            } else {
                result.push_back(1 + result[i / 2]);
            }
        }
        return result;
    }
};
