// https://leetcode.com/problems/validate-binary-search-tree/
// Given the root of a binary tree, determine if it is a valid binary search tree (BST).

// A valid BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.

// Example 1:
// Input: root = [2,1,3]
// Output: true

// Example 2:
// Input: root = [5,1,4,null,null,3,6]
// Output: false
// Explanation: The root node's value is 5 but its right child's value is 4.

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -231 <= Node.val <= 231 - 1

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

//    Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> traversal;
        inorder(root, traversal);

        int n = traversal.size();

        for(int i = 1; i < n; i++){
            if(traversal[i] <= traversal[i - 1]){
                return false;
            }
        }

        return true;
    }


    void inorder(TreeNode* root, vector<int>& traversal) {
        if(root == nullptr){
            return;
        }

        inorder(root->left, traversal);
        traversal.push_back(root->val);
        inorder(root->right, traversal);
    }

    TreeNode* createTree(vector<int>& arr){
        TreeNode* head, *curr;

        head = new TreeNode(arr[0]);

        queue<TreeNode*> q;

        q.push(head);

        int i = 0, n = arr.size();

        while(q.size() != 0 && i < n){
            if(arr[i] == 10001){
                i++;
                continue;
            }

            curr = q.front();
            q.pop();

            if(2 * i + 1 < n && arr[2*i+1] != 10001){
                TreeNode* node = new TreeNode(arr[2*i+1]);
                curr->left = node;
                q.push(node);
            }

            if(2 * i + 2 < n && arr[2*i+2] != 10001){
                TreeNode* node = new TreeNode(arr[2*i+2]);
                curr->right = node;
                q.push(node);
            }

            i++;
        }

        return head;
    }
};


int main(){

    Solution sol;

    vector<int> t1 = {2,1,3};
    // vector<int> t1 = {5,1,4,10001,10001,3,6};
    
    TreeNode* tree = sol.createTree(t1);

    printf("%d", sol.isValidBST(tree));
    return 0;
}