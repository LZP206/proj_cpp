using namespace std;
#include<iostream>

// 定义单链表数据类型
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x): val(x),next(NULL) {}
};

class Solution {
    public:
    // 设置虚拟头结点的方式
    ListNode* removeElements_dummy(ListNode* head, int value){
        ListNode*_dummyHead = new ListNode(0);
        _dummyHead->next = head;
        ListNode* curr = _dummyHead;
        while (curr->next != nullptr) {
            if (curr->next->val == value){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete temp;
            }
            else{
                curr = curr->next;
            }
        }
        head = _dummyHead->next;
        delete _dummyHead;
        return head;
    }
    
    // 分开删除头节点和其他节点的方式
    ListNode* removeElements(ListNode* head, int value){
        // 删除头结点
        while(head != nullptr && head->val == value){
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        // 删除其他节点
        ListNode* curr = head;
        while(curr != nullptr && curr->next != nullptr){
            if(curr->next->val == value){
                ListNode* tmp = curr->next;
                curr->next = curr->next->next;
                delete tmp;
            }
            else{
                curr = curr->next;
            }
        }
        return head;
    }
};

void test() {

}


int main() {
    test();
    system("pause");
    return 0;
}