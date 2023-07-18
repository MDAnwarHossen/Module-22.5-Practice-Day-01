#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
TreeNode *make_binary_search_tree()
{
    int val;
    cin >> val;
    TreeNode *root = new TreeNode(val);
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *p = q.front();
        q.pop();

        int L, R;
        if (!(cin >> L >> R))
        {
            break; // Break out of the loop if input fails
        }
        TreeNode *newLeft, *newRight;
        L == -1 ? newLeft = NULL : newLeft = new TreeNode(L);
        R == -1 ? newRight = NULL : newRight = new TreeNode(R);
        p->left = newLeft;
        p->right = newRight;

        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }
    return root;
}

void print_tree(TreeNode *root)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *p = q.front();
        q.pop();
        cout << p->val << " ";

        if (p->left)
        {
            q.push(p->left);
        }
        if (p->right)
        {
            q.push(p->right);
        }
    }
}
TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == val)
    {
        return root;
    }

    if (root->val > val)
    {
        searchBST(root->left, val);
    }
    else
    {
        searchBST(root->right, val);
    }
}

int main()
{
    TreeNode *root = make_binary_search_tree();
    TreeNode *result = searchBST(root, 5);
    if (result != NULL)
    {
        print_tree(result);
    }

    return 0;
}