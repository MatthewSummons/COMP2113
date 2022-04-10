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

// assume that after points to a node
// i.e., after not equals null
void insert( Node * after, int num )
{
    Node * p = new Node;
    p->info = num;
    p->next= after->next;
    after->next = p;
}

// return the node which is the last one in
// the list that is smaller than num
Node * find_prev( Node * head, int num )
{
    if (head == NULL || head->info >= num )
        return NULL;

    // at least one node in the list now
    Node * current = head;

    while (current->next != NULL)
    {
        if (current->next->info >= num)
            return current;
        else
            current = current->next;
    }

    return current;
}

Node * find( Node * head, int num )
{
    Node * current = head;

    while (current != NULL)
    {
        if (current->info == num)
            return current;
        else
            current = current->next;
    }

    return NULL;
}

void delete_head( Node * & head)
{
    if (head != NULL)
    {
        Node * p = head;
        head = head->next;
        delete p;
    }
}

// assume that after points to a node
// i.e., after not equals null
void delete_node( Node * after)
{
    Node * p = after->next;
    after->next = p->next;
    delete p;
}

int get_option()
{
    int c;
    cout << endl << "enter option (1: insert; 2: delete; 3: reverse; 4: get; 0: quit) ";
    cin >> c;
    return c;
}


void insert_sorted( Node * & head, int num)
{
    Node * after_this = find_prev(head, num);
    if (after_this == NULL)
        head_insert(head, num);
    else
        insert(after_this, num);
}


void option_insert(Node * & head)
{
    int num;
    cout << endl << "number to insert: ";
    cin >> num;

    insert_sorted( head, num );
}

void option_delete(Node * & head)
{
    int num;
    cout << endl << "number to delete: ";
    cin >> num;

    Node * p = find(head, num);

    if (p == NULL)
    {
        cout << "item not found!" << endl;
    }
    else
    {
        // find the previous node, so that we can delete
        p = find_prev(head, num);
        if (p == NULL)
            delete_head(head);
        else
            delete_node(p);
    }
}

void delete_list(Node * & head)
{
    cout << "deleting list... " << endl;
    while ( head != NULL )
    {
        delete_head(head);
    }
}

void reverse( Node * & head )
{
    Node * curr = head;
    Node * prev = NULL;
    Node * next;

    while ( curr != NULL )
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    head = prev;
}

// return the k-th item
// return NULL if item not exists
Node * get_item(Node * head, int k)
{
    Node * current = head;
    int idx = 0;
    while (current != NULL) {
        if (idx == k)
            return current;
        idx++;
        current = current->next;
    }
    return NULL;
}

void option_get(Node * head)
{
    int k;
    cout << endl << "enter 0-based position for an item: ";
    cin >> k;

    Node * p = get_item(head, k);
    if (p != NULL)
        cout << "Item at position " << k << " is " << p->info << endl;
    else
        cout << "Item does not exist." << endl;

    cout << endl;
}

int main()
{
    Node * head = NULL, * after_this;
    int num = 0;

    // build sorted linked list
    cout << "input integers (-999 to end): ";
    cin >> num;
    while ( num != -999 )
    {
        insert_sorted( head, num );
        cin >> num;
    }
    print_list(head);

    int c;
    while (c = get_option())
    {
        switch (c)
        {
        case 1:
            // insert a node
            option_insert(head);
            break;
        case 2:
            // delete a node
            option_delete(head);
            break;
        case 3:
            // reverse a list
            reverse(head);
            break;
        case 4:
            // get an item
            option_get(head);
        }
        print_list(head);
    }

    delete_list(head);

    return 0;
}
