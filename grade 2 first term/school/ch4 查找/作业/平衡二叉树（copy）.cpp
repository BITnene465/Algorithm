#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
    int height; // 新增高度属性，用于处理平衡因子
};

Node *createNode(char data)
{
    Node *newNode = new Node();
    if (newNode)
    {
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        newNode->height = 1; // 新节点的高度为1
    }
    return newNode;
}

int getHeight(Node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}

int getBalance(Node *root)
{
    if (root == NULL)
        return 0;
    return getHeight(root->left) - getHeight(root->right);
}

Node *leftRotate(Node *root)
{
    Node *newRoot = root->right;
    root->right = newRoot->left;
    newRoot->left = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
    return newRoot;
}

Node *rightRotate(Node *root)
{
    Node *newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;
    root->height = max(getHeight(root->left), getHeight(root->right)) + 1;
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right)) + 1;
    return newRoot;
}

Node *insertNode(Node *root, char data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insertNode(root->right, data);
    }
    else
    {
        return root;
    }

    root->height = 1 + max(getHeight(root->left), getHeight(root->right));
    int balance = getBalance(root);

    if (balance > 1)
    {
        if ((root->left != NULL) && (getBalance(root->left) >= 0))
        {
            return rightRotate(root);
        }
        else
        {
            root->left = leftRotate(root->left);
            return rightRotate(root);
        }
    }

    if (balance < -1)
    {
        if ((root->right != NULL) && (getBalance(root->right) <= 0))
        {
            return leftRotate(root);
        }
        else
        {
            root->right = rightRotate(root->right);
            return leftRotate(root);
        }
    }

    return root;
}

void preorder(Node *root)
{
    if (root)
    {
        cout << root->data;
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data;
        inorder(root->right);
    }
}

void postorder(Node *root)
{
    if (root)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->data;
    }
}

void displayTree(Node *root, int space)
{
    if (root == NULL)
    {
        return;
    }
    space += 4;
    displayTree(root->right, space);
    for (int i = 4; i < space; i++)
    {
        cout << " ";
    }
    cout << root->data << endl;
    displayTree(root->left, space);
}

int main()
{
    string input;
    cin >> input;

    Node *root = NULL;
    for (char ch : input)
    {
        root = insertNode(root, ch);
    }

    cout << "Preorder: ";
    preorder(root);
    cout << endl;

    cout << "Inorder: ";
    inorder(root);
    cout << endl;

    cout << "Postorder: ";
    postorder(root);
    cout << endl;

    cout << "Tree:" << endl;
    displayTree(root, 0);

    return 0;
}