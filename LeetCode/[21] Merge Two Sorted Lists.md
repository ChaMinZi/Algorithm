# [21. Merge Two Sorted Lists]()

* C++

```C++
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head, *newCur;
        ListNode *p_l1, *p_l2;
        
        p_l1 = l1;
        p_l2 = l2;
        head = newCur = nullptr;
        
        while (p_l1 != nullptr && p_l2 != nullptr) {
            ListNode* newNode = new ListNode(0);

            if (p_l1->val > p_l2->val) {
                newNode->val = p_l2->val;
                p_l2 = p_l2->next;
            }
            else {
                newNode->val = p_l1->val;
                p_l1 = p_l1->next;
            }
            
            if (head == nullptr) {
                head = newNode;
                newCur = head;
            }
            else {
                newCur->next = newNode;
                newCur = newNode;
            }
        }
        
        while(p_l1 != nullptr) {
            ListNode* newNode = new ListNode(0);
            newNode->val = p_l1->val;
            p_l1 = p_l1->next;
            
            if (head == nullptr) {
                head = newNode;
                newCur = head;
            }
            else {
                newCur->next = newNode;
                newCur = newNode;
            }
        }
        
        while(p_l2 != nullptr) {
            ListNode* newNode = new ListNode(0);
            newNode->val = p_l2->val;
            p_l2 = p_l2->next;
            
            if (head == nullptr) {
                head = newNode;
                newCur = head;
            }
            else {
                newCur->next = newNode;
                newCur = newNode;
            }
        }
        return head;
    }
};
```
