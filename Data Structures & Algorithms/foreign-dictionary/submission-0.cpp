class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<char> indeg(26, -1);
        // we should know what we have
        for (const auto& word : words) {
            for (const auto& c : word) {
                indeg[c - 'a'] = 0;
            }
        }
        queue<char> q; // what current character we should pay attention to
        unordered_map<char, unordered_set<char>> adj;
        int n = words.size();
        for (int i = 0; i < n - 1; ++i) {
            int idx = 0;
            int max_idx = min(words[i].size(), words[i + 1].size());
            while (idx < max_idx && words[i][idx] == words[i + 1][idx]) {
                idx++;
            }
            if (idx == max_idx) {
                // if the second word is smaller it breaks topological ordering
                if (words[i].size() > words[i + 1].size()) {
                    return "";
                }
                // else first word is smaller or the same size which gives us
                // no new info
                continue;
            } else {
                // idx would give us some info this is where they differ
                adj[words[i][idx]].insert(words[i + 1][idx]);
            }
        }
        // we need to change indeg based on the new info about dependencies
        for (const auto& entry : adj) {
            for (const auto& c : entry.second) {
                indeg[c - 'a']++;
            }
        }
        // any that have 0 we should add them to q because they have no dependencies
        for (int i = 0; i < 26; ++i) {
            if (indeg[i] == 0) {
                q.push(i + 'a');
            }
        }
        string retval = "";
        // now we will go through queue while it isn't empty and look at what
        // it corresponds to
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            retval += curr;
            // by unlocking this we decrease all of it's dependencies:
            for (const auto& c: adj[curr]) {
                indeg[c - 'a']--;
                if (indeg[c - 'a'] == 0) {
                    q.push(c);
                }
            }
        }
        for (int i = 0; i < 26; ++i) {
            if (indeg[i] != 0 && indeg[i] != -1) {
                // then we still have something that depends on something else
                // thus we have a loop and alien language wrong
                return "";
            }
        }
        return retval;
    }
};
