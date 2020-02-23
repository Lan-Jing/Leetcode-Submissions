#include <iostream>
using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    bool dfsCheck(int &viscnt, int now, int before, vector<int> &leftChild, vector<int> &rightChild) {
        viscnt++;
        int res = 1;
        if(leftChild[now] != -1) {
            if(leftChild[now] == before) return false;
            res &= dfsCheck(viscnt, leftChild[now], now, leftChild, rightChild);
        }
        if(rightChild[now] != -1) {
            if(rightChild[now] == before) return false;
            res &= dfsCheck(viscnt, rightChild[now], now, leftChild, rightChild);
        }
        return res;
    } 
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int root = -1;
        int viscnt = 0;
        vector<int> indegree(n,0);
        for(int i = 0;i < n;i++){
            if(leftChild[i] != -1) indegree[leftChild[i]]++;
            if(rightChild[i] != -1) indegree[rightChild[i]]++;
        }
        for(int i = 0;i < n;i++){
            if(indegree[i] > 1) return false;
            if(!indegree[i]) root = i;
        }
        if(root == -1) return false;
        int flag = dfsCheck(viscnt, root, -2, leftChild, rightChild);
        if(!flag || viscnt < n) return false;
        return true;
    }  
};

int main() {

}