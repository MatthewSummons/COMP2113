#include <iostream>

using namespace std;

struct Node
{
	int info;
	Node * next;
};

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

void head_insert(Node * & head, int num)
{
	Node * p = new Node;
	p->info = num;
	p->next = head;
	head = p;
}


int main()
{
    Node * head = NULL;
    int num = 0;

    // build linked list backward
    cout << "input integers (-999 to end): ";
    cin >> num;
    while ( num != -999 ) {
        head_insert(head, num);
        cin >> num;
    }

    // print the items in the linked list
    print_list(head);

    return 0;
}
