// https://leetcode.com/problems/add-two-numbers/
// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

// Example 1:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [7,0,8]
// Explanation: 342 + 465 = 807.

// Example 2:

// Input: l1 = [0], l2 = [0]
// Output: [0]
// Example 3:

// Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
// Output: [8,9,9,9,0,0,0,1]

#include<vector>
#include<iostream>

/**
 * Definition for singly-linked list. */
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
using namespace std;

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = nullptr;
        ListNode* head;
        int carry = 0;
        int value = 0;
        while(l1 != nullptr || l2 != nullptr) {
            
            if(l1 == nullptr){
                value = l2->val + carry;
                l2 = l2-> next;
            } else if (l2 == nullptr) {
                value = l1->val + carry;
                l1 = l1->next;
            } else {
                value = l1->val + carry + l2->val;
                l1 = l1->next;
                l2 = l2-> next;
            }

            carry = value / 10;
            ListNode* temp = new ListNode;

            temp->val = value % 10;
            temp->next = nullptr;

            if(result != nullptr){
                result->next = temp;
                result = temp;
            } else {
                result = temp;
                head = temp;
            }
        }

        if(carry == 1){
            ListNode* temp = new ListNode;
            temp->val = carry;
            temp->next = nullptr;

            result->next = temp;
        }

        return head;
    }
};

ListNode* createList(vector<int>& nums) {
    ListNode* list;
    ListNode* head;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
        // printf("inserting\n");
        if(i == 0){
            head = new ListNode;
            head->val = nums[i];
            head->next = nullptr;

            list = head;
        } else {
            ListNode* temp = new ListNode;
            temp->val = nums[i];
            temp->next = nullptr;

            list->next = temp;
            list = temp;
        }
    }

    return head;
}

void printList(ListNode* list){
    while(list != nullptr) {
        printf("%d -> ", list->val);
        list = list->next;
    }
    printf("\n");
}

int main() {
    Solution sol;

    // vector<int> t1l1{2, 4, 3};
    // vector<int> t1l2{5,6,4};

    vector<int> t1l1{9,9,9,9,9,9,9};
    vector<int> t1l2{9,9,9,9};

    ListNode* listl1 = createList(t1l1);
    ListNode* listl2 = createList(t1l2);

    ListNode* t1ans = sol.addTwoNumbers(listl1, listl2);
    
    printList(t1ans);

    fflush(stdout);
    return 0;
}