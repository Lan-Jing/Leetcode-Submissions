#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <cmath>
#include <vector>

/*
    for each node, the possible value should be in the range determined by its ancestors.
    Each left recursion narrow the right bound, while right recurision narrowing the left.
    The edge condition should be treated as the range for root node is not clear, but can be 
    solved by node-to-node comparison.
*/

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool valid(TreeNode *root, long long int leftBound, long long int rightBound) {
        if(root == NULL) return true;
        if(root->left != NULL){
            if(root->left->val >= root->val) return false;
            if(root->left->val <= leftBound) return false;
        }
        if(root->right != NULL){
            if(root->right->val <= root->val) return false;
            if(root->right->val >= rightBound) return false;
        }
        return valid(root->left,leftBound,root->val) && valid(root->right,root->val,rightBound);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root,-pow(2,63),pow(2,63)-1);
    }
};

int main() {
}