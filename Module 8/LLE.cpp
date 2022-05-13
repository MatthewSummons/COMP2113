// Exp

#include <iostream>
using namespace std;


struct Node {
  int val;
  Node *next;
};

// Add elements to the end
void build_forward(int val, Node *&head, Node *&tail)
{
  Node *temp = new Node;
  temp -> val = val;
  temp -> next = NULL;
  
  if (head == NULL)
    head = temp;
  
  else 
    tail -> next = temp;

  tail = temp;
}


void print(Node *head) {
  Node *curr = head;

  while (curr != NULL) {
    cout << curr -> val << " -> ";
    curr = curr -> next;
  }

  cout << "NULL" <<endl;
}


void build_backward(int val, Node *& head) {
  
  Node *temp = new Node;
  temp -> val = val;
  // Initialized so no Garbage value
  temp -> next = head;

  head = temp;
}

int main() {
  
  Node *head = NULL, *tail = NULL;

  
  build_forward(23, head, tail);
  build_forward(32, head, tail);
  build_forward(231, head, tail);

  print(head);

  Node *head1 = NULL;

  build_backward(23, head1);
  build_backward(32, head1);
  build_backward(231, head1);

  print(head1);
  
  
  return 0;
}
