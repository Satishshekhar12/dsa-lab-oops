/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include<iostream> 
using namespace std;

class Node {
    int data ,height ;
    Node * left, *right ;
    
    Node(int val){
        data = val ;
        left = right = NULL;
        height =1;
    }
}

Node * left_rotation(Node * root){
    Node *child = root->root->right;
    Node * child_left = child->left;
    
    child->left= root;
    root->right = child_left;
     //now height calculation first roots than child
    root->height= 1+(get_height(root->left),get_height(root->right));
    child->height= 1+(get_height(child->left),get_height(child->right));
    
    return child;
}

Node * right_rotation(Node *root){
    Node * child = root->left ;
    child_right = child->right;
    
    child->right =root;
    root->left = child;
    
    //now height calculation first roots than child
    root->height= 1+(get_height(root->left),get_height(root->right));
    child->height= 1+(get_height(child->left),get_height(child->right));
    
    return child;
}

int get_height(TreeNode *root){
    if(root==NULL) return 0;
    return root->height;
}

int get_balance(Node *root){
    return get_height(root->left) - get_height(root->right);
}
Node * insert(Node *root ,int val){
    if(root==NULL) return new Node(val);
    
    if(val < root->data ){
        root =insert(root->left,val);
    }
    else (val > root -> data) {
        root =insert (root->right ,val)
    }
    else return root;
    
    root->height= 1+max(get_height(root->left),get_height(root->right)) ;
    
    int balance= get_balance(root);
    //if balance < -1 than due to right unbalanced
    //if balance > 1 than due to left unbalanced
    /*
    balance if < -1 than due to Right
        root->right->data > val than RL
        root->right->data < val than RR

    if > 1 than left
        if root->left->data > val  than LL
        if root->left->data < val han LR

    */
    //LL
    if(balance >1 && root->left->data > val ){
        return right_rotation(root);
    }
    //RR
    else if( balance <-1 && root->right->data < val){
        return left_rotation(root);
    }
    
    //LR
    else if( balance >1 && root->left->data < val){
        root->left = left_rotation(root->left);
        right_rotation (root);
    }
    //RL
    else if(balance < -1 && root->right->data > val){
        root->right=right_rotation(root->right);
        left_rotation(root);
    }
    //not required to balance
    else {
        return root;
    }
}

void inorder (Node *root){
    if(root==NULL) return NULL;
    inorder(root->left);
    cout<<root->data<<", ";
    inorder(root->right);
}

int main(){
    Node *root =NULL;
    root= insert (root ,10);
    root= insert (root ,20);
    root= insert (root ,5);
    root= insert (root ,100);
    root= insert (root ,2);
    root= insert (root ,12);
    root= insert (root ,6);
    root= insert (root ,9);
    
    inorder(root);
}
