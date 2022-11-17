using namespace std;
#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slowIndex = 0;
        int fastIndex = 0;
        for (fastIndex=0;fastIndex<nums.size(); fastIndex++) {
            if (nums[fastIndex] != val){
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
        }
        return slowIndex;
    }
};