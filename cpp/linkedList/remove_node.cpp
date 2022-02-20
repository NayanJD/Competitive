// https://leetcode.com/explore/interview/card/google/60/linked-list-5/3064/
// Given the head of a linked list, remove the nth node from the end of the list and return its head.
// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]
// Example 2:

// Input: head = [1], n = 1
// Output: []
// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]

// Constraints:

// The number of nodes in the list is sz.
// 1 <= sz <= 30
// 0 <= Node.val <= 100
// 1 <= n <= sz
 

// Follow up: Could you do this in one pass?

#include<vector>
#include<iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p1 = nullptr;
        ListNode* curr = head;

        int i = 0;
        while(curr != nullptr){
            if(i > n - 1){
                if(p1 == nullptr){
                    p1 = head;
                } else {
                    p1 = p1->next;
                }
            }

            curr = curr->next;
            i++;
        }

        if(p1 == nullptr){
            head = head->next;
        } else {
            p1->next = p1->next->next;
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

    vector<int> t1 = {1};

    ListNode* head = createList(t1);

    ListNode* deletedHead = sol.removeNthFromEnd(head, 1);
    
    printList(deletedHead);

    return 0;
}

