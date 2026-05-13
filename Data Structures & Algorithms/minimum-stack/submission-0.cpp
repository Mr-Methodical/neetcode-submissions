class MinStack {
public:
    stack<pair<int, int>> s;
    // where the second value is what min used to be
    MinStack() {
        
    }
    
    void push(int val) {
        int min_val = val;
        if (!s.empty()) {
            min_val = min(min_val, s.top().second);
        }
        s.push({val, min_val});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};
