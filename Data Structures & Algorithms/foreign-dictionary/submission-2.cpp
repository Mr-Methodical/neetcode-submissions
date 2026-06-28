class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<int> indeg(26, -1);
        // we should know what we have
        for (const auto& word : words) {
            for (const auto& c : word) {
                indeg[c - 'a'] = 0;
            }
        }
        queue<int> q; // what current character we should pay attention to
        vector<vector<int>> adj(26);
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
                adj[words[i][idx] - 'a'].push_back(words[i + 1][idx] - 'a');
                indeg[words[i + 1][idx] - 'a']++;
            }
        }
        // any that have 0 we should add them to q because they have no dependencies
        for (int i = 0; i < 26; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        string retval = "";
        // now we will go through queue while it isn't empty and look at what
        // it corresponds to
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            retval += ('a' + curr);
            // by unlocking this we decrease all of it's dependencies:
            for (const auto& c: adj[curr]) {
                indeg[c]--;
                if (indeg[c] == 0) {
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
