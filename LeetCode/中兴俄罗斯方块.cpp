using namespace std;
#include <iostream>
#include <vector>


class Solution {
    public:
    int needSUM_V2(vector<int> &nums) {
        int sum = 0;
        int left = 0;
        int right = nums.size()-1;
        while (left < right) {
            while(nums[left] == 0) left++;
            while (nums[right] == 0) right--;
            if (left < right){ 
                for (int i = left; i <= right; i++) {
                    if(nums[i] == 0) sum++;
                    if(nums[i] > 0) nums[i]--;
                }
            }
        }
        return sum;
    }


    int needSUM(vector<int> &nums) {
        int sum = 0;
        vector<int> array;
        for(int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                if (nums[i] > nums[i+1]) array.push_back(i);
            }
            else if (i == nums.size()-1) {
                if(nums[i] > nums[i-1]) array.push_back(i);
            } 
            else {
                if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) array.push_back(i);
                if (nums[i] == nums[i-1] && nums[i] > nums[i+1]) array.push_back(i);
                if (nums[i] > nums[i-1] && nums[i] == nums[i+1]) array.push_back(i);
            }
        }
        for(int i = 1; i < array.size();i++){
                if (array[i] - array[i-1] > 1) {
                    int left = array[i-1], right = array[i];
                    for (int idx = left+1; idx < right;idx++){
                        sum = sum + min(nums[left], nums[right]) - nums[idx];
                    }
                }
        }
        return sum;
    }
    // 打印用来判断极值点位置是否找对
    void printArray(vector<int> &nums) {
        vector<int> array;
        for(int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                if (nums[i] > nums[i+1]) array.push_back(i);
            }
            else if (i == nums.size()-1) {
                if(nums[i] > nums[i-1]) array.push_back(i);
            } 
            else {
                if (nums[i] > nums[i-1] && nums[i] > nums[i+1]) array.push_back(i);
                if (nums[i] == nums[i-1] && nums[i] > nums[i+1]) array.push_back(i);
                if (nums[i] > nums[i-1] && nums[i] == nums[i+1]) array.push_back(i);
                
                // if ( (nums[i] >= nums[i-1] && nums[i] > nums[i+1]) || (nums[i] > nums[i-1] && nums[i] >= nums[i+1]) ) array.push_back(i);
            }
        }
        for(int i = 0; i < array.size();i++) {cout << array[i] << " ";}
    }
};



int main() {
    vector<int> test;
    test.push_back(0);
    test.push_back(1);
    test.push_back(0);
    test.push_back(2);
    test.push_back(1);
    test.push_back(0);
    test.push_back(1);
    test.push_back(3);
    test.push_back(2);
    test.push_back(1);
    test.push_back(2);
    test.push_back(1);
    
    vector<int> test2;
    test2.push_back(4);
    test2.push_back(4);
    test2.push_back(4);
    test2.push_back(0);
    test2.push_back(0);
    test2.push_back(0);
    test2.push_back(0);
    test2.push_back(2);
    test2.push_back(3);
    test2.push_back(3);
    
    Solution s;
    int res = s.needSUM(test);
    cout << res << " "; s.printArray(test); cout << endl;
    res = s.needSUM(test2); 
    cout << res << " "; s.printArray(test2); cout << endl;

    cout << s.needSUM_V2(test) << endl;
    cout << s.needSUM_V2(test2) << endl;
    

    system("pause");
    return 0;
}