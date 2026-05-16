class Solution {
public:
    // one subproblem is basically we are given k per hour and we need to hit h can we do it:
    bool possible_eat(vector<int>& piles, int h, int k) {
        // we can eat k bananas per hour and only go in one pile once:
        // we could assign a number of hours to each pile, oh we need to eat all the bannasa
        int total_hrs = 0;
        for (int i = 0; i < piles.size(); ++i) {
            // we should probably round up:
            total_hrs += (piles[i] + k - 1) / k;
        }
        return total_hrs <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // I guess l should be at least 1 
        int l = 1;
        // r should be the max thing in the piles
        int r = INT_MIN;
        for (int i = 0; i < piles.size(); ++i) r = max(r, piles[i]);
        while (l < r) { // as soon as they are equal to each other then we got the right answer
            int mid = l + (r - l) / 2;
            if (possible_eat(piles, h, mid)) {
                // then this is possible
                r = mid;
            } else {
                // not possible for mid
                l = mid + 1;
            }
        }
        return l;
    }
};
