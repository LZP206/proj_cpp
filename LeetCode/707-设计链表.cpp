using namespace std;
#include<iostream>

class MyLinkedList {
    public:
    // 定义单链表节点数据类型
    struct ListNode{
        int val;
        ListNode* next;
        ListNode(int x):val(x),next(NULL){}
    };
    // 构造函数，初始化链表
    MyLinkedList(){
        this->_size = 0;
        this->_dummyHead = new ListNode(0);
    }

    // 在头部添加节点
    void addAtHead(int value){
        ListNode* newNode = new ListNode(value);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }
    // 在尾部添加节点
    void addAtTail(int value){
        ListNode* curr = _dummyHead;
        while(curr->next != nullptr) {
            curr = curr->next;
        }
        ListNode* newNode = new ListNode(value);
        curr->next = newNode;
        _size++;
    }
    // 在index位置添加值为value的节点
    void addAtIndex(int index, int value){
        if(index > this->_size) {return;}
        ListNode* curr = this->_dummyHead;
        while(index--){
            curr = curr->next;
        }
        ListNode* newNode = new ListNode(value);
        newNode->next = curr->next;
        curr->next = newNode;
        this->_size++;
    }
    // 返回index位置的值
    int get(int index){
        if (index > this->_size-1 || index < 0){return -1;}
        ListNode* curr = this->_dummyHead;
        while(index--){
            curr = curr->next;
        }
        return curr->next->val;
    }
    // 删除链表的第index个节点
    void deleteAtIndex(int index){
        if (index > this->_size-1 || index < 0){return;}
        ListNode* curr = this->_dummyHead;
        while (index--)
        {
            curr = curr->next;
        }
        ListNode* tmp = curr->next;
        curr->next = curr->next->next;
        delete tmp;
        this->_size--;
    }
    // 打印链表
    void printLinkedList() {
        ListNode* cur = _dummyHead;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    private:
    int _size;
    ListNode* _dummyHead;
};



int main() {
    MyLinkedList list;
    list.addAtTail(1);
    list.addAtTail(2);
    list.addAtTail(3);
    list.addAtTail(4);
    list.addAtTail(5);
    list.printLinkedList(); // 1 2 3 4 5

    list.addAtIndex(2,6);
    list.printLinkedList(); // 1 2 6 3 4 5

    list.get(3);
    list.deleteAtIndex(3);  // 3
    list.printLinkedList(); // 1 2 6 4 5

    system("pause");
    return 0;
}