#include <iostream>
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        ListNode* myHead = new ListNode(head->val);
        ListNode* tempHead = myHead;
        ListNode*p1 = head, *p2 = head->next;

        while(p2)
        {
            if(p2->val == p1->val)
            {
                p2 = p2->next;
            }
            else
            {
                ListNode *temp = new ListNode(p2->val);
                myHead->next = temp;
                myHead = myHead->next;
                p1 = p2;
                p2 = p2->next;
            }
        }
        return tempHead;

    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}