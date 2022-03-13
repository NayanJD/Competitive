// https://leetcode.com/problems/count-complete-tree-nodes/
// Given the root of a complete binary tree, return the number of the nodes in the tree.

// According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

// Design an algorithm that runs in less than O(n) time complexity.

// Example 1:

// Input: root = [1,2,3,4,5,6]
// Output: 6

// Example 2:

// Input: root = []
// Output: 0
// Example 3:

// Input: root = [1]
// Output: 1

#include<iostream>
#include<vector>
#include<queue>
#include<math.h>

using namespace std;


//   Definition for a binary tree node.
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
    int countNodes(TreeNode* root) {
        int height = findHeight(root, -1);

        if(height == -1){
            return 0;
        } else {
            return pow(2 , height + 1) - 1 - getMissingNodeCount(root, 0, height);
        }

    }

    int getMissingNodeCount(TreeNode* root, int currHeight, int maxHeight){
        if(currHeight >= maxHeight){
            if(root == nullptr){
                return 1;
            } else {
                return 0;
            }
        }

        int isLeftComplete = isLeftSubtreeComplete(root->left, currHeight + 1, maxHeight);

        if(!isLeftComplete){
            return pow(2, maxHeight - currHeight - 1) + getMissingNodeCount(root->left, currHeight+1, maxHeight);
        } else {
            return getMissingNodeCount(root->right, currHeight+1, maxHeight);
        }

    }

    bool isLeftSubtreeComplete(TreeNode* root, int currHeight, int maxHeight) {
        if(currHeight == maxHeight){
            if(root == nullptr){
                return false;
            } else {
                return true;
            }
        } else {
            return isLeftSubtreeComplete(root->right, currHeight + 1, maxHeight);
        }
    }

    int findHeight(TreeNode* root, int height){
        if(root == nullptr){
            return height;
        }

        return findHeight(root->left, height + 1);
    }

    TreeNode* createTree(vector<int>& nums){
        queue<TreeNode*> q;
        TreeNode* root;
        int n = nums.size();

        if(n == 0){
            return nullptr;
        }

        root = new TreeNode(nums[0]);
        q.push(root);

        TreeNode* curr;
        int i = 0;
        while(i < n){
            curr = q.front();
            q.pop();

            if(2 * i + 1 < n){
                curr->left = new TreeNode(nums[2 * i + 1]);
                q.push(curr->left);
            }

            if(2 * i + 2 < n){
                curr->right = new TreeNode(nums[2 * i + 2]);
                q.push(curr->right);
            }


            i++;
        }

        return root;
    }
    
};

int main() {

    Solution sol;

    vector<int> t1 = {1,2,3,4,5};
    // vector<int> t1 = {1};


    TreeNode* root = sol.createTree(t1);

    printf("count: %d", sol.countNodes(root));

    return 0;
}