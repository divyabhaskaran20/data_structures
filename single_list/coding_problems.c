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
