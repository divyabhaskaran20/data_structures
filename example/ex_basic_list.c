/**
 * @file    ex_basic_list.c
 *
 * @brief   C Exmaple to use the API for single linked list
 *
 * @author  Divya Bhaskaran
 *
 * @date    09/08/2023
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include "../single_list/basic_list.h"
#include "../single_list/coding_problems.h"

/**
 * This is the main function
 */
int main() {

    LINK_INFO ll = {NULL, 0};

    printf("---------- Single Linked List (START) ------------\n");

    rear_insert(&ll, 5);
    rear_insert(&ll, 7);
    rear_insert(&ll, 9);
    rear_insert(&ll, 12);
    rear_insert(&ll, 15);
    print_list(&ll);

    front_insert(&ll, 3);
    print_list(&ll);

    position_insert(&ll, 1, 1);
    position_insert(&ll, 2, 2);
    print_list(&ll);

    mid_insert(&ll, 10);
    print_list(&ll);

    print_list(&ll);
    front_delete(&ll);
    print_list(&ll);

    rear_delete(&ll);
    print_list(&ll);


    mid_delete(&ll);
    print_list(&ll);

    mid_delete(&ll);
    print_list(&ll);

    printf("---------- Single Linked List (END) ------------\n");
    /* Success */
    return 1;
}

