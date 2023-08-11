/**
 * @file    basic_list.c
 *
 * @brief   This c File features insert/delete/display features of linked list
 *
 * @author  Divya Bhaskaran
 *
 * @date    09/08/2023
 *
 */

/**< Standard Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>


#include "basic_list.h"         /**< User defined header Files */


static int Is_Empty(LINK_INFO *l);  /**< Local Static function to identify the list is empty or not */


/**
 * @brief               Insert Elements at the end of the linked List
 * @param[in] l         Pointer to structure to hold the master node & number of elements in list.
 * @param[in] data      data to store in the existing list.
 * @return[out] 1/0     1- Successfull insertion / 0 - Failure
 */
int rear_insert(LINK_INFO *l, int data) {

    SINGLE_LINKS *node, *temp = NULL;   /**< Detailed description after the member */
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


/**
 * @brief               Insert Elements at the Start of the linked List
 * @param[in] l         Pointer to structure to hold the master node & number of elements in list.
 * @param[in] data      data to store in the existing list.
 * @return[out] 1/0     1- Successfull insertion / 0 - Failure
 */
int front_insert(LINK_INFO *l, int data) {

    SINGLE_LINKS *node = NULL;
    /* Node Creation */
    node = (SINGLE_LINKS *) malloc(sizeof(SINGLE_LINKS));
    if (node == NULL) {
        printf("Error: Malloc Failed");
        /* Failure */
        return 0;
    } else {
        node->value = data;
        node->next_node_addr = NULL;
        if(l->master == NULL) {
            l->master = node;
            l->total_cnt++;
        } else {
            node->next_node_addr = l->master;
            l->master = node;
            l->total_cnt++;
        }
    }

    /* Success */
    return 1;
}


/**
 * @brief               Insert Elements at any given position in  the linked List
 * @param[in] l         Pointer to structure to hold the master node & number of elements in list.
 * @param[in] data      data to store in the existing list.
 * @param[in] pos       Position at data to inserted in existing list
 * @return[out] 1/0     1- Successfull insertion / 0 - Failure
 */
int position_insert(LINK_INFO *l, int data, int pos) {

    SINGLE_LINKS *node, *next, *prev= NULL;
    int local_pos = 0, ret = 0;
    /* Node Creation */
    node = (SINGLE_LINKS *) malloc(sizeof(SINGLE_LINKS));
    if (node == NULL) {
        /* Failure */
        printf("Error: Malloc Failed");
    } else {
        node->value = data;
        node->next_node_addr = NULL;
        if(l->master == NULL) {
            /* Insert irrespective of position */
            l->master = node;
        } else {

            if (pos == 1) {
                /* First position */
                return (front_insert(l,data));
            } else if (pos > l->total_cnt) {
                /* Last position */
                return (rear_insert(l,data));
            } else {
                /* Any position */
                next = l->master;
                local_pos++;
                while((next->next_node_addr != NULL) && (pos != local_pos )) {
                    prev = next;
                    next = next->next_node_addr;
                    local_pos++;
                }
                if (pos == local_pos) {
                    prev->next_node_addr = node;
                    node->next_node_addr = next;
                    l->total_cnt++;
                    ret = 1;
                }
            }
        }
    }
    return ret;
}


/**
 * @brief               Insert Elements at mid position in  the linked List
 * @param[in] l         Pointer to structure to hold the master node & number of elements in list.
 * @param[in] data      data to store in the existing list.
 * @return[out] 1/0     1- Successfull insertion / 0 - Failure
 */
int mid_insert(LINK_INFO *l, int data) {

    SINGLE_LINKS *node;
    int mid_pos = 0, ret = 0;
    node = (SINGLE_LINKS*) malloc(sizeof(SINGLE_LINKS));
    if(node == NULL) {
        printf("Malloc Failed");
   } else {
        if (l->total_cnt == 0) {
            front_insert(l,data);
        } else {
            mid_pos = ceil(l->total_cnt/2) + 1;
            ret = position_insert(l,data,mid_pos);
        }
    }
    return ret;
}


/**
 * @brief               Display Elements in  the linked List
 * @param[in] l         Pointer to structure to hold the master node & number of elements in list.
 */
void print_list(LINK_INFO *l) {

    SINGLE_LINKS *sl = l->master;
    for(int i = 0; i < l->total_cnt; i++) {
        printf("%d ---> ", sl->value);
        sl = sl->next_node_addr;
    }
    printf("NULL \n");
    printf("Total Elements %d\n", l->total_cnt);
 }


/**
 * @brief               Static function to find the list id empty ot not
 * @param[in] l         Pointer to structure to hold the master node & number of elements in list.
 * @return[out] 1/0     1- Empty List / 0 - Not Empty List
 */
 static int Is_Empty(LINK_INFO *l) {
     if((l->master == NULL)  && (l->total_cnt == 0)) {
         printf("List is Empty");
         return 1;   /* TRUE -  EMPTY */
     }
     return 0; /* NOT EMPTY -  FALSE */
}


/**
 * @brief               Delete Elements at the beginning of  linked List
 * @param[in] l         Pointer to structure to hold the master node & number of elements in list.
 * @return[out]         void
 */
void front_delete(LINK_INFO *l) {

    SINGLE_LINKS *temp;
    if (!Is_Empty(l)) {
        temp = l->master;
        l->master = l->master->next_node_addr;
        temp->next_node_addr = NULL;
        free (temp);
        l->total_cnt--;
    }
    return;
}


/**
 * @brief               Delete Elements at end of  linked List
 * @param[in] l         Pointer to structure to hold the master node & number of elements in list.
 * @return[out]         void
 */
void rear_delete(LINK_INFO *l) {
    SINGLE_LINKS *temp, *prev;
    if (!Is_Empty(l)) {
        temp = l->master;
        while (temp->next_node_addr != NULL) {
            prev = temp;
            temp = temp->next_node_addr;
        }
        prev->next_node_addr = NULL;
        free(temp);
        l->total_cnt--;
    }
    return;
}


/**
 * @brief               Delete Elements at mid of linked List
 * @param[in] l         Pointer to structure to hold the master node & number of elements in list.
 * @return[out]         void
 */
void mid_delete(LINK_INFO *l) {
    SINGLE_LINKS *temp, *prev, *del_node;
    int mid_pos = 0, local_cnt = 0;
    if (!Is_Empty(l)) {
        mid_pos = ceil(l->total_cnt/2);
        temp = l->master;
        while ((temp->next_node_addr != NULL) && (local_cnt != mid_pos)) {
            prev = temp;
            temp = temp->next_node_addr;
            local_cnt++;
        }
        if(local_cnt ==  mid_pos) {
            del_node = temp;
            temp = temp->next_node_addr;
            prev->next_node_addr = temp;
            del_node->next_node_addr = NULL;
            free(del_node);
            l->total_cnt--;
        }
    }
    return;
}


/*TODO*/
void position_delete(LINK_INFO *l) {
    SINGLE_LINKS *temp, *prev;
    if (!Is_Empty(l)) {
        /*TODO*/
    }
    return;
}


/*TODO*/
void data_delete(LINK_INFO *l, int data) {
    SINGLE_LINKS *temp, *prev;
    if (!Is_Empty(l)) {
        /*TODO*/
    }
    return;
}


