#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node_t;

void insert_at_end(node_t **head_ref, int new_data) {
    node_t * new_node = (node_t *) malloc(sizeof(node_t));
    node_t * last = *head_ref;

    new_node->value = new_data;
    new_node->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL) {
        last = last->next;
    }

    last->next = new_node; // o last é um ponteiro que aponta para o último nodo (passagem por referência)
    return;

}
void insert_at_beginnig(node_t **head_list, int new_data){

    node_t * new_node = (node_t *) malloc(sizeof(node_t));

    new_node->value = new_data;
    new_node->next = (*head_list);

    (*head_list) = new_node;
}

void insert_after_given_node (node_t *node, int new_data){
    node_t * new_node = (node_t *) malloc(sizeof(node_t));

    if (node == NULL) {
        printf("Ops, given node is null");
        return;
    }

    new_node->value = new_data;
    new_node->next = node->next;
    node->next = new_node;
}

void print_list(node_t **head_list){

    node_t *temp = (node_t *) malloc(sizeof(node_t));

    temp = *head_list;

    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
}

int main () {
    node_t **head_list = (node_t **) malloc(sizeof(node_t)); // referência indireta ao primeiro nodo

    insert_at_beginnig(head_list, 2);
    insert_at_beginnig(head_list, 23);
    insert_at_beginnig(head_list, 22);
    insert_at_beginnig(head_list, 21);
    insert_at_beginnig(head_list, 29);


    insert_at_end(head_list, 932);

    node_t *node = *head_list;

    insert_after_given_node(node, 876543);
    print_list(head_list);

}