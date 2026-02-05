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
    ListNode* insertionSortList(ListNode* head) {
        if(!head||!head->next)return head;
        ListNode* sorted=new ListNode(0);
        ListNode* temp=head;
         while(temp){
            ListNode* prev = sorted;
            while(prev->next && prev->next->val < temp->val)
                prev = prev->next;
            ListNode* next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
            temp = next;
        }
        return sorted->next;
    }
};