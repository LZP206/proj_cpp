using namespace std;
#include <iostream>
#include <vector>

// 双指针实现滑动窗口
class Solution {
    public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int slowIndex = 0;
        int temp_length;
        int result = INT32_MAX;
        int sum = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            sum += nums[fastIndex];
            while (sum >= s) {
                temp_length = fastIndex - slowIndex +1;
                result = result < temp_length ? result:temp_length;
                sum -= nums[slowIndex++];
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};


// 暴力解法
class Solution {
    public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int result = INT32_MAX;
        int length = 0;
        for (int i=0; i<nums.size(); i++) {
            int sum = 0;
            for (int j=i; j<nums.size(); j++) {
                sum += nums[j];
                if (sum >= s) {
                    length = j - i +1;
                    result = result > length ? length : result;
                    break;
                }
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};