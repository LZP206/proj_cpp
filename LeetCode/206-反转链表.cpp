using namespace std;
#include<iostream>

// 先定义单链表节点数据类型
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};


// 双指针法
class Solution {
    public:
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* pre = nullptr;
        ListNode* temp;
        while(curr != nullptr){
            temp = curr->next;
            curr->next = pre;
            // 更新curr和pre指针
            pre = curr;
            curr = temp;
        }
        delete temp;
        return pre;
    }
};

// 递归法: 与双指针法一样的思路
class Solution2{
    public:
    ListNode* reverse(ListNode* pre, ListNode* curr){
        if (curr != nullptr){
            ListNode* temp = curr->next;
            curr->next = pre;
            return reverse(curr, temp);
        }
        else {return pre;}
    }
    ListNode* reverseList(ListNode* head){ return reverse(nullptr, head);}
};

// 递归法2：从后往前反转指针指向
class Solution3{
    public:
    ListNode* reverseList(ListNode* head){}
};


