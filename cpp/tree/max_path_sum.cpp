// https://leetcode.com/problems/binary-tree-maximum-path-sum/
// A path in a binary tree is a sequence of nodes where each pair of adjacent nodes in the sequence has an edge connecting them. A node can only appear in the sequence at most once. Note that the path does not need to pass through the root.

// The path sum of a path is the sum of the node's values in the path.

// Given the root of a binary tree, return the maximum path sum of any non-empty path.

// Example 1:
// Input: root = [1,2,3]
// Output: 6
// Explanation: The optimal path is 2 -> 1 -> 3 with a path sum of 2 + 1 + 3 = 6.

// Example 2:
// Input: root = [-10,9,20,null,null,15,7]
// Output: 42
// Explanation: The optimal path is 15 -> 20 -> 7 with a path sum of 15 + 20 + 7 = 42.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

#include<vector>
#include<queue>
#include<iostream>

using namespace std;

 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
  
// class Solution {
// public:
//     int maxPathSum(TreeNode* root) {
//         int minVal = - __INT_MAX__;
//         findMaxSum(root, minVal);

//         return minVal;
//     }

//     int findMaxSum(TreeNode* root, int& maxSum) {

//         if(root == nullptr){
//             return maxSum;
//         } else {

//             int leftSubTreeSum = 0, rightSubTreeSum = 0;

//             if(root->left != nullptr) {
//                 leftSubTreeSum = findMaxSum(root->left, maxSum);
//                 maxSum = max(maxSum, leftSubTreeSum);
//             }

//             if(root->right != nullptr) {
//                 rightSubTreeSum = findMaxSum(root->right, maxSum);
//                 maxSum = max(maxSum, rightSubTreeSum);
//             }

//             maxSum = max(leftSubTreeSum + rightSubTreeSum + root->val, maxSum);

//             int currentSum = max(leftSubTreeSum, rightSubTreeSum) + root->val;

//             currentSum = max(currentSum, root->val);

//             return currentSum ;

//         }
//     }
// };

class Solution {
public:
    int minVal = - __INT_MAX__;

    int maxPathSum(TreeNode* root) {
        findMaxSum(root);

        return minVal;
    }

    int findMaxSum(TreeNode* root) {

        if(root == nullptr){
            return 0;
        } else {
            int leftSubTreeSum = max(findMaxSum(root->left), 0);

            int rightSubTreeSum = max(findMaxSum(root->right), 0);

            minVal = max(leftSubTreeSum + rightSubTreeSum + root->val, minVal);

            return root->val + max(leftSubTreeSum, rightSubTreeSum) ;

        }
    }
};

TreeNode* createTree(vector<int>& nums){
    TreeNode* root = new TreeNode(nums[0]);
    TreeNode* current;


    queue<TreeNode*> q;

    int n = nums.size();

    q.push(root);

    for(int i = 0; i < n; i++){
        if(nums[i] == __INT_MAX__) {
            continue;
        }

        current = q.front();
        q.pop();


        // printf("Saving for %d\n", current->val);
        if(2 * i + 1 < n && nums[2 * i + 1] != __INT_MAX__){
            current->left = new TreeNode(nums[2 * i + 1]);
            q.push(current->left);
        }

        if(2 * i + 2 < n && nums[2 * i + 2] != __INT_MAX__){
            current->right = new TreeNode(nums[2 * i + 2]);
            q.push(current->right);
        }

    }

    return root;
}

int main() {
    Solution sol;
    vector<int> t1{-10,9,20,__INT_MAX__, __INT_MAX__, 15,7};
    // vector<int> t1{1,-2,3};

    TreeNode* tree = createTree(t1);

    // printf("tree root %d\n", tree->val);

    printf("max: %d\n", sol.maxPathSum(tree));

    return 0;
}