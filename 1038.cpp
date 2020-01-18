#include <iostream>
using namespace std;
#include <string>

/*
    a carefully modified post-order traverse.
    For computing the new value of a node, 
    we need to know sum of numbers from right.
    This could come from the right subtree of the node(rSum), or father and right
    brother of the node(rightSum).
    1. for rSum, use return values of dfs to add up values from subtree.
    2. for rightSum, pass to dfs process as a parameter 
    3. if there's no right child for a node, the new value is rightSum.
    4. Otherwise is it rSum (rSum > rightSum as values from the subtree is counted in rSum).
*/

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int Traverse(TreeNode *now, int rightSum){
        int rSum = 0, maxSum = 0;
        if(now->right != NULL) rSum = Traverse(now->right,rightSum);
        now->val += (now->right == NULL) ? rightSum : rSum;
        if(now->left != NULL) maxSum = Traverse(now->left,now->val);
        if(now->left != NULL) return maxSum;
        else return now->val;
    }
    TreeNode* bstToGst(TreeNode *root) {
        Traverse(root,0);
        return root;
    }
};

int main() {

}