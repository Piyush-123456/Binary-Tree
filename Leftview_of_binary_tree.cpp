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

void leftviewofbinarytree(Node *root, vector<int> &leftview, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == leftview.size())
    {
        leftview.push_back(root->data);
    }
    leftviewofbinarytree(root->left, leftview, level + 1);
    leftviewofbinarytree(root->right, leftview, level + 1);
}

int main()
{
    Node *root = createNode();
    vector<int> leftview;
    leftviewofbinarytree(root, leftview, 0);
    for (int i = 0; i < leftview.size(); i++)
    {
        cout << leftview[i] << " ";
    }
    return 0;
}
// INPUT: 
// 10 20 40 -1 -1 50 70 110 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 133 -1 -1
// OUTPUT : 
// 10 20 40 70 110
