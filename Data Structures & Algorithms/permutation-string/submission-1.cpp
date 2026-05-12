class Solution {
public:
    bool array_clean(int arr[]) {
        for (int i = 0; i < 26; ++i) {
            if (arr[i] != 0) {
                return false;
            }
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int left = 0;
        int arr[26] = {0};
        for (int i = 0; i < s1.size(); ++i) {
            arr[s1[i] - 'a']++;
            arr[s2[i] - 'a']--;
        }
        if (array_clean(arr)) return true;
        for (int right = s1.size(); right < s2.size();) {
            arr[s2[left++] - 'a']++;
            arr[s2[right++] - 'a']--;
            if (array_clean(arr)) return true;
        }
        return false;
    }
};
