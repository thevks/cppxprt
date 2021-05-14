#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
};

class linked_list{
private:
    node* head, *tail;
public:
    linked_list() { // constructor
        head = NULL;
        tail = NULL;
    }
    ~linked_list() {}; // destructor
    void add_node(int val);
    void delete_node(int val);
    void reverse_list();
    void display();

};

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
        tail->next = newnode;
        tail = tail->next;
        /*
        node* temp = head; // head is not NULL
        while (temp->next != NULL) { 
            temp = temp->next; // go to end of list
        }
        temp->next = newnode; // linking to newnode
        */
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
    delete list;
    return 0;
}