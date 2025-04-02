// #creation
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;
    int height;
    // constructor to create node
    Node(int val)
    {
        data = val;
        height = 1;
        left = right = NULL;
        ;
    }
};

int get_height(Node *root)
{
    if (root == NULL)
        return 0;
    return root->height;
}
// to get balance if -ve than due to Right if +vee than left
int get_balance(Node *root)
{
    return get_height(root->left) - get_height(root->right);
}

Node *right_rotation(Node *root)
{
    // return type node so that it get attached
    Node *child = root->left;
    Node *child_right = child->right;

    child->right = root;
    root->left = child_right;

    // height changed in these 2 since root goes down first calculate root height than childs(new root but not updated till now)
    root->height = 1 + max(get_height(root->left), get_height(root->right));
    child->height = 1 + max(get_height(child->left), get_height(child->right));

    return child;
}

Node *left_rotation(Node *root)
{
    Node *child = root->right;
    Node *child_left = child->left;

    child->left = root;
    root->right = child_left;

    root->height = 1 + max(get_height(root->left), get_height(root->right));
    child->height = 1 + max(get_height(child->left), get_height(child->right));
    return child;
}

Node *insert(Node *root, int val)
{
    // dowsn't exist
    if (root == NULL)
        return new Node(val);
    // exist
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    { // value greater than current node
        root->right = insert(root->right, val);
    }
    else
    {
        return root;
    }
    // after inserting update height for each node in that tree where we traversed
    // now get/assgin height
    root->height = 1 + max(get_height(root->left), get_height(root->right));

    // now check balance using function
    int balance = get_balance(root);

    // if abs(balance) >1 than unbalanced
    /*
    balance if < -1 than due to Right
        root->right->data > val than RL
        root->right->data < val than RR

    if > 1 than left
        if root->left->data > val  than LL
        if root->left->data < val han LR

    */

    // LL   -> right Rotation (top)
    if (balance > 1 && root->left->data > val)
    {
        return right_rotation(root);
    }

    // RR  -> left rotation (top)
    else if (balance < -1 && root->right->data < val)
    {
        return left_rotation(root);
    }

    // LR -> left Rot (middle) ,right rotation(top)
    else if (balance > 1 && root->left->data < val)
    {
        root->left = left_rotation(root->left);
        return right_rotation(root);
    }

    // RL  -> Right Rot (middle) , left rotate(top)
    else if (balance < -1 && root->right->data > val)
    {
        root->right = right_rotation(root->right);
        return left_rotation(root);
    }
    // no unbalancing
    else
        return root;
}

void inorder(Node *root){
    if(root==NULL) return ;
    inorder(root->left);
    cout<<root->data<<", ";
    inorder(root->right);
}
int main()
{
    Node *root = NULL;
    // duplicate element are not allowed
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 50);
    root = insert(root, 70);
    root = insert(root, 5);
    root = insert(root, 100);
    root = insert(root, 95);
    inorder(root);
}
