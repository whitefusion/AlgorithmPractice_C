#include <iostream>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x): val(x),next(NULL){}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !(head->next))
            return head;
        ListNode *res = head->next;
        head->next = swapPairs(res->next);
        res->next = head;
        return res;
    }

};

int main() {
    ListNode* n1 = new ListNode(0);
    ListNode* n2 = new ListNode(1);
    ListNode* n3 = new ListNode(2);
    ListNode* n4 = new ListNode(3);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    Solution mySolu;
    ListNode *result = mySolu.swapPairs(n1);
    while(result){
        cout << result->val << endl;
        result = result->next;
    }
    std::cout << "Hello, World!" << std::endl;

    delete n1,n2;
    return 0;
}