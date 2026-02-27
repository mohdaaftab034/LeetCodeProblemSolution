LeetCode Link - "https://leetcode.com/problems/min-stack/description"


class MinStack {
public:
    // Each stack element stores {value, current_minimum}
    stack<pair<int, int>> s;

    MinStack() {
        // Constructor (nothing special to initialize here)
    }
    
    void push(int val) {
        if(s.empty()) {
            // If stack is empty, the min is the element itself
            s.push({val, val});
        } else {
            // Compare current value with the minimum so far (s.top().second)
            int minVal = min(val, s.top().second);
            // Store current value along with updated minimum
            s.push({val, minVal});
        }
    }
    
    void pop() {
        // Remove the top element (value + min pair)
        s.pop();
    }
    
    int top() {
        // Return the actual value stored on top
        return s.top().first;
    }
    
    int getMin() {
        // Return the minimum up to the current point
        return s.top().second;
    }
};
