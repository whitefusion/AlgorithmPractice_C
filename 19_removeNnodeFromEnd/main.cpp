#include <iostream>
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x),next(NULL){}
};
//Be cautious about the situation where the head is deleted
//And the case [1,2] 1; [1] 1 ; [1,2] 2

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        if(!head->next) return head->next;

        ListNode* slow = head;
        ListNode* fast = head;

        while(n--)
            fast = fast->next;

        if(fast == NULL) return head->next;

        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return head;

    }
};
int main() {
    return 0;
}