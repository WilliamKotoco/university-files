#include <stdio.h>
#include<stdlib.h>
#include "include/register.h"
#include "include/search_id.h"
#include "include/add_elements.h"

int main() {
    struct register_file element;
    uint op;
    printf("[1] for inserting a new register \n"
           "[2] for searching by index"
           "\n [3] for searching by name");
    scanf("%d", &op);
    switch (op)
    {
        case 1:
            add_element();
            break;
        case 2:
            search_by_id();
            break;

    }
}
