#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <set>
#include <algorithm>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    }
    void dfs_build(vector<int> &seq, TreeNode* root) {
        seq.push_back(root->val);
        if(root->left != NULL) dfs_build(seq, root->left);
        if(root->right != NULL) dfs_build(seq, root->right);
    }
    void dfs_buildTree(vector<int> &seq, TreeNode* root, int now, int left, int right) {
        int nextLeft = (left + now) / 2, nextRight = (now + right + 1) / 2;
        cout<<now<<' '<<seq[now]<<':'<<nextLeft<<' '<<nextRight<<endl;
        if(left <= nextLeft && nextLeft < now) {
            TreeNode* newLeft = new TreeNode(seq[nextLeft]);
            root->left = newLeft;
            dfs_buildTree(seq, newLeft, nextLeft, left, now-1);
        }
        if(now < nextRight && nextRight <= right) {
            TreeNode* newRight = new TreeNode(seq[nextRight]);
            root->right = newRight;
            dfs_buildTree(seq, newRight, nextRight, now+1, right);
        }
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> seq;
        dfs_build(seq, root);    
        sort(seq.begin(), seq.end());
        TreeNode* newRoot = new TreeNode(seq[(seq.size()-1)/2]);
        dfs_buildTree(seq, newRoot, (seq.size()-1)/2, 0, seq.size()-1);
        return newRoot;    
    }
};

int main() {

}