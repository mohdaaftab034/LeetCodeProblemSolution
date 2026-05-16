// LeetCode - https://leetcode.com/problems/merge-k-sorted-lists/description/?utm=codolio



// ----------------------Solution - Brute force --------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int> arr;

        // Brute force ---> Store all the elements in an arr from the every
        // lists
        for (int i = 0; i < lists.size(); i++) {
            ListNode* temp = lists[i];
            while (temp != nullptr) {
                arr.push_back(temp->val);
                temp = temp->next;
            }
        }

        // Sort the arr in increasing order
        sort(arr.begin(), arr.end());

        // convert the array into list
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        for (int i = 0; i < arr.size(); i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return dummy->next;
    }
};

// --------------------Solution - Average case------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* mergeTwoLists(ListNode* head, ListNode* temp) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while (head != NULL && temp != NULL) {

            if(head -> val <= temp -> val) {
                curr-> next = head;
                head = head -> next;
            } else {
                curr->next = temp;
                temp = temp -> next;
            }

            curr = curr->next;
        }

        if(head != NULL) {
            curr->next = head;
        }

        if(temp != NULL) {
            curr->next = temp;
        }

        return dummy->next;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) {
            return NULL;
        }

        ListNode* head = lists[0];

        for (int i = 1; i < lists.size(); i++) {
            head = mergeTwoLists(head, lists[i]);
        }
        return head;
    }
};


// ---------------------Solution -> Optimal ---> Min-Heap -------------------------
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>>pq;

        for (int i = 0; i < lists.size(); i++) {
            if(lists[i]) {
                pq.push({lists[i]->val, lists[i]});
            }
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            if(it.second -> next) {
                pq.push({it.second->next->val, it.second->next});
            }

            temp->next = it.second;
            temp = temp->next;
        }

        return dummy->next;
    }
};
