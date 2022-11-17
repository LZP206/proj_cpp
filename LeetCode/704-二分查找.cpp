using namespace std;
#include <iostream>
#include <vector>


// 左闭右闭
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        int middle;
        while (left <= right)
        {
            middle = (left+right) / 2;
            if (nums[middle] > target){
                right = middle - 1;
            }
            else if (nums[middle] < target){
                left = middle + 1;
            }
            else{
                return middle;
            }
        }
        return -1;
    }
};

// 左闭右开
class Solution2 {
    public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int middle;
        while (left < right){
            middle = (left+right) / 2;
            if (nums[middle] > target){
                right = middle;
            }
            else if (nums[middle] < target) {
                left = middle + 1;
            }
            else {
                return middle;
            }
        }
        return -1;
    }
};