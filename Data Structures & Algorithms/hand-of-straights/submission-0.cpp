class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        sort(hand.begin(), hand.end());
        unordered_map<int, int> freq;
        for (int num : hand) freq[num]++;
        for (int num : hand) {
            // assume the first thing is the start to the sequence
            if (freq[num] == 0) continue;
            for (int i = 0; i < groupSize; ++i) {
                if (!freq.contains(num + i) || freq[num + i] == 0) return false;
                freq[num + i]--;
            }
        }
        return true;
    }
};
