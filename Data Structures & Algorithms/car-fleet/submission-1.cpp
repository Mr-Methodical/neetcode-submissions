class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // we should have them sorted by position where they start
        vector<pair<int, int>> pos_speed;
        int n = position.size();
        for (int i = 0; i < n; ++i) {
            pos_speed.push_back({position[i], speed[i]});
        }
        sort(pos_speed.begin(), pos_speed.end(), greater<pair<int, int>>());
        // I guess the default for sort is to put smallest first
        // we need to sort with greatest first because hten closer to position
        // maybe we could calculate the arrival time
        // oh because we can go through pos_speed since it is already sorted
        // and then if the next one has a greater time then it just gets pushed
        // onto our current heat else we need another stack layer:
        // well first we need to calculate how many hours it takes for each one
        // (target - position) / speed
        stack<float> s; // we can actually just put time on here
        for (int i = 0; i < n; ++i) {
            float hours = (float)(target - pos_speed[i].first) / pos_speed[i].second;
            if (s.empty() || s.top() < hours) {
                // if hours more then we pop our new time on:
                s.push(hours);
            }
        }
        return s.size();
    }
};
