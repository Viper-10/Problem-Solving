#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;
  Node(int d)
  {
    data = d;
    left = NULL;
    right = NULL;
  }
};

class Solution
{
public:
  Node *insert(Node *root, int data)
  {
    if (root == NULL)
    {
      return new Node(data);
    }
    else
    {
      Node *cur;
      if (data <= root->data)
      {
        cur = insert(root->left, data);
        root->left = cur;
      }
      else
      {
        cur = insert(root->right, data);
        root->right = cur;
      }

      return root;
    }
  }

  void topView(Node *root)
  {
    if (root == NULL)
      return;

    map<int, int> level;

    queue<pair<Node *, int>> q;
    level.insert(make_pair(0, root->data));

    q.push(make_pair(root, 0));

    while (!q.empty())
    {
      pair<Node *, int> top = q.front();

      Node *node = top.first;
      int k = top.second;
      q.pop();

      if (node->left)
      {
        map<int, int>::iterator it = level.find(k - 1);

        if (it == level.end())
        {
          level.insert(make_pair(k - 1, node->left->data));
        }

        q.push(make_pair(node->left, k - 1));
      }

      if (node->right)
      {
        map<int, int>::iterator it = level.find(k + 1);

        if (it == level.end())
        {
          level.insert(make_pair(k + 1, node->right->data));
        }

        q.push(make_pair(node->right, k + 1));
      }
    }

    for (map<int, int>::iterator it = level.begin(); it != level.end(); ++it)
    {
      cout << it->second << " ";
    }

    cout << endl;
  }

}; // End of Solution

int main()
{

  Solution myTree;
  Node *root = NULL;

  int t;
  int data;

  std::cin >> t;

  while (t-- > 0)
  {
    std::cin >> data;
    root = myTree.insert(root, data);
  }

  myTree.topView(root);

  return 0;
}
