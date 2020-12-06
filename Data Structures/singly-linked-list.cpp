#include<iostream>
using namespace std;

struct Node{
  int data;
  struct Node* next;
};


void push_at_front(struct Node** head_ref, int new_data){
  //allocate node;
  struct Node* new_node = new Node;

  new_node->data = new_data;
  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

void insert_after(struct Node* prev_node, int new_data){
  if(prev_node == NULL) return ;
  struct Node* new_node = new Node;
  new_node->data = new_data;
  new_node->next = prev_node->next;
  prev_node->next = new_node;
}

void append(struct Node** head_ref, int new_data){
  //allocate
  struct Node* new_node = new Node;

  //last node
  struct Node* last = *head_ref;

  new_node->data = new_data;
  new_node->next = NULL;
  if(last == NULL){
    *head_ref = new_node;
    return;
  }
  while(last->next != NULL){
    last = last->next;
  }
  last->next = new_node;
}

//deletion
void delete_first_occurence(struct Node** head_ref, int key){
  struct Node* temp = *head_ref, *prev;
  if(temp!=NULL && temp->data == key){
    *head_ref = temp->next;
    free(temp);
    return;
  }

  while(temp != NULL && temp->data != key){
    prev = temp;
    temp = temp->next;
  }
  if(temp == NULL) return;
  prev->next = temp->next;
  free(temp);
}

void delete_at_given_position(struct Node** head_ref, int position){
  if(*head_ref == NULL) return;

  struct Node* temp = *head_ref;
  if(position == 0){
    *head_ref = temp->next;
    free(temp);
    return;
  }
  for(int i = 0;temp!=NULL && i<position - 1;i++) temp = temp->next;
  if(temp == NULL || temp->next == NULL) return ;
  struct Node* next = temp->next->next;
  free(temp->next);
  temp->next = next;

}

void delete_given_ptr(struct Node* ptr){
  ptr->data = ptr->next->data;
  ptr->next = ptr->next->next;
  free(ptr->next);
}

void traverse(struct Node* node){
  while(node->next!=NULL){
    cout<<node->data<<" -> ";
    node = node->next;
  }
  cout<<node->data;
}

int main(){
  struct Node* head = NULL;
  struct Node* second = NULL;
  struct Node* third = NULL;

  //allocating 3 nodes in heap
  head = new Node;
  second = new Node;
  third = new Node;

  //chaining
  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  //inserting
  push_at_front(&head, 67);
  insert_after(second, 100);
  append(&head, -200);

  //deleting
  delete_first_occurence(&head,2);
  delete_at_given_position(&head, 1);
  delete_given_ptr(third);

  //traversing the linked list
  traverse(head);

  cout<<"\n";

  return 0;
}
