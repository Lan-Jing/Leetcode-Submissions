#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <utility>

class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left, *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    void PreOrderRebuild(vector<pair<int,int> > &vec, TreeNode *root, int &ptr) {
        int now = ptr;
        if(ptr+1 < vec.size() && vec[ptr+1].second > vec[now].second){
            ptr++;
            root->left = new TreeNode(vec[ptr].first);
            PreOrderRebuild(vec,root->left,ptr);
        }
        if(ptr+1 < vec.size() && vec[ptr+1].second > vec[now].second){
            ptr++;
            root->right = new TreeNode(vec[ptr].first);
            PreOrderRebuild(vec,root->right,ptr);
        }
    }
    TreeNode* recoverFromPreorder(string S) {
        vector<pair<int,int> > vec;
        int l = S.length();
        int num = 0;
        vec.push_back(make_pair(0,0));
        for(int i = 0;i < l;i++){
            if(S[i] == '-'){
                if(num){
                    vec.back().first = num;
                    num = 0;
                    vec.push_back(make_pair(0,0));                    
                }
                vec.back().second++;
            }else{
                num = num*10 + S[i]-'0';
            }
        }
        vec.back().first = num;
        TreeNode *root = new TreeNode(vec[0].first);
        int ptr = 0;
        PreOrderRebuild(vec,root,ptr);
        return root;
    }
};

int main() {
    Solution sol;
    string input = "1-2--3---4-5--6---7";
    sol.recoverFromPreorder(input);
    return 0;
}