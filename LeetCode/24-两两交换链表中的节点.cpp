using namespace std;
#include<iostream>


// 先定义单链表节点数据类型
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

class Solution {
    public:
    ListNode* swapPairs(ListNode* head){
        ListNode* _dummyHead = new ListNode(0);
        _dummyHead->next = head;
        ListNode *curr = _dummyHead;
        while (curr->next != nullptr && curr->next->next != nullptr){
            ListNode* tmp = curr->next;
            ListNode* tmp1 = curr->next->next->next;
            curr->next = curr->next->next;
            curr->next->next = tmp;
            curr->next->next->next = tmp1;

            curr = curr->next->next;

        }
        return _dummyHead->next;
    }
};