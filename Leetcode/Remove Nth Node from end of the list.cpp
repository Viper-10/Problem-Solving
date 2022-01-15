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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *saveHead = head;
    ListNode *temp = head;

    while (n--)
    {
      temp = temp->next;
    }

    if (temp == NULL)
    {
      ListNode *freept = saveHead;
      saveHead = saveHead->next;
      freept->next = NULL;
      delete freept;

      return saveHead;
    }

    while (temp->next)
    {
      temp = temp->next;
      head = head->next;
    }

    ListNode *freept = head->next;
    head->next = head->next->next;

    freept->next = NULL;
    delete freept;

    return saveHead;
  }
};