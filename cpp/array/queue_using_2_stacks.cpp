// https://leetcode.com/problems/implement-queue-using-stacks/
// Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

// Implement the MyQueue class:

// void push(int x) Pushes element x to the back of the queue.
// int pop() Removes the element from the front of the queue and returns it.
// int peek() Returns the element at the front of the queue.
// boolean empty() Returns true if the queue is empty, false otherwise.
// Notes:

// You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

// Example 1:

// Input
// ["MyQueue", "push", "push", "peek", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 1, 1, false]

// Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.

// Explanation
// MyQueue myQueue = new MyQueue();
// myQueue.push(1); // queue is: [1]
// myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
// myQueue.peek(); // return 1
// myQueue.pop(); // return 1, queue is [2]
// myQueue.empty(); // return false


#include<iostream>
#include<vector>

using namespace std;

class MyQueue {
    vector<int> pop_stack, push_stack;
public:
    MyQueue() {
        
    }
    
    void push(int x) {
        push_stack.push_back(x);
    }
    
    int pop() {
        if(pop_stack.size() == 0){
            while(push_stack.size() != 0){
                pop_stack.push_back(push_stack.back());
                push_stack.pop_back();
            }
        }

        int value = pop_stack.back();
        pop_stack.pop_back();

        return value;
    }
    
    int peek() {
        if(pop_stack.size() == 0){
            while(push_stack.size() != 0){
                pop_stack.push_back(push_stack.back());
                push_stack.pop_back();
            }
        }

        int value = pop_stack.back();

        return value;
    }
    
    bool empty() {
        return pop_stack.empty() && push_stack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main() {
    vector<string> t1 = {"MyQueue", "push", "push", "peek", "pop", "empty"};
    vector<string> t1Vals = {{}, {1}, {2}, {}, {}, {}};

    int n = t1.size();

    MyQueue* queue;
    vector<int> result;
    for(int i = 0; i < n; i++){
        string op = t1[i];

        if(op == "MyQueue") {
            queue = new MyQueue();
            result.push_back(-1);
        } else if (op == "push") {
            queue->push(t1Vals[i][0]);
            result.push_back(-1);
        } else if(op == "peek") {
            // printf("%d\n", queue->peek());
            result.push_back(queue->peek());

        } else if(op == "pop") {
            result.push_back(queue->pop());
        } else if(op == "empty") {
            result.push_back(queue->empty());
        }
    }

    for(int item: result){
        printf("%d, ", item);
    }
}