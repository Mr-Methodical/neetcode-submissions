class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result;
        // this will end up being O(n)
        for (int i = 0; i <= n; ++i) {
            int count = 0;
            int temp = i;
            while (temp) {
                temp = temp & (temp - 1);
                count++;
            }
            result.push_back(count);
        }
        return result;
    }
};
