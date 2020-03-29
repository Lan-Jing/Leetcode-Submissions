#include <iostream>
using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    int findLucky(vector<int>& arr) {
        int n = arr.size();
        int ans = -1;
        for(int i = 0;i < n;i++) {
            int count = 0;
            for(int j = 0;j < n;j++)
                if(arr[j] == arr[i]) count++;
            if(count == arr[i] && arr[i] > ans) ans = arr[i]; 
        }
        return ans;
    }
};

int main() {

}