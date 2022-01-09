node *createNode(int val)
{
  node *temp = (node *)malloc(sizeof(node));
  temp->left = NULL;
  temp->right = NULL;
  temp->val = val;
  temp->ht = 0;

  return temp;
}
int findHeight(node *root)
{
  return (root == NULL) ? -1 : root->ht;
}
int findBalanceFactor(node *root)
{
  int lh = findHeight(root->left);
  int rh = findHeight(root->right);

  return lh - rh;
}
void setHeight(node *root)
{
  int lh = findHeight(root->left);
  int rh = findHeight(root->right);

  root->ht = max(lh, rh) + 1;
}
node *leftRotate(node *root)
{
  node *newRoot = root->right;
  root->right = newRoot->left;
  newRoot->left = root;

  setHeight(root);
  setHeight(newRoot);
  return newRoot;
}
node *rightRotate(node *root)
{
  node *newRoot = root->left;
  root->left = newRoot->right;
  newRoot->right = root;

  setHeight(root);
  setHeight(newRoot);

  return newRoot;
}
node *insert(node *root, int val)
{
  if (root == NULL)
  {
    return createNode(val);
  }

  if (val <= root->val)
  {
    root->left = insert(root->left, val);
  }

  else
  {
    root->right = insert(root->right, val);
  }

  int balanceFactor = findBalanceFactor(root);

  if (balanceFactor > 1)
  {
    if (findHeight(root->left->left) > findHeight(root->left->right))
    {
      root = rightRotate(root);
    }

    else
    {
      root->left = leftRotate(root->left);
      root = rightRotate(root);
    }
  }

  else if (balanceFactor < -1)
  {
    if (findHeight(root->right->right) > findHeight(root->right->left))
    {
      root = leftRotate(root);
    }

    else
    {
      root->right = rightRotate(root->right);
      root = leftRotate(root);
    }
  }

  else
    setHeight(root);

  return root;
}