class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // let's first try the approach of sorting them:
        vector<string> strs_sorted;
        for (string s : strs) {
            string copy = s;
            sort(copy.begin(), copy.end());
            strs_sorted.push_back(copy);
        }
        unordered_map<string, vector<string>> groups;
        for (int i = 0; i < strs.size(); ++i) {
            groups[strs_sorted[i]].push_back(strs[i]);
        }
        vector<vector<string>> result;
        for (auto& [_, value] : groups) {
            result.push_back(value);
        }
        return result;
    }
};
