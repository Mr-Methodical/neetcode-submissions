class Solution {
public:
    vector<int> partitionLabels(string s) {
        // we only want a letter to appear in one substring, and create most possible amount
        // of substrings
        // let's do a hash map that has the last index basically:
        unordered_map<char, int> last_index;
        for (int i = 0; i < s.size(); ++i) last_index[s[i]] = i;
        // now we know the last index:
        // idea will be that we go to that last index and as we keep finding higher last
        // indexes we expand our search
        vector<int> result;
        for (int i = 0; i < s.size(); ++i) {
            int start = i;
            int lim = last_index[s[i]];
            // when it hits limit we shouldn't go past that
            while (i < lim) {
                if (last_index[s[i]] > lim) lim = last_index[s[i]];
                i++;
            }
            // now we are at the end of that and will go on to the next one
            result.push_back(lim - start + 1);
        }
        return result;
    }
};
