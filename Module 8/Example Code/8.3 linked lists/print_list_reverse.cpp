#include <iostream>

using namespace std;

struct Node
{
	int info;
	Node * next;
};

void print_list_reverse(Node * head)
{
    if (head == NULL)
        cout << "NULL";
    else {
        print_list_reverse( head->next );
        cout << " <- " << head->info;
    }
}

void print_list(Node * head)
{
    Node * current = head;
	while (current != NULL)
	{
		// process the current node, e.g., print the content
		cout << current->info << " -> ";
		current = current->next;
	}
	cout << "NULL\n";
}

void tail_insert(Node * & head,
	Node * & tail, int num)
{
	Node * p = new Node;
	p->info = num;
	p->next = NULL;

	if (head == NULL) {
		head = p;
		tail = p;
	}
	else {
		tail->next = p;
		tail = p;
	}
}



int main()
{
    Node * head = NULL, * tail = NULL;
    int num = 0;

    // build linked list backward
    cout << "input integers (-999 to end): ";
    cin >> num;
    while ( num != -999 ) {
        tail_insert(head, tail, num);
        cin >> num;
    }

    // print the items in the linked list
    cout << "print list in order: " << endl;
    print_list(head);

    // print the items in the linked list in reverse
    cout << "print list in reverse: " << endl;
    print_list_reverse(head);

    return 0;
}
