// https://leetcode.com/explore/interview/card/amazon/78/trees-and-graphs/507/
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

// Example 1:

// Input: root = [1,2,2,3,4,4,3]
// Output: true

// Example 2:

// Input: root = [1,2,2,null,3,null,3]
// Output: false

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -100 <= Node.val <= 100

// Follow up: Could you solve it both recursively and iteratively?

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
    bool isSymmetric(TreeNode* root) {
        vector<vector<int>> t;

        dfs(root, t, 0);

        int n = t.size();

        for(int i = 0; i < n; i++){
            int m = t[i].size();

            int j = 0, k = m - 1;
            
            while(j < k){
                if(t[i][j++] != t[i][k--]){
                    return false;
                }
            }
        }

        return true;
    }

    void dfs(TreeNode *root, vector<vector<int>>& t, int level){

        int val;
        if(root == nullptr){
            val = 10001;
        } else {
            val = root->val;
        }

        if(level + 1 > t.size()){
            t.push_back({val});
        } else {
            t[level].push_back(val);
        }

        if(root != nullptr){
            dfs(root->left, t, level + 1);
            dfs(root->right, t, level + 1);
        }
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

    vector<int> t1 = {1,2,2,3,4,4,3};
    // vector<int> t1 = {1,2,2,10001,3,10001,3};

    // vector<int> t1 = {5,1,4,10001,10001,3,6};
    
    TreeNode* tree = sol.createTree(t1);

    printf("%d", sol.isSymmetric(tree));
    return 0;
}