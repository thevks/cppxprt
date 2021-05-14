#include <iostream>
using namespace std;

struct node {
public:
    int data;
    node* next;
};

class linked_list{
private:
    node* head;
    node* tail;
public:
    linked_list() { // constructor
        head = NULL;
        tail = NULL;
    }
    ~linked_list() {}; // destructor
    void add_node(int);
    void delete_node(int);
    void reverse_list();
    void display();
    void node_swap_iterative();
    void node_swap_recusive();
    void zipped_linked_list();
    bool is_palindrome();

    void partition_list_around_value(int);
};

node * _partition_list_around_value(node *head, int x)
{
    
    node *smaller_head, *smaller_tail;
    node *greater_head, *greater_tail;
    node *equal_head, *equal_tail;

    //Process the original list and create three list
    //{

    //}

    greater_tail->next = NULL;

    smaller_tail->next = equal_head;
    equal_tail->next = greater_head;

    return smaller_head;
}

void linked_list::partition_list_around_value(int x)
{
    this->head = _partition_list_around_value(this->head, x);
}

node * _node_swap_recusive(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    node *next_node = head->next;
    head->next = _node_swap_recusive(head->next->next);
    next_node->next = head;

    return next_node;
}

void linked_list::node_swap_recusive()
{
    this->head = _node_swap_recusive(this->head);
}

node* _node_swap_iterative(node *head)
{
    node *temp = new node();
    temp->next = head;

    node *prev = temp;
    node *first;
    node *second;

    while ((prev->next != NULL) && (prev->next->next != NULL))
    {
        first = prev->next;
        second = prev->next->next;

        first->next = second->next;
        second->next = first;
        prev->next = second;

        prev = first;             
    }

    return temp->next;   
}

void linked_list::node_swap_iterative()
{
    this->head = _node_swap_iterative(this->head);   
}

// function to add node to a list
void linked_list::add_node(int val) {
    node* newnode = new node();
    newnode->data = val;
    newnode->next = NULL;
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    }

    else {
        /*
        tail->next = newnode;
        tail = tail->next;
        */
        node* temp = head; // head is not NULL
        while (temp->next != NULL) { 
            temp = temp->next; // go to end of list
        }
        temp->next = newnode; // linking to newnode
        
    }
}

// reverse Linked List
void linked_list::reverse_list() {
    node* temp = head;
    node* nextnode = NULL;
    node* revnode = NULL;
    while (temp != NULL) {
        head = temp;
        nextnode = temp->next;
        temp->next = revnode;
        revnode = temp;
        temp = nextnode;
    }
}

void linked_list::display() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
    }
    else {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

void _zipped_linked_list(node *head)
{
    //split the list into first & second list
    //Reverse seond list
    //Start from first list. Merge two lists nodes - alternatively
}

//Returns the zipped version of the list
void linked_list:: zipped_linked_list()
{
    _zipped_linked_list(this->head);    
}

bool linked_list::is_palindrome()
{
    //use slow & fast pointers to identify middle of list 
    //Reverse second half of the list
    //compare the nodes in first half and second half
    return false;
}

int main() {
    linked_list* list = new linked_list();
    list->add_node(100);
    list->add_node(200);
    list->add_node(300);
    list->add_node(400); 
    list->add_node(500);
    cout << "Linked List data" << endl;
    list->display();
    list->reverse_list();
    cout << "Reversed Linked List data" << endl;
    list->display();

    list->node_swap_iterative();
    list->display();

    list->node_swap_recusive();
    list->display();

    delete list;
    return 0;
}