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
class Solution 
{
public:
    void reorderList(ListNode* head) 
    {
        if(head == NULL || head->next == NULL)
        {
            return;
        }
        ListNode* first = head;
        ListNode* second = head->next;

        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr->next)
        {
            prev = curr;
            curr = curr->next;
        }
        if(first == prev && curr == second)
        {
            return;
        }
        first->next = curr;
        prev->next = NULL;
        curr->next = second;
        reorderList(second);
    }
};