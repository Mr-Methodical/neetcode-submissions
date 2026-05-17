class TimeMap {
public:
    // we could do unordered_map with string and vector
    unordered_map<string, vector<pair<string, int>>> um;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        // we can just push onto it because time is always moving forward
        um[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto& val = um[key];
        int l = -1;
        int r = val.size() - 1;
        // we want to favor the lower middle one
        while (l < r) {
            int mid = l + (r - l + 1) / 2;
            if (val[mid].second == timestamp) {
                return val[mid].first;
            } else if (val[mid].second > timestamp) {
                // too big let's go down
                r = mid - 1;
            } else {
                // mid could be the answer
                l = mid;
            }
        }
        if (l == -1) return "";
        return val[l].first;
    }
};
