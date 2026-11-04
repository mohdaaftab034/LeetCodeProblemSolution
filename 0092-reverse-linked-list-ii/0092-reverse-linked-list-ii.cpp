class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        // Dummy node to handle edge cases where 'left' is 1 (head changes)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // 1. Move 'prev' to the node right before the 'left' position
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        // 2. 'curr' points to the first node of the sub-list to be reversed
        ListNode* curr = prev->next;

        // 3. Iteratively reverse the sub-list from 'left' to 'right'
        for (int i = 0; i < right - left; ++i) {
            ListNode* nextTemp = curr->next;
            curr->next = nextTemp->next;
            nextTemp->next = prev->next;
            prev->next = nextTemp;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};