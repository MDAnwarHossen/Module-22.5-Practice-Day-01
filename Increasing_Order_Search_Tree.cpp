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
void remake_binary_search_tree(TreeNode *&root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return;
    }
    if (val < root->val)
    {
        remake_binary_search_tree(root->left, val);
    }
    else
    {
        remake_binary_search_tree(root->right, val);
    }
}
vector<int> make_array(TreeNode *root, vector<int> &v)
{
    if (root == NULL)
    {
        return v;
    }
    v.push_back(root->val);
    make_array(root->left, v);
    make_array(root->right, v);
    return v;
}
TreeNode *increasingBST(TreeNode *root)
{
    vector<int> v;
    vector<int> arry = make_array(root, v);
    sort(v.begin(), v.end());
    TreeNode *newRoot = NULL;
    for (int num : v)
    {
        remake_binary_search_tree(newRoot, num);
    }
    return newRoot;
}

int main()
{
    TreeNode *root = make_binary_search_tree();
    TreeNode *result = increasingBST(root);
    print_tree(result);

    return 0;
}