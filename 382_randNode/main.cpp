#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
private:
    int len = 1;
    ListNode* myHead;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        myHead = head;
        ListNode* dummy = head;
        while(dummy->next != NULL) {
            len++;
            dummy = dummy->next;
        }
    }

    /** Returns a random node's value. */
    int getRandom() {
        ListNode *temp = myHead;
        int myRand = rand() % len;
        while(myRand--){
            temp = temp->next;
        }
        return temp->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution solution(head);
    int count = 12;
    while(count--) {
        std::cout << solution.getRandom() << std::endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}