// https://leetcode.com/explore/interview/card/google/60/linked-list-5/3066/
// A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.

// Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.

// For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.

// Return the head of the copied linked list.

// The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:

// val: an integer representing Node.val
// random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
// Your code will only be given the head of the original linked list.

 

// Example 1:


// Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]
// Example 2:


// Input: head = [[1,1],[2,1]]
// Output: [[1,1],[2,1]]
// Example 3:



// Input: head = [[3,null],[3,0],[3,null]]
// Output: [[3,null],[3,0],[3,null]]
 

// Constraints:

// 0 <= n <= 1000
// -104 <= Node.val <= 104
// Node.random is null or is pointing to some node in the linked list.


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *newHead = nullptr, *currNode = nullptr, *currHead = head, *oldHead = head;

        unordered_map<Node*, Node*> mapping;

        while(currHead != nullptr){
            Node *node = new Node(currHead->val);
            node->random = currHead->random;
            mapping[currHead] = node;

            if(currHead == oldHead){
                newHead = node;
            } else {
                currNode->next = node;
            }

            currNode = node;
            currHead = currHead->next;
        }

        if(currNode != nullptr){
            currNode->next = nullptr;
        }

        currNode = newHead;

        while(currNode != nullptr){
            currNode->random = mapping[currNode->random];

            currNode = currNode->next;
        }

        return newHead;
    }

    Node* createRandromList(vector<vector<int>> arr){
        Node* head = nullptr, *currNode = nullptr;
        Node* nodeArr[arr.size()];

        for(int i = 0; i < arr.size(); i++){
            Node* node = new Node(arr[i][0]);

            if(i == 0){
                head = node;
            } else {
                currNode->next = node;
            }

            currNode = node;
            nodeArr[i] = node;
        }

        if(currNode != nullptr){
            currNode->next = nullptr;
        }

        for(int i = 0; i < arr.size(); i++){
            if(arr[i][1] != 1001){
                nodeArr[i]->random = nodeArr[arr[i][1]];
            } else {
                nodeArr[i]->random = nullptr;
            }
        }
        return head;
    }

    void printList(Node* head){
        Node* currNode = head;

        while(currNode != nullptr){
            printf("%d, ", currNode->val);

            if(currNode->random != nullptr){
                printf("%d", currNode->random->val);
            }
            printf("\n");

            currNode = currNode->next;
        }
    }
};

int main() {

    Solution sol;
    // vector<vector<int>> t1 = {{7,1001},{13,0},{11,4},{10,2},{1,0}};
    // vector<vector<int>> t1 = {{1,1},{2,1}};
    // vector<vector<int>> t1 = {{3,1001},{3,0},{3,1001}};
    vector<vector<int>> t1 = {};



    Node* head = sol.createRandromList(t1);
    Node* newHead = sol.copyRandomList(head);

    sol.printList(newHead);

    return 0;
}