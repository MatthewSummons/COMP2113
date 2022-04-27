// Large Numbers Addition
// Add two arbitrarily large numbers together using linked lists
// Created by Shaheer Ziya

#include <iostream>   // For Standard Input & Output
#include <string>     // For C++ strings to store number chunks in create_num_list()
#include <cctype>     // For isspace() in obtain_num()
#include <cstdlib>    // For atoi() to convert C-strings to integer types
#include <cmath>      // For pow()
#include <iomanip>    // For padding with leading zeroes in print_num()

using namespace std;

// Structure representing a node in linked lists.
// Consists of an integer "value" and a "next" pointer
struct Node {
  int value;
  Node * next;
};

// Functions to obtain user input
Node * create_num_list();
void obtain_num(char *& digits, int & num_digits);
void grow_array(char *& array, int & array_size);
void tail_insert(Node *& head, Node *& tail, int value);    // Used in add_two_nums(*args) to create resultant linked list

// Functions to output linked lists
void print_list(Node *head);
void print_num(Node *head);

// Functions to add two numbers in linked lists together
Node * add_two_nums(Node *num1, Node *num2);
bool isCarry(const int, const int);

int list_length(Node *head);


int main() {
  
  // Obtain input from user and store it in two separate linked lists
  Node *num1, *num2;

  num1 = create_num_list();

  cin.get();      // Skip the + sign in the input
  cin.get();      // Skip the space after the + sign in the input 

  num2 = create_num_list();

  // Output the numbers represented in the two linked lists to screen
  print_list(num1);
  print_list(num2);

  // Add two numbers and store result in linked list
  Node * sum;
  sum = add_two_nums(num1, num2);
  
  // Output the resultant number in the linked list to screen
  print_list(sum); 

  // Output number represented by that linked list to screen
  print_num(sum);
}

// Take a user-input number from standard input.
// Return a pointer to the head of a linked list storing the number.
// For example "123456789" will be stored as "678 -> 345 -> 12 -> NULL".
Node * create_num_list() {
  char * digits = NULL;
  int num_digits = 0;

  // Store the numbers input by user in an array
  obtain_num(digits, num_digits);

  // Scan the array in reverse and add chunks of three digits as a Node to the linked list
  string chunk = "";

  // Head & Tail of the linked list
  Node *head = NULL, *tail = NULL;
  int val;
  
  for (int i = num_digits - 1; i >= 0; i--) {
    // "123456789" shall be stored as "678 -> 345 -> 12 -> NULL"
    // "1009" shall be stored as "9 -> 1 -> NULL"
    chunk = digits[i] + chunk;

    if (chunk.length() == 3) {
      val = atoi(chunk.c_str());

      // Insert the value to the linked list as a Node to the end of the list
      tail_insert(head, tail, val);

      chunk.clear();
    }
  }

  // Add the remaning digits (if any) to the linked lists
  if (!chunk.empty()) {
    val = atoi(chunk.c_str());
    tail_insert(head, tail, val);
  }

  // Free up space
  if (digits != NULL) {
    delete [] digits;
  }

  return head;
}

// Store the "digits" of the input number in a dyanmic array of the same name & modify num_digits
// to the number of digits in the dynamic array (for looping purposes)
void obtain_num(char *& digits, int & num_digits) {
  
  int array_size = 32;
  digits = new char [array_size];   // Dynamic Array to store the digits
  
  char chr = cin.get();
  int num_read = 0;

  // Read digit characters untile a whitespace is read
  while (!isspace(chr)) {
    
    if (num_read >= array_size) {
      grow_array( digits, array_size );
    }
    
    digits[num_read] =  chr;
    num_read++;

    chr = cin.get();
  }

  // Update number of digits
  num_digits = num_read;
}

// Take in an array and its size then double its capacity
void grow_array(char *& array, int & array_size) {
  if (array == NULL)
    return;

  int new_array_size = array_size * 2;

  // Double the size of the array;
  char *temp = new char[new_array_size];
  // Copy the original contents
  for (int i = 0; i < array_size; ++i)
    temp[i] = array[i];

  delete[] array;

  array = temp;
  array_size = new_array_size;
}

// Insert an intger "value" to the end of a given linked list provided its "head" & "tail" pointers
void tail_insert(Node *&head, Node *&tail, int value) {
  Node * ptr = new Node;
  ptr -> value = value;
  ptr -> next = NULL;

  // If empty linked list
  // head -> NULL
  if (head == NULL) {
    head = ptr;
    tail = ptr;
  } 
  // If non-empty
  // head -> ... -> p  -> ... -> tail -> NULL
  else {
    tail -> next = ptr;
    tail = ptr;
  }
}


// Print the "value" of each Node in a linked list given its head
void print_list(Node *head)
{
  Node *current = head;
  while (current != NULL)
  {
    // Print the content of the current node
    cout << current->value << " -> ";
    current = current->next;
  }
  cout << "NULL\n";
}

// Takes two numbers represented in linked lists
// Returns the head to a linked list representing the sum of the two input numbers
// For example, "999 -> 999 -> NULL" + "999 -> 899", which represent the numbers
// 999,999 & 999,899 respectively, will be returned as "898 -> 999 -> 1 -> NULL"
Node *add_two_nums(Node *num1, Node *num2) {
  
  // Determine the longer of the two linked lists
  // If they have the same length, preserve their order

  Node *long_list, *short_list;
  
  if (list_length(num1) >= list_length(num2)) {
    long_list = num1;
    short_list = num2;
  }

  else {
    long_list = num2;
    short_list = num1;
  }

  // Create a linked list to store the sum of the two numbers
  Node *head = NULL, *tail = NULL;

  // Traverse the longer linked list and add the corresponding digits of the shorter linked list

  int node_carry = 0;     // Hold the carry from the sum of previous nodes
  Node *curr1 = long_list, *curr2 = short_list;

  int node_sum = 0;     // Hold the sum of the nodes
  
  // Loop till the end of the shorter list, summing the corresponding nodes from the longer list
  while (curr2 != NULL) {
    // Add the carry value from the previous summing of nodes (if any)
    if (node_carry != 0) {
      node_sum++;
      node_carry = 0;
    }
    
    node_sum += curr1 -> value + curr2 -> value;
    
    // Determine if after the summing of nodes any carry is generated
    if (isCarry(node_sum, 3))
      node_carry++;
      node_sum %= 1000;     // Add the three digit sum (carry removed)
    
    // Insert the sum of the nodes into the new linked list being constructed
    tail_insert(head, tail, (node_sum));
    
    // Reset node_sum to zero
    node_sum = 0;
    
    // Advance to the next nodes in the two linked lists
    curr1 = curr1 -> next;
    curr2 = curr2 -> next;
  }


  // If length of the two linked lists is not the same, then traverse till the end of the longer list
  // adding the nodes and taking care of the carry to the thrid resultant list
  while (curr1 != NULL) {
    
    if (node_carry != 0) {
      node_sum++;
      node_carry = 0;
    }

    node_sum += curr1 -> value;

    if (isCarry(node_sum, 3)) {
      node_carry++;
      node_sum %= 1000;     // Add the three digit sum (carry removed)
    }

    tail_insert(head, tail, node_sum);

    // Reset the node_sum to zero
    node_sum = 0;
    
    // Advance to the next node in the longer list
    curr1 = curr1 -> next;
  }

   // Handle any leftover carry
  if (node_carry != 0) {
    tail_insert(head, tail, 1);
  }

  // Return the head of the resultant linked list
  return head;
}

// Take in an integer and determine if it has more than "carry_limit" digits
bool isCarry(const int node_sum, const int carry_limit) {
  return (node_sum / static_cast<int>(pow(10, carry_limit)) != 0);
}

// Take in the head of a linked list
// Return the length of a linked list
int list_length(Node *head) {
  // Count the number of nodes in a linked list

  Node *current = head;
  int node_count = 0;
  while (current != NULL) {
    node_count++;
    current = current -> next;
  }

  return node_count;
}

// Take in the head of a linked list and print the number repsrented by it
// For example "678 -> 9 -> 12" will print "12009678"
void print_num(Node *head) {
  // Initialize a string array to store the digits of the linked list
  int array_size = list_length(head);     // Each node has at max 3 digits
  int *digits = new int [array_size];

  // Traverse the linked list and store the digits in each node to the array
  // The linked list stores the digits in reverse so iterate over the array in reverse
  Node *current = head;
  int node_val = 0;
  for (int i = array_size - 1; i >= 0; i--) {
    node_val = current -> value;
    digits[i] = node_val;
    current = current -> next; 
  }

  // Iterate over the array and print the digits to standard output
  cout << digits[0];      // The first entry is special because no leading zeros

  int chunk_size = 3;
  for (int i = 1; i < array_size; i++) {
    cout << setfill('0') << setw(chunk_size) << digits[i];      // Add leading zeros if neccessary
  }
  
  cout << endl;
}