class Solution {
public:
    ListNode* sortList(ListNode* head) {
        // Base case: if list is empty or has only one node, it's already sorted
        if (!head || !head->next) return head;

        // Step 1. Split the list into two halves using the slow and fast pointer technique
        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr; // Break the list into two parts

        // Step 2. Recursively sort both halves
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);

        // Step 3. Merge the sorted halves
        return merge(left, right);
    }

private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        // Attach the remaining elements, if any
        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }
};