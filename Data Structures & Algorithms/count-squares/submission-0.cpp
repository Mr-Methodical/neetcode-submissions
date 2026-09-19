class CountSquares {
    // x corresponding to y's 
    // where it is the y value and then the count
    unordered_map<int, unordered_set<int>> x_to_y;
    // counts
    vector<vector<int>> counts;
public:
    CountSquares() : counts(1001, vector<int>(1001, 0)) {}
    
    void add(vector<int> point) {
        x_to_y[point[0]].insert(point[1]);
        counts[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int res = 0;
        int x = point[0];
        int y = point[1];
    
        for (int y_coord : x_to_y[x]) {
            int dist = abs(y_coord - y);
    
            if (dist == 0) continue;
    
            int new_x_1 = x - dist;
            int new_x_2 = x + dist;
    
            // Square extending left
            if (new_x_1 >= 0) {
                res += counts[new_x_1][y] *
                   counts[new_x_1][y_coord] *
                   counts[x][y_coord];
            }
    
            // Square extending right
            if (new_x_2 <= 1000) {
                res += counts[new_x_2][y] *
                   counts[new_x_2][y_coord] *
                   counts[x][y_coord];
            }
        }
    
        return res;
    }
};
