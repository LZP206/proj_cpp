using namespace std;
#include <iostream>

// 先定义单链表节点数据类型
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(NULL){}
};

// 双指针的经典
class Solution {
    public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* _dummyHead = new ListNode(0);
        _dummyHead->next = head;
        ListNode* fast = _dummyHead;
        ListNode* slow = _dummyHead;
        while (n-- && fast != nullptr){fast = fast->next;}
        fast = fast->next;
        
        while (fast != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        return _dummyHead->next;
    }
};

