#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct node 
{
    int item;
    struct node *next;
}node_t;

void addNode(node_t **root, int value)
{
    node_t *temp = NULL, *p = NULL;

    temp = (node_t *)malloc(sizeof(node_t));
    assert(temp != NULL);
    temp->item = value;
    temp->next = NULL;

    if (*root == NULL) {
        *root = temp;
    } else {
        p = *root;
        while (p->next != NULL) //Go to end of list
            p = p->next;
        p->next = temp;
    }
    return;
}

void printList(node_t *root)
{
    node_t *p;
    for (p = root; p != NULL; p= p->next)
        printf("%d ", p->item);
    printf("\n");
}

void printUsingRecursion(node_t *root)
{
    if (root) {
        printf("%d ", root->item);
        printUsingRecursion(root->next);
    }
}

void printReverseUsingRecursion(node_t *root)
{
    if (root->next) 
        printReverseUsingRecursion(root->next);
    printf("%d ", root->item);
}

//Compares two lists
int compare_lists(node_t *p, node_t *q)
{
    static int flag;
    if ((p == NULL) && (q == NULL))
        flag = 1;
    else {
        if ((p == NULL) || (q == NULL))
            flag = 0;
        else if (p->item != q->item)
                flag = 0;
        else
            compare_lists(p->next, q->next);
    }
    return flag;
}

node_t *copy_list(node_t *root)
{
    node_t *temp = NULL;
    if (root){
        temp = (node_t *)malloc(sizeof(node_t)); 
        assert(temp != NULL);
        temp->item = root->item;
        temp->next = copy_list(root->next);
    }
    return temp;
}

int main(void)
{
    node_t *head1 = NULL, *head2 = NULL, *head3 = NULL;

    addNode(&head1, 40);
    addNode(&head1, 20);
    addNode(&head1, 30);
    addNode(&head1, 10);
    printf("Head 1 ---> ");
    printList(head1);

    addNode(&head2, 40);
    addNode(&head2, 20);
    addNode(&head2, 50);
    addNode(&head2, 10);
    printf("Head 2 ---> ");
    printList(head2);

    if (compare_lists(head1, head2))
        printf("Lists are equal\n");
    else
        printf("Lists are not equal\n");

    head3 = copy_list(head2);
    printf("Head 3 ---> ");
    printList(head3);

    printf("Head 3 ---> ");
    printReverseUsingRecursion(head3);
    printf("\n");

    printf("Head 3 ---> ");
    printUsingRecursion(head3);
    printf("\n");

    return 0;
}
