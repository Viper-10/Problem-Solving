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
  priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq;

public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    ListNode *output = new ListNode(0);

    ListNode *temp = output;

    for (ListNode *list : lists)
    {
      if (list)
      {
        pq.push(make_pair(list->val, list));
      }
    }

    while (!pq.empty())
    {
      temp->next = pq.top().second;
      pq.pop();

      temp = temp->next;
      if (temp->next)
        pq.push(make_pair(temp->next->val, temp->next));
    }

    return output->next;
  }
};