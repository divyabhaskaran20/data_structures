//
// Created by dbhaskaran on 31/07/23.
//

#ifndef BASIC_LIST_H
#define BASIC_LIST_H


typedef struct node {
    int value;
    struct node *next_node_addr;
}SINGLE_LINKS;


typedef struct link_info {
    SINGLE_LINKS *master;
    int total_cnt;
}LINK_INFO;


/* Function Prototype */
int rear_insert(LINK_INFO *l, int data);
void print_list(LINK_INFO *l);

#endif //BASIC_LIST_H
