#include<iostream>
#include<vector>

using namespace std;

class bst_node
{
    public:
        bst_node *left;
        int item;
        bst_node *right;
        bst_node(int item);
};

bst_node::bst_node(int item)
{
    this->item = item;
    left = NULL;
    right = NULL;   
};

class BST
{
    public:
        bst_node *root = NULL;
        void add_node(int item);
        //void _add_node(bst_node **node, int item);
        void in_order_traversal();
        void _in_order_traversal(bst_node *node);
        bst_node *insert(bst_node *node, int item);
        BST(vector<int> items);
};

BST::BST(vector<int> items)
{
    for (int item: items)
        add_node(item);
};

bst_node * BST::insert(bst_node *node, int item)
{
    if (node == NULL)
        return new bst_node(item);

    if (item < node->item)
        node->left = insert(node->left, item);
    else
        node->right = insert(node->right, item);

    return node;
}

/*
void BST::_add_node(bst_node **node, int item)
{
    if (*node == NULL) {
        *node = new bst_node(item);
        return;
    }
    if (item < (*node)->item)
        _add_node(&((*node)->left), item);
    else
        _add_node(&((*node)->right), item);    
}
*/

void BST::add_node(int item)
{
    this->root = insert(this->root, item);
}

void BST::_in_order_traversal(bst_node *node)
{
    if (node == NULL)
        return;
    _in_order_traversal(node->left);
    cout<< node->item << " ";
    _in_order_traversal(node->right);
}

void BST::in_order_traversal()
{
    _in_order_traversal(this->root);    
}

int main(void)
{
    vector<int> items{2,5,6,7,8,1,3,4};
    
    BST *bst = new BST(items);

    bst->add_node(99);
    bst->add_node(-10);
    cout<<"Tree Items are: " << endl;
    bst->in_order_traversal();
    cout << endl;

    return 0;
}
