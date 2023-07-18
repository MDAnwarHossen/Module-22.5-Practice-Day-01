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
int rangeSumBST(TreeNode *root, int low, int high)
{
    if (root == NULL)
    {
        return 0;
    }
    int L = 0;
    int R = 0;
    if (root->val > low)
    {
        L = rangeSumBST(root->left, low, high);
    }
    if (root->val < high)
    {

        R = rangeSumBST(root->right, low, high);
    }
    return L + R + (root->val >= low && root->val <= high ? root->val : 0);
}
int main()
{
    TreeNode *root = make_binary_search_tree();
    cout << rangeSumBST(root, 7, 15);
    // print_tree(root);

    return 0;
}