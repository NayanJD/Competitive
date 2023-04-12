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
        TreeNode* lca = NULL;
        dfs(root, p, q, lca);
        return lca;
         
    }

    int dfs(TreeNode* node, TreeNode*& p, TreeNode*& q, TreeNode*& ancestor) {
        if(ancestor != NULL){
            return 0;
        }
        
        if(node == NULL){
            return 0;
        }

        int isPresentInLeft = dfs(node->left, p, q, ancestor);
        int isPresentInRight = dfs(node->right, p, q, ancestor);
        int isPresentInHere = ((node->val == p->val) || (node->val == q->val)) ? 1: 0;
        
        if(isPresentInLeft + isPresentInRight + isPresentInHere == 2){
            ancestor = node;
            return 1;
        } else {
            return isPresentInLeft + isPresentInRight + isPresentInHere; 
        }
    }

};


TreeNode* makeTree(vector<int> h) {
    queue<TreeNode*> q;
    
    TreeNode* head = new TreeNode(h[0]);
    q.push(head);
    
    TreeNode* currNode;
    int i = 0, n = h.size();

    while(q.size() != 0){
        currNode = q.front();
        q.pop();
        
        if(currNode == NULL){
            i++;
            continue;
        }

        if(2 * i + 1 < n){
            if(h[2 * i + 1] == (int)10e9) {
                q.push(NULL);
            } else {
                currNode->left = new TreeNode(h[2 * i + 1]);
                q.push(currNode->left);
            }
        }

        if(2 * i + 2 < n){
            if(h[2 * i + 2] == (int)10e9) {
                q.push(NULL);
            } else {
                currNode->right = new TreeNode(h[2 * i + 2]);
                q.push(currNode->right);
            }
        }

        i++;
    }

    return head;
}

int main(){
    Solution sol;

    TreeNode* tree = makeTree({3,5,1,6,2,0,8,(int)10e9,(int)10e9,7,4});
    int p = 5, q = 1;
    
    auto lca = sol.lowestCommonAncestor(tree, new TreeNode(p), new TreeNode(q));
    cout << "LCA: " << lca->val << endl;
    
    tree = makeTree({3,5,1,6,2,0,8,(int)10e9,(int)10e9,7,4});
    p = 5, q = 4;
    
    lca = sol.lowestCommonAncestor(tree, new TreeNode(p), new TreeNode(q));
    cout << "LCA: " << lca->val << endl;
}

