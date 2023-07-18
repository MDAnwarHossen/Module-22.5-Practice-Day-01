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
void findTargetHelper(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
    {
        return;
    }
    findTargetHelper(root->left, v);
    v.push_back(root->val);
    findTargetHelper(root->right, v);
}
bool findTarget(TreeNode *root, int k)
{
    vector<int> v;
    findTargetHelper(root, v);
    int start = 0;
    int end = v.size() - 1;
    int sum = 0;
    while (start < end)
    {
        sum = v[start] + v[end];
        if (sum == k)
        {
            return true;
        }
        else if (sum > k)
        {
            end--;
        }
        else
        {
            start++;
        }
    }
    return false;
}

int main()
{
    TreeNode *root = make_binary_search_tree();
    cout << findTarget(root, 28);

    return 0;
}