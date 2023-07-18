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
TreeNode *sortedArrayToBSTHelper(vector<int> nums, int L, int R)
{
    if (L > R)
    {
        return NULL;
    }

    int mid = (L + R) / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    TreeNode *leftRoot = sortedArrayToBSTHelper(nums, L, mid - 1);
    TreeNode *rightRoot = sortedArrayToBSTHelper(nums, mid + 1, R);
    root->left = leftRoot;
    root->right = rightRoot;
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{

    int n = nums.size();
    return sortedArrayToBSTHelper(nums, 0, n - 1);
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
int main()
{

    vector<int> nums;
    int X;
    while (cin >> X)
    {
        nums.push_back(X);
    }

    TreeNode *root = sortedArrayToBST(nums);
    print_tree(root);

    return 0;
}