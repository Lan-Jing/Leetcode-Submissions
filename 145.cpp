#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left, *right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    };
    void postOrder(TreeNode *root, vector<int> &ans) {
        if(root->left != NULL) postOrder(root->left,ans);
        if(root->right != NULL) postOrder(root->right,ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root != NULL) postOrder(root,ans);
        return ans;
    }
};

int main() {

}