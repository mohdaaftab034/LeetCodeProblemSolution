LeetCode Link - "https://leetcode.com/problems/remove-nth-node-from-end-of-list/description"


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode *temp = head;
        // count the number of nodes present in the Linked List
        while(temp != NULL)
        {
            count++;
            temp = temp->next;
        }

        count -= n;
        // If node are present in the list only one
        if(count == 0)
        {
           temp = head;
           head = head->next;
           delete temp;

           return head; 
        }
        // Achieve the (n-count) node from the start of the list
        ListNode *curr = head, *prev = NULL;
        while(count--)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        delete curr;

        return head;
    }
};
