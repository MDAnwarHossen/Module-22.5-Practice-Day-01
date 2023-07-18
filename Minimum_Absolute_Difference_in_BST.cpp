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

int getMinimumDifference(TreeNode *root)
{
    if (root == NULL)
    {
        return INT_MAX;
    }

    int minDiff = INT_MAX;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *p = q.front();
        q.pop();

        if (p->left)
        {
            q.push(p->left);
            TreeNode *maxNode = p->left;
            while (maxNode->right)
            {
                maxNode = maxNode->right;
            }
            minDiff = min(minDiff, p->val - maxNode->val);
        }

        if (p->right)
        {
            q.push(p->right);
            TreeNode *minNode = p->right;
            while (minNode->left)
            {
                minNode = minNode->left;
            }
            minDiff = min(minDiff, minNode->val - p->val);
        }
    }

    return minDiff;
}

int main()
{
    TreeNode *root = make_binary_search_tree();
    cout << getMinimumDifference(root);

    return 0;
}