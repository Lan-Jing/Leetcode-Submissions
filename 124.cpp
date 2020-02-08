#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <stdint.h>

/*
    a medium dfs on tree. for any node i, consider the maximum sum:
    1. from root to i
    2. from left subtree to i
    3. from right subtree to i.
    Then the path with maximum sum comes from combinations of two of the three branches above.
*/
 
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
    };
    void findPos(TreeNode* &root) {
        ans = max(ans,root->val);
        if(root->left != nullptr) findPos(root->left);
        if(root->right != nullptr) findPos(root->right);
    }
    int TreeDP(TreeNode* &root, int upMax) {
        upMax = upMax + root->val > 0 ? upMax + root->val : 0;
        int leftDown = root->left == nullptr ? 0 : TreeDP(root->left,upMax);
        int rightDown = root->right == nullptr ? 0 : TreeDP(root->right,upMax);
        ans = max(ans,max(max(leftDown,rightDown) + upMax,leftDown + rightDown + root->val));
        int downMax = max(leftDown,rightDown) + root->val > 0 ? max(leftDown,rightDown)+root->val : 0;
        return downMax;
    }
    int ans = INT32_MIN;
    int maxPathSum(TreeNode* root) {
        findPos(root);
        if(ans < 0) return ans;
        TreeDP(root,0);
        return ans;
    }
};

int main() {

}