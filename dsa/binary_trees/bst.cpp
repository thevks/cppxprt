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
        BST(vector<int> items);

        bst_node *root = NULL;

        void add_node(int item);
				void delete_node(int item);

				vector<bst_node *> get_diameter_nodes();
				vector<bst_node *> get_max_path_nodes();

				//Get all nodes, matching with target and at distance k
				vector<bst_node *> get_k_distance_nodes(int target, int k);

				int get_height(); //or depth
				bool is_exists(int item);
				bool is_valid_bst();
				bool is_mirror();
				bool is_height_balanced();
				
				bst_node* get_minium_value_node();
				bst_node* get_maximum_value_node();
				bst_node* get_kth_largest_node();
				bst_node* get_kth_smallest_node();
				bst_node *get_lowest_common_ancestor_node(bst_node *n1, bst_node *n2);
				BST *get_inverted_bst(BST *bst);

				//Flatten the BST and returns its left most node
				bst_node* flatten_bst();

				//Transform BST into its right sibling tree and returns its root pointer
				bst_node* right_sibling_tree();
				
				
				void print_node_with_height();
				void get_node_with_height(vector<int,int>& array);

        void print_in_order_traversal();
				void get_in_order_traversal(vector<int>& array);

        void print_pre_order_traversal();
				void get_pre_order_traversal(vector<int>& array);
				
        void print_post_order_traversal();
				void get_post_order_traversal(vector<int>& array);

				void level_order_traversal();
				void get_level_order_traversal(vector<int>& array);

				void print_iterative_in_order_traversal();

};

BST::BST(vector<int> items)
{
    for (int item: items)
        add_node(item);
};

//bst_node * BST::insert(bst_node *node, int item)
bst_node * insert(bst_node *node, int item)
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

//void BST::_print_in_order_traversal(bst_node *node)
void _print_in_order_traversal(bst_node *node)
{
    if (node == NULL)
        return;
    _print_in_order_traversal(node->left);
    cout<< node->item << " ";
    _print_in_order_traversal(node->right);
}

void BST::print_in_order_traversal()
{
    _print_in_order_traversal(this->root);    
}

int main(void)
{
    vector<int> items{2,5,6,7,8,1,3,4};
    
    BST *bst = new BST(items);

    bst->add_node(99);
    bst->add_node(-10);
    cout<<"Tree Items are: " << endl;
    bst->print_in_order_traversal();
    cout << endl;

    return 0;
}
