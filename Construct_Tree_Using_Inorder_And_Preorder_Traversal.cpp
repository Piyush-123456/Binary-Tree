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

Node *createNode()
{
    int val;
    cout << "Enter the value of node : " << endl;
    cin >> val;
    Node *root = new Node(val);
    root->left = createNode();
    root->right = createNode();
    return root;
}

void Preorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

void Inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Postorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

void Level_Order_Traversal(Node *root)
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

int searchinorder(int inorder[], int size, int element)
{
    for (int i = 0; i < size; i++)
    {
        if (inorder[i] == element)
        {
            return i;
        }
    }
}

Node *constructTreeFromInorderAndPreorderTraversal(int preorder[], int inorder[], int &preIndex, int inorderstart, int inorderend, int size)
{
    if (preIndex >= size || inorderstart > inorderend)
    {
        return NULL;
    }

    int element = preorder[preIndex];
    preIndex++;
    Node *root = new Node(element);

    int position = searchinorder(inorder, size, element);

    root->left = constructTreeFromInorderAndPreorderTraversal(preorder, inorder, preIndex, inorderstart, position - 1, size);
    root->right = constructTreeFromInorderAndPreorderTraversal(preorder, inorder, preIndex, position + 1, inorderend, size);

    return root;
}
int main()
{
    // Node *root = createNode();
    int inorder[] = {10, 8, 6, 2, 4, 12};
    int preorder[] = {2, 8, 10, 6, 4, 12};
    int size = 6;
    int preIndex = 0;
    int inorderstart = 0;
    int inorderend = 5;

    Node *newnode = constructTreeFromInorderAndPreorderTraversal(preorder, inorder, preIndex, inorderstart, inorderend, size);
    Level_Order_Traversal(newnode);
    return 0;
}
