#include <iostream>
using namespace std;
#include <vector>

/*
    Morris Inorder Traversal with only O(1) space complexity, but slower efficiency.
    The key problem if we remove the stack is how to go back to lower levels after moving deeper? 
    Morris Traversal takes advantage of Binary Thread Tree, which uses empty child fields to store 
    locations of predecessors and successors. 

    The key thought of Morris Traversal is to first set up information tracing back current nodes
    before start going deeper, which will certainly consume more time for trying.
    
    For each node i, in inorder traversal its predecessor locates at the rightmost node in the left subtree of i.
    Also the predecessor surely doesn't right child.

    To use these properties, Consider each node visited, say cur.
    1. If cur doesn't have left child, we reach the leftmost node in a subtree. Consider it as a turning point the 
       traversal. We simply need to print it out and go to the right subtree.
    2. If cur have left child, then there is a predecessor j determined by the property above. 
        1) If the right-child field of j is empty, we point it back to cur to set up a way back. (before going down)
           Then we can savely go left.
        2) If the right-child field of j already points back to cur, the traversal down to j has been completed. (after going back up)
           Then we need to change the pointer back to empty, keeping the tree unchanged.
           Then we can go right.
*/

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left, *right;
    };
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *ptr = root;
        while(ptr != NULL){
            TreeNode *prev = ptr->left;
            if(prev == NULL){
                ans.push_back(ptr->val);
                ptr = ptr->right;
            }else{
                while(prev->right != NULL && prev->right != ptr)
                    prev = prev->right;
                if(prev->right == NULL){
                    prev->right = ptr;
                    ptr = ptr->left;
                }else{
                    prev->right = NULL;
                    ans.push_back(ptr->val);
                    ptr = ptr->right;
                }
            }
        }
        return ans;
    }
};

int main() {

}