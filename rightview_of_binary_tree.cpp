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
    if (val == -1)
    {
        return NULL;
    }
    Node *root = new Node(val);
    root->left = createNode();
    root->right = createNode();
    return root;
}

void rightviewofbinarytree(Node *root, vector<int> &rightview, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == rightview.size())
    {
        rightview.push_back(root->data);
    }
    rightviewofbinarytree(root->right, rightview, level + 1);
    rightviewofbinarytree(root->left, rightview, level + 1);
}

int main()
{
    Node *root = createNode();
    vector<int> rightview;
    rightviewofbinarytree(root, rightview, 0);
    for (int i = 0; i < rightview.size(); i++)
    {
        cout << rightview[i] << " ";
    }
    return 0;
}
