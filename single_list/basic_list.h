/**
 * @file    basic_list.h
 *
 * @brief   H File
 *          Data structure - Single Linked list
 *          This File will exercise the various insert/delete options on singly linked list
 *
 * @author  Divya Bhaskaran
 *
 * @date    09/08/2023
 *
 */

#ifndef BASIC_LIST_H
#define BASIC_LIST_H

/**
 *   SINGLE_LINKS
 */
typedef struct node {
    int value;                               /**< Value stored in the list         */
    struct node *next_node_addr;             /**< Address of next node stored in   */
}SINGLE_LINKS;


/**
 *   LINK_INFO
 */
typedef struct link_info {
    SINGLE_LINKS *master;                    /**< Address of MASTER node               */
    int total_cnt;                           /**< Total elements stored in Linked list */
}LINK_INFO;


/**
 *   Function Prototype  - INSERT
 */
int     rear_insert                 (LINK_INFO *l, int data);
int     front_insert                (LINK_INFO *l, int data);
int     position_insert             (LINK_INFO *l, int data, int pos);
int     mid_insert                  (LINK_INFO *l, int data);


/**
 *   Function Prototype  - DISPLAY
 */
void    print_list                  (LINK_INFO *l);


/**
 *   Function Prototype  - DELETE
 */
void    front_delete                (LINK_INFO *l);
void    rear_delete                 (LINK_INFO *l);
void    mid_delete                  (LINK_INFO *l);


/* Function Prototype  - SEARCH */
/* Todo */

/* Todo */
/* Function Prototype  - INSERT - ASCENDING */
/* Function Prototype  - INSERT - DESCENDING */


#endif //BASIC_LIST_H
