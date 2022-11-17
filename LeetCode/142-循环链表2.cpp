
#include <iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(nullptr) {}
};


class Solution{
    public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                ListNode* meetNode = fast;
                ListNode* starNode = head;
                while(meetNode != starNode){
                    meetNode = meetNode->next;
                    starNode = starNode->next;
                }
                return starNode;
            }
        }
        return nullptr;
    }
};

int main() {
    Solution s;
    cout << "hello world" << endl;
    return 0;
}