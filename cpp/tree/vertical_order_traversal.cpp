// Vertical Order Traversal of a Binary Tree
// Given the root of a binary tree, calculate the vertical order traversal of the binary tree.

// For each node at position (row, col), its left and right children will be at positions (row + 1, col - 1) and (row + 1, col + 1) respectively. The root of the tree is at (0, 0).

// The vertical order traversal of a binary tree is a list of top-to-bottom orderings for each column index starting from the leftmost column and ending on the rightmost column. There may be multiple nodes in the same row and same column. In such a case, sort these nodes by their values.

// Return the vertical order traversal of the binary tree.

// Example 1:
//  Input: root = [3,9,20,null,null,15,7]
// Output: [[9],[3,15],[20],[7]]
// Explanation:
// Column -1: Only node 9 is in this column.
// Column 0: Nodes 3 and 15 are in this column in that order from top to bottom.
// Column 1: Only node 20 is in this column.
// Column 2: Only node 7 is in this column.

// Example 2:
// Input: root = [1,2,3,4,5,6,7]
// Output: [[4],[2],[1,5,6],[3],[7]]
// Explanation:
// Column -2: Only node 4 is in this column.
// Column -1: Only node 2 is in this column.
// Column 0: Nodes 1, 5, and 6 are in this column.
//           1 is at the top, so it comes first.
//           5 and 6 are at the same position (2, 0), so we order them by their value, 5 before 6.
// Column 1: Only node 3 is in this column.
// Column 2: Only node 7 is in this column.

// Example 3:
// Input: root = [1,2,3,4,6,5,7]
// Output: [[4],[2],[1,5,6],[3],[7]]
// Explanation:
// This case is the exact same as example 2, but with nodes 5 and 6 swapped.
// Note that the solution remains the same since 5 and 6 are in the same location and should be ordered by their values.

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>

using namespace std;

// Definition for a binary tree node.
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};  

class Item {
    public:
        int row;
        int val;

        Item(int row, int val): row(row), val(val) {}

        bool operator<(const Item& i2) const{
            if(row < i2.row){
                return false; 
            } else if (row > i2.row){
                return true;
            } else {
                return val > i2.val;
            }
        }
};

class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        TreeNode* current = root;

        // printf("n %d\n", n);

        unordered_map<int, priority_queue<Item>> t;

        int minCol = 10001, maxCol = -10001;


        dfs(root, t, 0, 0, minCol, maxCol);

        vector<vector<int>> result;

        int i = minCol;
        while(i <= maxCol){
            // result.push_back(vector<int>(t[i].))

            vector<int> v;
            while(t[i].size() != 0){
                v.push_back(t[i].top().val);
                t[i].pop();
            }

            result.push_back(v);

            i++;
        }

        return result;
    }

    void dfs(TreeNode* node, unordered_map<int, priority_queue<Item>>& t, int row, int col, int& minCol, int& maxCol){
        if(node == nullptr){
            return;
        }

        minCol = min(col, minCol);
        maxCol = max(col,maxCol);

        if(t.find(col) != t.end()){
            t[col].push(Item(row, node->val));
        } else{
            t[col] = priority_queue<Item>();
            t[col].push(Item(row, node->val));
        }

        dfs(node->left, t, row + 1, col - 1, minCol, maxCol);
        dfs(node->right, t, row + 1, col + 1, minCol, maxCol);
    }

    TreeNode* createTree(vector<int>& arr){
        TreeNode* head, *current;
        int n = arr.size();

        vector<TreeNode*> q;

        head = new TreeNode(arr[0]);
        q.push_back(head);

        int i = 0;

        while(q.size() != 0){
            current = q.front();
            q.erase(q.begin());

            if(2 * i + 1 < n && arr[2 * i + 1] != 1001){
                current->left = new TreeNode(arr[2 * i + 1]);
                q.push_back(current->left);
            }

            if(2 * i + 2 < n && arr[2 * i + 2] != 1001){
                current->right = new TreeNode(arr[2 * i + 2]);
                q.push_back(current->right);
            }

            i++;
        }

        return head;
    }

    void displayTree(TreeNode* head){
        vector<TreeNode*> q;
        TreeNode* current;
        q.push_back(head);

        while(q.size() != 0){
            current = q.front();
            q.erase(q.begin());

            if(current == nullptr){
                printf("null, ");
            } else {

            printf("%d ", current->val);


            q.push_back(current->left);



            q.push_back(current->right);
            }

        }

        printf("\n");
    }

    void print2D(vector<vector<int>> arr){
        printf("[");
        for(int i = 0; i < arr.size(); i++){
            printf("[");
            for(int j = 0; j < arr[i].size(); j++){
                printf("%d,", arr[i][j]);
            }
            printf("],");
        }
        printf("]\n");
    }
};

int main(){
    // vector<int> t1 = {3,9,20,1001,1001,15,7};
    // vector<int> t1 = {1,2,3,4,6,5,7};
    // vector<int> t1 = {0,1,1001,1001,2,6,3,1001,1001,1001,4,1001,5};
    // vector<int> t1 = {3,9,20,1001,1001,15,7};
    vector<int> t1 = {0,8,1,1001,1001,3,2,1001,4,5,1001,1001,7,6};;


    Solution sol;

    TreeNode* head = sol.createTree(t1);
    // sol.displayTree(sol.createTree(t1));


    sol.print2D(sol.verticalTraversal(head));

    return 0;
}