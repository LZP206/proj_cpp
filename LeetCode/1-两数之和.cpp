#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
    public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for (int i = 0; i < nums.size(); i++) {
            unordered_map<int,int>::iterator it = map.find(target - nums[i]);
            if (it != map.end()) {
                return {i,it->second};
            }
            map.insert(pair<int,int>(nums[i], i));
        }
        return {};
    }
};

