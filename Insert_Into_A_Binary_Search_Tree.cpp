#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *make_tree()
{
    int val;
    cin >> val;

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();
        int L, R;
        cin >> L >> R;
        Node *newLeft, *newRight;
        L == -1 ? newLeft = NULL : newLeft = new Node(L);
        R == -1 ? newRight = NULL : newRight = new Node(R);
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
void insert_X(Node *root, int val)
{
    // cout<<root.val;
    queue<Node *> q;
    if (root)
    {
        q.push(root);
    }
    else
    {
        root = new Node(val);
    }

    while (!q.empty())
    {
        // part_1
        Node *p = q.front();
        q.pop();
        // part_2

        if (p->left && val < p->val)
        {
            q.push(p->left);
        }
        else if (p->right && val > p->val)
        {
            q.push(p->right);
        }
        else if (p->left == NULL && val < p->val)
        {
            p->left = new Node(val);
        }
        else if (p->right == NULL && val > p->val)
        {
            p->right = new Node(val);
        }
    }
}
void print(Node *root)
{

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        // part_1
        Node *p = q.front();
        q.pop();
        // part_2
        cout << p->val << " ";

        // part_3
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
    Node *root = make_tree();
    int X;
    cin >> X;
    insert_X(root, X);
    insert_X(root, 32);
    insert_X(root, 27);
    insert_X(root, 22);
    print(root);

    return 0;
}