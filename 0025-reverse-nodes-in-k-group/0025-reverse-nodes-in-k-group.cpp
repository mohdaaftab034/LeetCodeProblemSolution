class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        // Dummy node acts as a prev pointer to the head of the current group
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroup = dummy;

        while (true) {
            // Check if there are at least k nodes left to reverse
            ListNode* kthNode = getKthNode(prevGroup, k);
            if (!kthNode) break; // Less than k nodes remain, done

            ListNode* nextGroup = kthNode->next;
            ListNode* curr = prevGroup->next;
            ListNode* prev = nextGroup; // Points to start of remaining list

            // Standard iterative linked list reversal for k nodes
            while (curr != nextGroup) {
                ListNode* nextTemp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = nextTemp;
            }

            // Connect the previously processed group to the newly reversed group
            ListNode* tmp = prevGroup->next;
            prevGroup->next = kthNode;
            prevGroup = tmp;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }

private:
    ListNode* getKthNode(ListNode* curr, int k) {
        while (curr && k > 0) {
            curr = curr->next;
            k--;
        }
        return curr;
    }
};