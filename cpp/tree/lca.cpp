// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

// Example 1:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
// Output: 3
// Explanation: The LCA of nodes 5 and 1 is 3.

// Example 2:

// Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
// Output: 5
// Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

// Example 3:

// Input: root = [1,2], p = 1, q = 2
// Output: 1

#include<iostream>
#include<vector>
#include<queue>

using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pParents, qParents;

        dfsParent(root, pParents, p);
        dfsParent(root, qParents, q);

        int i = pParents.size() - 1, j = qParents.size() - 1;

        while(i >= 0 && j >= 0){
            if(pParents[i]->val != qParents[j]->val){
                return pParents[i + 1];
            }
            i--;
            j--;
        }

        if(i >= 0) {
            return pParents[i + 1];
        }

        if(j >= 0) {
            return qParents[j + 1];
        }
        
        return NULL;
    }

    bool dfsParent(TreeNode* root, vector<TreeNode*>& parents, TreeNode* item){
        if(root == NULL) {
            return false;
        }

        if(root->val == item->val) {
            parents.push_back(root);
            return true;
        } else if(dfsParent(root->left, parents, item)) {
            parents.push_back(root);
            return true;
        } else if(dfsParent(root->right, parents, item)) {
            parents.push_back(root);
            return true;
        } else {
            return false;
        }
    }

    TreeNode* createTree(vector<int>& arr){
        TreeNode* head = new TreeNode(arr[0]);

        int n = arr.size();

        queue<TreeNode*> q;
        q.push(head);

        TreeNode* curr;

        int i = 0;

        while(i < n){
            if(arr[i] == 100001) {
                i++;
                continue;
            }

            curr = q.front();
            q.pop();

            // printf("For node: %d, ", curr->val);
            if(2 * i + 1 < n && arr[2 * i + 1] != 100001) {
                // printf("inserting left: %d, ", arr[2 * i + 1]);
                curr->left = new TreeNode(arr[2 * i + 1]);
                q.push(curr->left);
            }

            if(2 * i + 2 < n && arr[2 * i + 2] != 100001) {
                // printf("inserting right: %d, \n", arr[2 * i + 2]);
                curr->right = new TreeNode(arr[2 * i + 2]);
                q.push(curr->right);
            }

            i++;
        }

        return head;
    }

    TreeNode* findNodeBfs(TreeNode* tree, int item) {
        queue<TreeNode*> q;
        q.push(tree);

        TreeNode* curr;
    
        while(q.size() != 0){
            curr = q.front();
            q.pop();

            // printf("%d ", curr->val);

            if(curr->val == item) {
                return curr;
            } else {
                if(curr->left != NULL) {
                    q.push(curr->left);
                }

                if(curr->right != NULL) {
                    q.push(curr->right);
                }
            }
        }

        // printf("\n");
        return NULL;
    }
};

int main() {
    vector<int> t1 = {3,5,1,6,2,0,8,100001,100001,7,4};

    Solution sol;

    TreeNode* tree = sol.createTree(t1);

    printf("\n");

    // printf("%d", sol.findNodeBfs(tree, 1)->val);

    printf("Result: %d", sol.lowestCommonAncestor(tree, sol.findNodeBfs(tree, 6), sol.findNodeBfs(tree, 6))->val);
}