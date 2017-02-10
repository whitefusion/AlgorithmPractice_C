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
        ListNode *dummy = new ListNode(0);
        ListNode *p1 = head, *p2 = dummy;
        p2->next = p1;

        while(p1)
        {
            while(p1->next && p1->val == p1->next->val)
                p1 = p1->next;
            if(p2->next != p1)
            {
                p2->next = p1->next;
                p1 = p2->next;
            }
            else
            {
                p2 = p2->next;
                p1 = p1->next;
            }
        }
        return dummy->next;

    }
};

int main() {
    //ListNode *n1 = new ListNode(1);
    //ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n31 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n41 = new ListNode(4);
    //ListNode *n5 = new ListNode(5);
    //n1->next = n2;
    //n2->next = n3;
    n3->next = n31;
    n31->next = n4;
    n4->next = n41;
    //n41->next = n5;

    Solution mySolu;
    ListNode *temp = mySolu.deleteDuplicates(n3);
    while(temp)
    {
        std::cout << temp->val << std::endl;
        temp = temp ->next;
    }



    delete n3,n31,n4,n41;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}