#include <iostream>
using namespace std;
#include <string>
#include <cstring>
#include <vector>

/*
    This solution is plain and straight-forward: rebuild the disturbed array and find the two swapped numbers.
    To do this an In-order traverse in needed to compute each element's position in the array. 
    This is calculated by summing up nodes from the left parent and left subtree.
    Notice that a swap should produce two larger numbers and two smaller numbers, such as 1 2 3 4 -> 4 2 3 1
    We only pick up the first larger-than-usual number and the second smaller-then-usual one for swap.
*/
 
class Solution {
public:
    struct TreeNode{
        int val;
        TreeNode *left, *right;
    };
    int countN(TreeNode *root) {
        int ans = 1;
        if(root->left != nullptr) ans += countN(root->left);
        if(root->right != nullptr) ans += countN(root->right);
        return ans;
    }
    int dfsBuild(vector<int> &seg, TreeNode *root, int leftCountUp) {
        int tot = 1, leftCountDown = 0;
        if(root->left != nullptr) leftCountDown = dfsBuild(seg,root->left,leftCountUp);
        tot += leftCountDown;
        seg[leftCountUp + leftCountDown] = root->val;
        if(root->right != nullptr) tot += dfsBuild(seg,root->right,leftCountUp + leftCountDown + 1);
        return tot;
    }
    void dfsPlace(TreeNode* &root, int a, int b){
        if(root->val == a) root->val = b;
        else if(root->val == b) root->val = a;
        if(root->left != nullptr) dfsPlace(root->left,a,b);
        if(root->right != nullptr) dfsPlace(root->right,a,b);
    }
    void recoverTree(TreeNode* &root) {
        int N = countN(root);
        vector<int> seg; seg.resize(N);
        dfsBuild(seg,root,0);
        for(int i = 0;i < N;i++) cout<<seg[i]<<' '; cout<<endl;
        int num[2];
        for(int i = 0;i < N-1;i++)
            if((!i && seg[i] > seg[i+1]) || (seg[i] > seg[i+1] && seg[i] > seg[i-1])){
                num[0] = seg[i]; break;
            }
        for(int j = N-1;j > 0;j--)
            if((j == N-1 && seg[j] < seg[j-1]) || (seg[j] < seg[j-1] && seg[j] < seg[j+1])){
                num[1] = seg[j]; break;
            }

        cout<<num[0]<<' '<<num[1]<<endl;
        dfsPlace(root,num[0],num[1]);
    }
};