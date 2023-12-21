/**
 * @file    coding_problem
 *
 * @brief   This c File features various problems on linked list
 *
 * @author  Divya Bhaskaran
 *
 * @date    09/08/2023
 *
 */


/**< Standard Header Files */
#include <stdio.h>

#include "basic_list.h"           /**< User defined header Files */


/**
 * @brief       challenge1_arr
 *       Problem:  How do you find the middle element of a singly linked list in one pass?
 *       Solution: Use Array to store all elements in the list (this method is works on small list)
 * @param[in] l         Pointer to structure to hold the master node & number of elements in list.
 * @return[out]         Void
 */
void challenge1_arr(LINK_INFO *l) {

    int arr[50]= {0};
    SINGLE_LINKS *temp = l->master;
    int cnt = 0, mid = 0;
    if (l->master == NULL ) {
        printf("Empty List");
    } else {
        while (temp != NULL) {
            arr[cnt++] = temp->value;
            temp = temp->next_node_addr;
        }
        mid = (cnt/2);
        printf ("\n---- challenge1 (Using Array) - Find the middle element of a singly linked list in one pass?----\n");
        printf("Complete List: ");
        print_list(l);
        printf("Total number of elements = %d\n", cnt);
        printf("Mid element in the list = %d\n", arr[mid]);
        printf ("----------------------------------------------------------------\n");
    }
    return;
}


/**
 * @brief           challenge1_ptr
 *       Problem:  How do you find the middle element of a singly linked list in one pass?
 *       Solution: Use mod operator to find the Mid fo list as we traverse
 * @param[in] l         Pointer to structure to hold the master node & number of elements in list.
 * @return[out]         Void
 */
 void challenge1_ptr(LINK_INFO *l) {

    SINGLE_LINKS *temp, *mid;
    int cnt = 0;
    if (l->master == NULL ) {
        printf("Empty List");
    } else {
        temp = mid = l->master;
        while (temp != NULL) {
            cnt++;
            if (cnt%2 == 0){
                mid = mid->next_node_addr;
            }
            temp = temp->next_node_addr;
        }

        printf ("\n---- challenge1 (Using Pointers) - Find the middle element of a singly linked list in one pass?----\n");
        printf("Complete List: ");
        print_list(l);
        printf("Mid element in the list = %d\n", mid->value);
        printf ("----------------------------------------------------------------\n");
    }
    return;
}


/**
 * @brief          challenge2_ptr
 *       Problem:  How do you check if a given linked list contains a cycle? How do you find the starting node of the cycle
 *       Solution: Use 2 pointer technique (Slow: one step / Fast : Two Step)
 *       Todo: Another Solution  Use Hash Table
 * @param[in] l         Pointer to structure to hold the master node & number of elements in list.
 * @return[out] 1/0     1 - Cycle exist / 0 - No Cycle in the List
 */
int challenge2_ptr(LINK_INFO *l){

    SINGLE_LINKS *fast, *slow, *temp;
    int found = 0;
    if(l->master == NULL) {
     printf("Empty List");
    } else {
        /* Create Cycle */
        temp = l->master;
        while ((temp->next_node_addr != NULL)) {
            temp = temp->next_node_addr;
        }
        temp->next_node_addr = l->master;

        /* Check Cycle */
        slow = fast = l->master;
        while (fast != NULL)  {
            fast = fast->next_node_addr->next_node_addr;
            slow = slow->next_node_addr;
            if(slow == fast) {
                found = 1;
                break;
            }
        }
    }
    if (found) {
        printf("Cycle Found\n");
        return 1;
    } else {
        printf("No Cycle\n") ;
        return 0;
    }
}


/**
 * @brief          challenge3
 *       Problem:  Reverse the even number in the list
 *       Solution: extract the subsequent even numbers, create a new list with rear insert method and join back new even list with main list on next occurrence of odd number
 * @param[in]    l    Pointer to structure to hold the master node & number of elements in list.
 * @return[out]       Void
 *
 * Example:         Original : {1,5,6,8,9,10,12,5,3,1,4,6,9}
 *                  Expected:  {1,5,8,6,9,12,10,5,3,1,6,4,9}
 */
void challenge3(LINK_INFO *l) {

    SINGLE_LINKS *temp, *f, *last, *temp2;
    LINK_INFO g1 = {NULL, 0};
    int count = 0;
    if(l->master == NULL){
        printf("Empty List");
    } else {
        temp = l->master;
        while (temp->next_node_addr != NULL) {
            f = temp;
            count = 0;
            g1.master = NULL;
            g1.total_cnt = 0;
            while(temp->next_node_addr->value % 2 == 0){
                front_insert(&g1, temp->next_node_addr->value);
                count++;
                last = temp = temp->next_node_addr;
            }
            temp2 = g1.master;

            if(count > 0) {
                f->next_node_addr = temp2;
                while (temp2->next_node_addr != NULL){
                    temp2 = temp2->next_node_addr;
                }
                temp2->next_node_addr = last->next_node_addr;
            }
            temp = temp->next_node_addr;
        }
    }
}


/**
 * @brief          challenge4
 *       Problem:  Reverse the list
 *       Solution: use 2 list, create a new list and insert elements from front
 * @param[in]    l    Pointer to structure to hold the master node & number of elements in list.
 * @return[out]       Void
 *
 * Example:         Original : {1,5,6,8,9,10,12,5,3,1,4,6,9}
 *                  Expected:  {9,6,4,1,3,5,12,10,9,8,6,5,1}
 */
void challenge4(LINK_INFO *l) {

    SINGLE_LINKS *temp;
    LINK_INFO new_list = {NULL, 0};
    if (l->master == NULL){
        printf("Empty List");
        return;
    } else {
        temp = l->master;
        while(temp != NULL) {
            front_insert(&new_list, temp->value);
            temp = temp->next_node_addr;
        }
        l->master = new_list.master;
    }
    return;
}


/**
 * @brief          challenge4
 *       Problem:  Reverse the list
 *       Solution: use 3 pointer method, cur: points to reversed list, prev and temp: points to the next elements
 * @param[in]    l    Pointer to structure to hold the master node & number of elements in list.
 * @return[out]       Void
 *
 * Example:         Original : {1,5,6,8,9,10,12,5,3,1,4,6,9}
 *                  Expected:  {9,6,4,1,3,5,12,10,9,8,6,5,1}
 */
void challenge4_ptr(LINK_INFO *l) {

    SINGLE_LINKS *temp, *prev, *cur;
    if (l->master == NULL){
        printf("Empty List");
        return;
    } else {
      temp = l->master;
      if(temp->next_node_addr == NULL) {
          return;
      }
      prev = cur = temp;
      prev = temp = temp->next_node_addr;
      cur->next_node_addr = NULL;
     while(temp != NULL) {
          temp = temp->next_node_addr;
          prev->next_node_addr = cur;
          cur = prev;
          prev = temp;

      }
     l->master = cur;
    }
    return;
}







































