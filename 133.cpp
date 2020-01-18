#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include <map>

/*
    modified dfs.
    1. use a list to maintain and check if new nodes exist.
    2. for every linked edge, connect a clone one for the new graph
    3. like original dfs, only go to nodes that haven't been visited.
    4. mind that edges we followed are only subset of edges we built.
*/

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(){
        val = 0; neighbors = vector<Node*>();
    }
    Node(int _val){
        val = _val; neighbors = vector<Node*>();
    }
};
class Solution {
public:
    Node* list[101];
    map<Node*,int> vis;
    void dfsBuild(Node* &oldNow, Node* &newNow) {
        vis[oldNow] = 1;
        for(int i = 0;i < oldNow->neighbors.size();i++) {
            if(list[oldNow->neighbors[i]->val] != NULL){
                newNow->neighbors.push_back(list[oldNow->neighbors[i]->val]);
                continue;
            }
            list[oldNow->neighbors[i]->val] = new Node(oldNow->neighbors[i]->val);
            newNow->neighbors.push_back(list[oldNow->neighbors[i]->val]);
        }
        for(int i = 0;i < oldNow->neighbors.size();i++) {
            if(!vis[oldNow->neighbors[i]])
                dfsBuild(oldNow->neighbors[i],list[oldNow->neighbors[i]->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(node == NULL) return NULL;
        for(int i = 0;i < 101;i++) list[i] = NULL;
        list[node->val] = new Node(node->val);
        dfsBuild(node,list[node->val]);
        return list[node->val];
    }
};

int main(){

}