using namespace std;
#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>



// 双指针实现
class Solution {
    public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {return result;}
            if (i >= 1 && nums[i] == nums[i-1]) {continue;} // 第一个数去重
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                if (nums[i] + nums[left] + nums[right] > 0) {right--;}
                else if (nums[i] + nums[left] + nums[right] < 0) {left++;}
                else {
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (right > left && nums[left] == nums[left+1]) {left++;}// 第二个数去重
                    while (right > left && nums[right] == nums[right-1]) {right--;}// 第三个数去重
                    left++; right--; // 找到答案时，双指针同时收缩 (注意位置)
                }
            }
        }
        return result;
    }
};



