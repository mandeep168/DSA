#include<bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  struct Node* prev;
  struct Node* next;
};

//adds a node on the end
void append(struct Node** head_ref, int new_data){
  struct Node* new_node = *head_ref;
  if(new_node == NULL) {
    struct Node* node = new Node;
    *head_ref = node;
    node->data = new_data;
    node->next = NULL;
    node->prev = NULL;
    return;
  }

  while(new_node->next != NULL){
    new_node = new_node->next;
  }
  new_node->next = new Node;
  new_node->next->data = new_data;
  new_node->next->prev = new_node;
  new_node->next->next = NULL;
}

void traverse(struct Node* node){
  while(node->next!=NULL){
    cout<<node->data<<" -> ";
    node = node->next;
  }
  cout<<node->data;

  cout<<"\ntraversal in backward direction\n";
  while(node->prev!=NULL){
    cout<<node->data<<" <- ";
    node = node->prev;
  }
  cout<<node->data;
}

int main(){
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;

  head = new Node;
  third = new Node;
  second = new Node;

  head->data = 1;
  head->prev = NULL;
  head->next = second;


  second->data = 2;
  second->next = third;
  second->prev = head;


  third->data = 3;
  third->next = NULL;
  third->prev = second;

  //append 67
  append(&head, 67);

  //traverse DLL
  traverse(head);
}
