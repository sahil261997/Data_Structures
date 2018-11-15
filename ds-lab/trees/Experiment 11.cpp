/*
Write a menu driven program that implements the following operations on a
Binary search tree :
•	Insert a new element
•	Delete an existing element
•	Traversing the tree
o	Pre-order Traversal
o	In-order Traversal
o	Post-order Traversal

*/

#include <iostream>

using namespace std;

struct node{
    node *left;
    node *right;
    int data;
};

struct node *create(int val){
    struct node *n = new struct node;
    n->data = val;
    n->left = NULL;
    n->right = NULL;
    return n;
};

struct node *insert(struct node *node, int val){
    if(node==NULL)
        return create(val);

    if(val < node->data)
        node->left = insert(node->left,val);
    else
        node->right = insert(node->right,val);
};

struct node *mini(struct node *node)
{
    struct node *curr = node;
    while(curr->left != NULL)
        curr = curr->left;

    return curr;
};

struct node *del(struct node *node ,int data){
    if(node == NULL)
        return node;

    if(data < node->data)
        node->left = del(node->left,data);
    else if(data > node->data)
        node->right = del(node->right,data);
    else{
        if(node->left == NULL)
        {
            struct node *temp = node->right;
            delete(node);
            return temp;
        }
        else if(node->right == NULL)
        {
            struct node *temp = node->left;
            delete(node);
            return temp;
        }

        struct node *temp = mini(node->right);
        node->data = temp->data;
        node->right = del(node->right,temp->data);
    }

    return node;
};

void Postorder(struct node* node)
{
    if (node == NULL)
        return;

    Postorder(node->left);

    Postorder(node->right);

    cout << node->data << " ";
}

void Inorder(struct node* node)
{
    if (node == NULL)
        return;

    Inorder(node->left);

    cout << node->data << " ";

    Inorder(node->right);
}

void Preorder(struct node* node)
{
    if (node == NULL)
        return;

    cout << node->data << " ";

    Preorder(node->left);

    Preorder(node->right);
}
int main()
{
    int n,el;
    struct node *root =NULL;
    cout<<"enter tree size";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        root = insert(root,x);
    }

    cout<<"Enter element to be delete:";
    cin>>el;
    del(root,el);

    cout << "\nPreorder traversal of binary tree is \n";
    Preorder(root);

    cout << "\nInorder traversal of binary tree is \n";
    Inorder(root);

    cout << "\nPostorder traversal of binary tree is \n";
    Postorder(root);
}
