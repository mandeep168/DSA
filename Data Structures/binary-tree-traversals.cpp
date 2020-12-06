#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node* left, *right;
  Node(int data){
    this->data = data;
    left = right = NULL;
  }
};

void postorder_traversal(struct Node* node){
  if(node == NULL) return;
  postorder_traversal(node->left);
  postorder_traversal(node->right);
  cout<<node->data<<" ";
}

void preorder_traversal(struct Node* node){
  if(node == NULL) return;
  cout<<node->data<<" ";
  preorder_traversal(node->left);
  preorder_traversal(node->right);
}

void inorder_traversal(struct Node* node){
  if(node == NULL)return;
  inorder_traversal(node->left);
  cout<<node->data<<" ";
  inorder_traversal(node->right);
}

void levelorder_traversal(struct Node* root){
  if(root == NULL) return;
  queue<struct Node* > q;
  q.push(root);
  while(!q.empty()){
    struct Node* node = q.front();
    cout<<node->data<<" ";
    q.pop();
    if(node->left != NULL) q.push(node->left);
    if(node->right != NULL) q.push(node->right);
  }
}

int main(){
  //tree - non-linear Data Structure
  /*height  = level of tree
  level started from 0 from root
  Properties of binary trees:
  1.The maximum number of nodes at level l is 2^(l) - 1. (level of root is 1).
  2.The maximum number of nodes at height h is 2^(h) - 1.
  3.given n nodes, minimum level/height = log2(n+1).
  4.given n leaves minimum level / height is log2(n) + 1.
  5.In a Binary tree where every node has 0 or 2 children, number of leaf nodes is always one more than nodes with two children.

Full binary trees:
  if every node has 0 or 2 childs.
  In a Full Binary, number of leaf nodes is number of internal nodes plus 1.
  We can also say a full binary tree is a binary tree in which all nodes except leaves have two children.

Complete binary trees:
  A Binary Tree is complete Binary Tree if all levels are completely filled except possibly the last level and the last level has all keys as left as possible

Perfect binary trees:
   A Binary tree is Perfect Binary Tree in which all internal nodes have two children and all leaves are at the same level.
   has 2^h - 1 nodes, where h is the height of the perfect binary tree.

Traversal:
Inorder (Left, Root, Right)
Preorder (Root, Left, Right)
Postorder (Left, Right, Root).

  */

  struct Node *root = new Node(1);
  root->left = new Node(2);
  root->right = new Node(3);
  root->left->left = new Node(4);
  root->left->right = new Node(5);

  cout<<"Pre order Traversal: ";preorder_traversal(root);cout<<"\n";
  cout<<"In order Traversal: ";inorder_traversal(root);cout<<"\n";
  cout<<"Post order Traversal: ";postorder_traversal(root);cout<<"\n";
  cout<<"Level order Traversal: ";levelorder_traversal(root);cout<<"\n";

  return 0;
}
