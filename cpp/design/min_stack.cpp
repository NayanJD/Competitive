#include<iostream>
#include<vector>

using namespace std;

class MinStack {
    vector<vector<int>> stack;
public:
    MinStack() {
    }

    void push(int val) {

        if(stack.size() > 0){
            vector<int> vals = stack.back();

            stack.push_back({val, min(val, vals[1])});
        } else {
            stack.push_back({val, val});
        }
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back()[0];
    }
    
    int getMin() {
        return stack.back()[1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
int main() {
    MinStack* minStack = new MinStack();

    minStack->push(-2);
    minStack->push(0);
    minStack->push(-3);
    printf("%d\n", minStack->getMin()); // return -3
    minStack->pop();
    printf("%d\n", minStack->top());    // return 0
    printf("%d\n", minStack->getMin()); 
}