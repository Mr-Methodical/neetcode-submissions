class Solution {
public:
    bool checkValidString(string s) {
        int leftMin = 0;
        int leftMax = 0;
        for (char c : s) {
            if (c == '(') {
                leftMin++;
                leftMax++;
            } else if (c == '*') {
                leftMax++;
                leftMin--; // treating it as right closing
            } else {
                leftMin--;
                leftMax--;
            }
            if (leftMax < 0) return false;
            if (leftMin < 0) leftMin = 0; // we can treat it as empty string
        }
        return leftMin == 0; // number on the left must end up being 0
    }
};
