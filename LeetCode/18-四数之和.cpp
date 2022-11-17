using namespace std;
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>


class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++){
            if(nums[i] > target && nums[i] >= 0 && target >= 0) {break;} //一级剪枝
            if(i > 0 && nums[i] == nums[i-1]) {continue;} // 去重
            for (int j = i+1; j < nums.size(); j++){
                if(nums[i]+nums[j] > target && nums[i]+nums[j] >= 0 && target >= 0) {break;} //二级剪枝
                if(j > i+1 && nums[j] == nums[j-1]) {continue;} // 去重

                int left = j + 1;
                int right = nums.size() - 1;

                while (right > left) {
                    // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                    if (nums[i]+nums[j]+nums[left]+nums[right] > target) {right--;}
                    else if (nums[i]+nums[j]+nums[left]+nums[right] < target) {left++;}
                    else {
                        result.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
                        //剪枝
                        while(right > left && nums[right] == nums[right-1]) {right--;}
                        while(right > left && nums[left] == nums[left+1]) {left++;}
                        //找到正确的数组后双指针同时收缩
                        left++; right--;
                    }
                }
            }
        }
        return result;
    }
};