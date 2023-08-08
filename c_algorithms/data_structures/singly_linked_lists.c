#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node_t;

void insert_at_beginnig(node_t **head_list, int new_data){

    node_t * new_node = (node_t *) malloc(sizeof(node_t));

    new_node->value = new_data;
    new_node->next = (*head_list);

    (*head_list) = new_node;
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
    node_t **head_list = (node_t **) malloc(sizeof(node_t));

    insert_at_beginnig(head_list, 2);
    insert_at_beginnig(head_list, 23);
    insert_at_beginnig(head_list, 22);
    insert_at_beginnig(head_list, 21);
    insert_at_beginnig(head_list, 29);

    print_list(head_list);

}