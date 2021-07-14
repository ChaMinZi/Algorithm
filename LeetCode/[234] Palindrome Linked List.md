# [234. Palindrome Linked List](https://leetcode.com/problems/palindrome-linked-list/)

* C++

```c++
class Solution {
public:
    int getSize(ListNode* head) {
        int ret = 0;
        ListNode* temp = head;
        while (temp != NULL) {
            ++ret;
            temp = temp->next;
        }

        return ret;
    }

    bool isPalindrome(ListNode* head) {
        int sz;
        stack<int> st;

        sz = getSize(head);

        if (sz % 2 != 0) {
            // 홀수
            for (int i = 0; i < (sz / 2); i++) {
                st.push(head->val);
                head = head->next;
            }
            head = head->next;
            for (int i = ((sz / 2) + 1); i < sz; i++) {
                if (st.top() != head->val)
                    return false;
                st.pop();
                head = head->next;
            }
        }
        else {
            for (int i = 0; i < (sz / 2); i++) {
                st.push(head->val);
                head = head->next;
            }
            for (int i = (sz / 2); i < sz; i++) {
                if (st.top() != head->val)
                    return false;
                st.pop();
                head = head->next;
            }
        }

        return true;
    }
};
```
