#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree()
{
    int val;
    cout << "Enter the value of Node : " << endl;
    cin >> val;
    if (val == -1)
    {
        return NULL;
    }
    Node *root = new Node(val);
    cout << "value of left Node : " << endl;
    root->left = createTree();
    cout << "Value of right Node : " << endl;
    root->right = createTree();
    return root;
}

void preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    inorder(root->right);
    cout << root->data << " ";
}

void levelorderTraversal(Node *root)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        Node *frontnode = q.front();
        q.pop();
        if (frontnode == NULL)
        {
            cout << endl;
            q.push(NULL);
        }
        else
        {
            cout << frontnode->data << " ";
            if (frontnode->left != NULL)
            {
                q.push(frontnode->left);
            }
            if (frontnode->right != NULL)
            {
                q.push(frontnode->right);
            }
        }
    }
}

int main()
{
    Node *root = createTree();
    levelorderTraversal(root);
    return 0;
}
