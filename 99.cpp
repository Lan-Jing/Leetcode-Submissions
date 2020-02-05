#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>
#include <stdint.h>
 
class Solution {
public:
    int a, b, aPos, bPos;
    struct returnNode{
        int totCount, rb, lb;
        returnNode(int _t, int _lb, int _rb) : totCount(_t), lb(_lb), rb(_rb) {}
        returnNode(TreeNode *root) : totCount(1), lb(root->val), rb(root->val) {}
        returnNode() : totCount(0), lb(-1), rb(-1) {}
    };
    int countN(TreeNode *root) {
        int ans = 1;
        if(root->left != nullptr) ans += countN(root->left);
        if(root->right != nullptr) ans += countN(root->right);
        return ans;
    }
    returnNode dfsBuild(TreeNode *root, int leftCountUp, int lbUp, int rbUp) {
        returnNode left, right, tot(root);
        if(root->left != nullptr){
            left = dfsBuild(root->left,leftCountUp,lbUp,root->val);
            tot.lb = left.lb;
        }
        if(root->right != nullptr){
            right = dfsBuild(root->right,leftCountUp + left.totCount + 1,root->val,rbUp);
            tot.rb = right.rb;
        }
        tot.totCount += left.totCount + right.totCount;
        if(left.rb == -1) left.rb = lbUp;
        if(right.lb == -1) right.lb = rbUp;
        int pos = leftCountUp + left.totCount;
        if(left.rb != -1 && right.lb == -1){
            if(root->val < left.rb && bPos < pos) b = root->val, bPos = pos;
        }else if(left.rb == -1 && right.lb != -1){
            if(root->val > right.lb && aPos > pos) a = root->val, aPos = pos;
        }else if(left.rb != -1 && right.lb != -1){
            if(root->val > left.rb && root->val > right.lb && aPos > pos) a = root->val, aPos = pos;
            if(root->val < left.rb && root->val < right.lb && bPos < pos) b = root->val, bPos = pos;
        }
        return tot;
    }
    void dfsPlace(TreeNode* &root, int a, int b) {
        if(root->val == a) root->val = b;
        else if(root->val == b) root->val = a;
        if(root->left != nullptr) dfsPlace(root->left,a,b);
        if(root->right != nullptr) dfsPlace(root->right,a,b);
    }
    void recoverTree(TreeNode* &root) {
        int N = countN(root);
        a = -1, b = -1, aPos = INT32_MAX, bPos = 0;
        dfsBuild(root,0,0,INT32_MAX);
        dfsPlace(root,a,b);
    }
};