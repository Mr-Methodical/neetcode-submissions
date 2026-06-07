class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& order, unordered_set<int>& curr, 
             vector<int>& course_order, unordered_set<int>& course_order_hash, int course) {
        if (curr.contains(course)) return false;
        curr.insert(course);
        for (auto c : order[course]) {
            // we explore the other courses
            if (!course_order_hash.contains(c)) {
                if (!dfs(order, curr, course_order, course_order_hash, c)) return false;
            }
        }
        curr.erase(course);
        // we need to check if order contains it then we would add 
        // idea is that we are doing recursion so we will go back the other way
        if (!course_order_hash.contains(course)) {
            course_order.push_back(course); 
            course_order_hash.insert(course);
        } // else we have already addded it earlier
        // it is no longer on our path, and it is no longer in our order as we have proved
        // that we can satisfy it with our prereqs
        // we actually don't need to erase because we already track it with 
        // the course_order_hash: order.erase(course);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // return order to take courses in and none if it is impossible
        // we can go through the list of courses that is down the current path
        // if we attach it then how would that work if we have repeat courses
        // maybe we could have a visited to know whether or not to add it
        unordered_map<int, vector<int>> order;
        for (auto course : prerequisites) {
            order[course[0]].push_back(course[1]);
        }
        vector<int> course_order;
        // we also want immediate access to see what courses we already have:
        unordered_set<int> course_order_hash;
        // we need to know if we have visited it yet
        unordered_set<int> curr_path;
        for (const auto& entry : order) {
            // cycle detected not possible:
            if (!dfs(order, curr_path, course_order, course_order_hash, entry.first)) return {}; 
        }
        // we should do one more loop to see if we missed any that weren't in the prereqs
        for (int i = 0; i < numCourses; ++i) {
            if (course_order_hash.contains(i)) continue;
            course_order.push_back(i);
        }
        return course_order;
    }
};
