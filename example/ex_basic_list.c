//
// Created by dbhaskaran on 31/07/23.
//
#include <stdio.h>
#include <stdlib.h>

#include "../single_list/basic_list.h"

int main() {

    LINK_INFO ll = {NULL, 0};

    printf("single_linked_list \n");

    rear_insert(&ll, 5);
    rear_insert(&ll, 7);
    rear_insert(&ll, 9);
    rear_insert(&ll, 12);
    print_list(&ll);

    /* Success */
    return 1;
}