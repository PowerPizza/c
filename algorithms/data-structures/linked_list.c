#include <stdio.h>
#include <stdlib.h>

/*
This program is example of linked list.
by : https://github.com/powerpizza

Fact about C-lang pointers :-
if function takes structure as argument like : add_data(Node * n, int data)
so n = ____ will not gonna affect actual structure.
but *n = ____ will gonna affect actual structure.

but n->member1 = ____ will gonna affect and change value of actual structure's member.
*/

typedef struct node{
    int data;
    struct node * next_node;
} Node;

Node * initLinkedList(int value){
    // To create/initialize a new linked list.
    Node * node1 = (Node*) malloc(sizeof(Node));
    node1->data = value;
    node1->next_node = NULL;
    return node1;
}

void addElement(Node * n, int data){
    // To add new element at the end of list
    while (n->next_node != NULL)
    {
        n = n->next_node;
    }
    n->data = data;
    Node * to_add = (Node*)malloc(1*sizeof(Node));
    to_add->data = 0;
    to_add->next_node = NULL;
    n->next_node = to_add;
}

void printList(Node * n){
    // To print whole content of linked list.
    while (n->next_node != NULL)
    {
        printf("%d\n", n->data);
        n = n->next_node;
    }
}

int getListLength(Node * n){
    // To get no. of items in linked list.
    int i = 0;
    while (n->next_node != NULL)
    {
        i++;
        n = n->next_node;
    }
    return i;
}

void insertAtIndex(Node * n, int idx_, int value){
    // To insert a new node in linked list at any index.
    for (int i = 0; i < idx_; i++){
        n = n->next_node;
    }
    Node * new_data = (Node*) malloc(sizeof(Node));
    new_data->data = n->data;
    new_data->next_node = n->next_node;
    n->data = value;
    n->next_node = new_data;
}

void deleteByIndex(Node * n, int idx_){
    // To delete any index node from linked list
    for (int i = 0; i < idx_; i++){
        n = n->next_node;
    }
    n->data = n->next_node->data;
    n->next_node = n->next_node->next_node;
}

int main(){
    // USAGE....
    Node * l1 = initLinkedList(100);
    addElement(l1, 30);
    addElement(l1, 40);
    // printList(&l1);
    // printf("LENGTH OF LINKED LIST IS : %d\n", getListLength(&l1));
    addElement(l1, 40);
    addElement(l1, 90);
    // printf("LENGTH OF LINKED LIST IS : %d\n", getListLength(&l1));
    printList(l1);
    // printf("AFTER INSERTION\n");
    // insertAtIndex(l1, 4, 100);
    printf("AFTER DELETION\n");
    deleteByIndex(l1, 3);
    printList(l1);
    return 0;
}