class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        int new_num = 0;
        while (true) {
            if (n == 1) return true;
            if (seen.contains(n)) return false;
            seen.insert(n);
            while (n) {
                int first_dig = n % 10;
                n = n / 10;
                new_num += first_dig * first_dig;
            }
            // n will get to 0 and then we need to let n be our new_num 
            n = new_num;
            new_num = 0;
        }
        return true; // this should never happen though
    }
};
