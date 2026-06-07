class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& order, unordered_set<int>& curr, int course) {
        if (curr.contains(course)) return false;
        curr.insert(course);
        for (const auto& c : order[course]) {
            if (!dfs(order, curr, c)) return false;
        }
        // now we are going back:
        curr.erase(course);
        // if all prereqs are satisfied we know that it is available:
        order.erase(course);
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // lets map a course to all the prereqs:
        unordered_map<int, vector<int>> order;
        for (auto course : prerequisites) {
            order[course[0]].push_back(course[1]);
        }
        // we need current course so we can detect cycles down a path
        unordered_set<int> curr;
        for (const auto& course : prerequisites) {
            if (!dfs(order, curr, course[0])) return false;
        }
        return true;
    }
};
