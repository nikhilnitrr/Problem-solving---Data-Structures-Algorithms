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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
        vector<vector<int>>result(m, vector<int>(n, -1));
        if(head == NULL)
        {
            return result;
        }

        ListNode* curr = head;
        int row_start = 0;
        int row_end = m-1;
        int col_start = 0;
        int col_end = n-1;

        int i = row_start;
        int j = col_start;

        while(row_start <= row_end && col_start <= col_end && curr!=NULL)
        {
            while(curr!=NULL && j <= col_end)
            {
                result[i][j] = curr->val;
                curr=curr->next;
                j++;
            }

            row_start++;
            i = row_start;
            j = col_end;

            while(curr!=NULL && i <= row_end)
            {
                result[i][j] = curr->val;
                curr = curr->next;
                i++;
            }

            col_end--;
            i = row_end;
            j = col_end;

            while(curr!=NULL && j>=col_start)
            {
                result[i][j] = curr->val;
                curr = curr->next;
                j--;
            }

            row_end--;
            i = row_end;
            j = col_start;

            while(curr!=NULL && i>=row_start)
            {
                result[i][j] = curr->val;
                curr = curr->next;
                i--;
            }

            col_start++;
            i = row_start;
            j = col_start;
        }
        return result;
    }
};  