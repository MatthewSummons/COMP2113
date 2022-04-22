#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdlib>

using namespace std;

struct Node
{
    int value;
    Node * next;
};

// output the linked list
void print_list(Node * head)
{
    Node * current = head;
    while (current != NULL)
    {
        // process the current node, e.g., print the content
        cout << current->value << " -> ";
        current = current->next;
    }
    cout << "NULL\n";
}

// output the large number stored in the linked list
void print_num(Node * head)
{
    Node * current = head;
    while (current != NULL)
    {
        if (current == head)
            cout << current->value;
        else
            cout << setw(5) << setfill('0') << current->value;
        current = current->next;
    }
}

// insert a value as a node to the head of a linked list
void head_insert(Node * & head, int v)
{
    Node * p = new Node;
    p->value = v;
    p->next = head;
    head = p;
}

// delete the head node from a linked list
void delete_head( Node * & head)
{
    if (head != NULL) {
        Node * p = head;
        head = head->next;
        delete p;
    }
}

// free an entire linked list
void delete_list(Node * & head)
{
    while ( head != NULL )
    {
        delete_head(head);
    }
}

// double the capacity of an array
// array: input array
// size: original size of array, updated to new size of array
void grow_array( char * & array, int & size )
{
    if (array == NULL)
        return;

    int newSize = size * 2;

    // doubled the size of the array;
    char * tmp = new char [ newSize ];
    // copy original contents
    for (int i = 0; i < size; ++i)
        tmp[i] = array[i];

    delete [] array;

    array = tmp;
    size = newSize;
}

// get a number from a user
// by reading character by character until a space is hit
// use dynamic array to store the digits
// digits:  character array that stores the digits of the number
// numDigits: number of digits read from input
void input_num(char * & digits, int & numDigits)
{
    int arraysize = 32;
    digits = new char [arraysize];
    char c;
    int numRead = 0;

    // read each digit as a character until a white space is hit
    c = cin.get();
    while (!isspace(c))
    {
        if (numRead >= arraysize)
            grow_array( digits, arraysize );

        digits[numRead] = c;
        numRead++;

        c = cin.get();
    }

    numDigits = numRead;

}

// get a large integer from user input
// and store in a linked list of Node
// each node stores the value of a chunk of 5 digits taken from the large integer
// e.g., if the input is 43323000089500012, the linked list is
// 43 -> 32300 -> 895 -> 12 -> NULL
//
Node * create_num_list()
{
    // TASK 1a: declare a pointer pointing to the head of the link list
    Node *head = NULL;

    string str;
    char * digits = NULL;  // a dynamic array for storing an input number
    int numDigits;
    int val;

    // get a number from the user
    input_num( digits, numDigits);

    // scan the digits in reverse, and create a list of nodes for
    // the value of every 5 digits
    str.clear();
    for (int i = numDigits-1; i >=0; --i) {
        str = digits[i] + str;
        if (str.length()==5) {
            val = atoi(str.c_str());

            // TASK 1b: insert a value as a node to the head of the linked list
            head_insert(head, val);

            str.clear();
        }
    }
    // the digits array is scanned and there are still digits
    // stored in str that are not inserted into the list yet
    if (!str.empty()) {
        val = atoi(str.c_str());

        // TASK 1c: insert a value as a node to the head of the linked list
        head_insert(head, val);
    }

    // free the dynamic array
    if (digits != NULL) {
        delete [] digits;

    }

    // TASK 1d: return the pointer to the linked list
    return head;
}



// return the length of a linked list
int list_length(Node * head)
{
 	// TASK 3: Modify this print function to one that
	// count the number of nodes in a linked list

    Node * current = head;
    int node_count = 0;
    while (current != NULL)
    {
        node_count++;
        current = current->next;
    }

    return node_count;
}

// return if the number n1 is larger than n2
bool larger(Node * n1, Node * n2)
{
    int len1 = list_length(n1);
    int len2 = list_length(n2);

	// TASK 4a: handle the case
	// when the list lengths are different

    if (len1 > len2)
        return true;

    // the two lists are of equal length

    Node * curr1 = n1, * curr2 = n2;

    while (curr1 != NULL) {
        if (curr1->value > curr2->value)
            return true;
        else if (curr1->value < curr2->value)
            return false;

        // TASK 4b: advance curr1, curr2
		// to point to the next nodes
        curr1 = curr1 -> next;
        curr2 = curr2 -> next;
    }

    return false;
}



int main()
{
    Node * n1, * n2;

    cout << "expr> ";
    n1 = create_num_list();
    cin.get();       // skip the '>' sign
    cin.get();       // the space after the '>' sign
    n2 = create_num_list();

    // TASK 2: call print_list() on n1 and n2 for checking
    print_list(n1);
    print_list(n2);

    if (larger(n1, n2)) {
        cout << "Yes, ";
        print_num(n1);
        cout << " is larger." << endl;
    }
    else {
        cout << "No, ";
        print_num(n1);
        cout << " is not larger." << endl;
    }

    // TASK 5: free the linked lists
    delete_list(n1);
    delete_list(n2);
}

