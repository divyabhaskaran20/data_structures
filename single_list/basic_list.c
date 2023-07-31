//
// Created by dbhaskaran on 24/07/23.
//

#include <stdio.h>
#include <stdlib.h>

#include "basic_list.h"

int rear_insert(LINK_INFO *l, int data) {

    SINGLE_LINKS *node, *temp = NULL;
    /* Node Creation */
    node = (SINGLE_LINKS *) malloc(sizeof(SINGLE_LINKS));
    if (node == NULL) {
        printf("Error: Malloc Failed");
        /* Failure */
        return 0;
    } else {
        node->value = data;
        node->next_node_addr = NULL;
        /* First Node Insert */
        if (l->master == NULL) {
            l->master = node;
            l->total_cnt++;
        } else {
            /* Traverse to End */
            temp = l->master;
            while (temp->next_node_addr != NULL) {
                temp = temp->next_node_addr;
            }
            /* Insert at End */
            temp->next_node_addr = node;
            l->total_cnt++;
        }
    }

    /* Success */
    return 1;
}

void print_list(LINK_INFO *l) {

    SINGLE_LINKS *sl = l->master;
    for(int i = 0; i < l->total_cnt; i++) {
        printf("%d ---> ", sl->value);
        sl = sl->next_node_addr;
    }
    printf("NULL \n");
 }




