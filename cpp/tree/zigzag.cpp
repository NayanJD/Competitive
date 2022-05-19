// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
// Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

// Example 1:
// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[20,9],[15,7]]

// Example 2:
// Input: root = [1]
// Output: [[1]]

// Example 3:
// Input: root = []
// Output: []

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -100 <= Node.val <= 100


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        queue<pair<int, TreeNode*>> q;

        deque<int> dq;
        
        vector<int> v;

        vector<vector<int>> result;

        if(root == nullptr){
            return result;
        }

        q.push({0, root});


        while(q.size() != 0){
            auto p = q.front();
            q.pop();

            if(result.size() <= p.first) {
                result.push_back({p.second->val});
            } else {
                result[p.first].push_back({p.second->val});
            }

            if(p.second->left != nullptr){
                q.push({p.first + 1, p.second->left});
            }

            if(p.second->right != nullptr){
                q.push({p.first + 1, p.second->right});
            }
        }

        for(int i = 0; i < result.size(); i++){
            if(i % 2 == 0){
                continue;
            }

            for(int j = 0, k = result[i].size() - 1; j < k; j++, k--){
                swap(result[i][j], result[i][k]);
            }
        }

        return result;
    }


    TreeNode* createTree(vector<int>& arr){
        if(arr.size() == 0){
            return nullptr;
        }

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

    // vector<int> t1 = {3,9,20,10001,10001,15,7};

    vector<int> t1 = {};
    
    TreeNode* tree = sol.createTree(t1);

    auto result = sol.zigzagLevelOrder(tree);

    printf("[");
    for(int i = 0; i < result.size(); i++){
        printf("[");
        for(int j = 0; j < result[i].size(); j++){
            printf("%d", result[i][j]);
            if(j != result[i].size() - 1){
                printf(", ");
            }
        }
        printf("]");
    }
    printf("]");

    return 0;
}