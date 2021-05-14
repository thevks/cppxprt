#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

class doubly_linked_list
{
    private:
	node *head;  	// points to first node of list
	node *tail;   	// points to first las of list
	
    public:
	doubly_linked_list()
	{
		head = NULL;
		tail = NULL;
	}
    ~doubly_linked_list();
	
    void add_front(int );
	void add_after(node* , int );
	void add_before(node* , int );
	void add_end(int );
	void delete_node(node *);
	void forward_traverse();
	void backward_traverse();
};


void doubly_linked_list::add_front(int d)
{
    // Creating new node
	node *temp;
	temp = new node();
	temp->data = d;
	temp->prev = NULL;
	temp->next = head;

	// List is empty
	if(head == NULL)
		tail = temp;
		
	else
		head->prev = temp;
		
	head = temp;
}

void doubly_linked_list::add_after(node *n, int d)
{
    node *temp;
	temp = new node();
	temp->data = d;
	temp->prev = n;
	temp->next = n->next;
	n->next = temp;

	//if node is to be inserted after last node
	if(n->next == NULL)
		tail = temp;

}

void doubly_linked_list::add_before(node *n, int d)
{
    node *temp;
	temp = new node();
	temp->data = d;
	temp->next = n;
	temp->prev = n->prev;
	n->prev = temp;

	//if node is to be inserted before first node
	if(n->prev == NULL)
		head = temp;
}

void doubly_linked_list::add_end(int d)
{
    // create new node
	node *temp;
	temp = new node();
	temp->data = d;
	temp->prev = tail;
	temp->next = NULL;

	// if list is empty
	if(tail == NULL)
		head = temp;
	else
		tail->next = temp;	
	tail = temp;
}

void doubly_linked_list::delete_node(node *n)
{
    // if node to be deleted is first node of list
	if(n->prev == NULL)
	{
		head = n->next; //the next node will be front of list
		head->prev = NULL;
	}
	// if node to be deleted is last node of list
	else if(n->next == NULL)
	{
		tail = n->prev;   // the previous node will be last of list
		tail->next = NULL;
	}
	else
	{
		//previous node's next will point to current node's next
		n->prev->next = n->next;
		//next node's prev will point to current node's prev
		n->next->prev = n->prev;
	}
	//delete node
	delete(n);			
}

void doubly_linked_list::forward_traverse()
{
    node *p;
	p = head;
	while(p != NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
}

void doubly_linked_list::backward_traverse()
{
    node *p;
	p = tail;
	while(p != NULL)
	{
		cout<<p->data<<" ";
		p = p->prev;
	}
}


int main(void)
{
    doubly_linked_list* l = new doubly_linked_list();
    
    l->add_end(2);
    l->add_end(4);
    l->add_end(5);

    cout << "Forward Traversal: " << endl;
    l->forward_traverse();
    
    cout << "Backward Traversal: " << endl;
    l->backward_traverse();
    cout<<endl;

    return 0;
}