class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<int, vector<int>> order;
        for (int i = 0; i < wordList.size() - 1; ++i) {
            for (int j = i + 1; j < wordList.size(); ++j) {
                // now we get to compare every word (O(n^2 * m))
                int differences = 0;
                for (int k = 0; k < wordList[0].size(); ++k) {
                    if (wordList[i][k] != wordList[j][k]) differences++;
                }
                if (differences <= 1) {
                    // then we have a connection so we will add to hash map
                    order[i].push_back(j);
                    // undirected so j also connected to i
                    order[j].push_back(i);
                }
            }
        }
        // now we need to know what vectors we have for beginWord to do BFS, like what 
        //   is the posssible first step to make?
        // we will compare it against every word
        // this should actually be a queue instead
        queue<int> curr;
        // we need to track which ones we have visited so that we do not have a cycle:
        unordered_set<int> visited;
        // we do also need to find our goal index:
        int goal = -1;
        for (int i = 0; i < wordList.size(); ++i) {
            int differences = 0;
            int differences_goal = 0;
            for (int j = 0; j < wordList[0].size(); ++j) {
                if (wordList[i][j] != beginWord[j]) differences++;
                if (wordList[i][j] != endWord[j]) differences_goal++;
            }
            if (differences == 1) {
                // only if exactly 1 because we would't do it for repeat words
                curr.push(i);
                visited.insert(i);
            }
            if (differences_goal == 0) goal = i;
        }
        if (goal == -1) {
            // so there is no endWord in the wordList
            return 0;
        }
        // now we will do BFS on it
        // we almost need some way to make sure that we are not going in a loop
        //   we start at 1 because we already have one word in our pattern which is beginWord
        int count = 1;
        while (!curr.empty()) {
            int level_size = curr.size();
            count++; // we are going through another rotation
            for (int i = 0; i < level_size; ++i) {
                int idx = curr.front();
                curr.pop();
                if (idx == goal) return count;
                // see what path each of them can lead us to
                for (int element : order[idx]) {
                    // now we add these to our queue but only if we have not already visited them
                    if (!visited.contains(element)) {
                        visited.insert(element);
                        curr.push(element);
                    }
                }
            }
        }
        // there was no path
        return 0;
    }
};
