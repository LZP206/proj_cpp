#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Sort {
    public:
    // 堆排序
    void heapSort(vector<int> & nums) {
        int last =  nums.size()-1; // 找到最大堆
        for (int i = (last-1)/2; i >= 0; i--) adjustHeap(nums, i, last);
        // 堆调整        
		while (last >= 0) {            
			swap(nums[0], nums[last--]);            
			adjustHeap(nums, 0, last); 
        }
    }
    void adjustHeap(vector<int> & nums, int i, int last) {        
		int left, right, j;        
		left = 2 * i + 1;        
		while (left <= last) {            
			right = left + 1;            
			j = left;            
			if (j < last && nums[left] < nums[right]) j++;                       
			if (nums[i] < nums[j]) {                
				swap(nums[i], nums[j]);                
				i = j;                
				left = 2 * i + 1;            
			} else {                
				break; // 停止筛选            
			}        
		}    
	}    


    // 快速排序算法
    void quickSort(vector<int> & nums) {internalPartition(nums, 0, nums.size()-1);}
    void internalPartition(vector<int> & nums, int start, int end) {
        if (start >= end) return;
        int i = start, j = end;
        int pivot = nums[i];
        while (i < j) {
            while (i < j && nums[j] >= pivot) j--;
            nums[i] = nums[j];
            while (i < j && nums[i] <= pivot) i++;
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        internalPartition(nums, start, i-1); // 这里递归时可能 start > i-1
        internalPartition(nums, i+1, end);   // 所以一开始递归的结束条件是 start >= end 而不是 start == end
    }


    // 归并排序算法
    void mergeSort(vector<int> & nums) {internalMerge(nums, 0, nums.size()-1);}
    void internalMerge(vector<int> & nums, int left, int right) {
        if(left == right) return;
        if (left < right) {
            int mid = (left + right) /2;
            internalMerge(nums, left, mid);
            internalMerge(nums, mid+1, right);
            // 再完成当前子序列的排序
            int i = left,j = mid+1, k = 0;
            int temp[right-left+1];
            while(i <= mid && j <= right) temp[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
            while(i <= mid) temp[k++] = nums[i++];
            while(j <= right) temp[k++] = nums[j++];
            for(int i = 0; i < right-left+1; i++) nums[left+i] = temp[i];
        }
    }

    // 插入排序
    void insertionSort(vector<int> & nums) {
        for(int i = 1; i < nums.size(); i++) {
            int position = i;
            int value = nums[i];
            while (position > 0 && nums[position-1] > value) {
                nums[position] = nums[position-1];
                position--;
            }
            nums[position] = value;
        }
    }

    // 冒泡排序
    void bubbleSort(vector<int> & nums) {
        int len = nums.size();
        for (int i = len-1; i > 0; i--){
            for (int j = 0; j < i; j++){
                if(nums[j] > nums[j+1]) swap(nums[j], nums[j+1]);
            }
        }
    }

    // 选择排序
    void selectionSort(vector<int> & nums) {
        int len = nums.size();
        int minIndex;
        for(int i = 0; i < len-1; i++) {
            minIndex = i;
            for (int j = i+1; j < len; j++){
                if(nums[minIndex] > nums[j]) minIndex = j;
            }
            if (minIndex != i) swap(nums[i], nums[minIndex]); 
        }
    }
    

};

void printArray(vector<int> &nums){
    for(vector<int>::iterator it = nums.begin(); it < nums.end(); it++) cout << *it << " ";
    cout << endl;
}



int main() {
    vector<int> arr;
    arr.push_back(4);
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(2);
    arr.push_back(0);
    arr.push_back(2);

    Sort Collection;
    Collection.heapSort(arr); printArray(arr);

    


    return 0;
}