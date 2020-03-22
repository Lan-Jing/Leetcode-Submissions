#include <iostream>
using namespace std;
#include <string>
#include <vector>

class CustomStack {
public:
    CustomStack(int maxSize) {
        if(maxSize > stack.size()) {
            if(stack.size() == 0) back = 0;
            stack.resize(maxSize), this->maxSize = maxSize;
        }
    }
    
    void push(int x) {
        if(back < this->maxSize) stack[back++] = x;
    }
    
    int pop() {
        int ans = -1;
        if(back) {
            ans = stack[--back];
        }
        return ans;
    }
    
    void increment(int k, int val) {
        for(int i = 0;i < min(k, back);i++)
            stack[i] += val;
    }
    vector<int> stack;
    int maxSize, back;
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */

int main() {

}