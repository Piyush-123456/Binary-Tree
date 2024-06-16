#include <iostream>
#include <queue>
#include <map>
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

void BottomView(Node *root)
{
    map<int, int> hdtoNodemap;
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();
        Node *frontnode = temp.first;
        int hd = temp.second;

        hdtoNodemap[hd] = frontnode->data;
        if (frontnode->left != NULL)
        {
            q.push(make_pair(frontnode->left, hd - 1));
        }
        if (frontnode->right != NULL)
        {
            q.push(make_pair(frontnode->right, hd + 1));
        }
    }

    cout << "Printing the Top View : " << endl;
    for (auto i : hdtoNodemap)
    {
        cout << i.second << " ";
    }
}

int main()
{
    Node *root = createNode();
    BottomView(root);
}
//INPUT : 
// 10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1

// OUTPUT : 
// 110 70 111 80 112 90 113
