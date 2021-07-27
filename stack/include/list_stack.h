//
// Created by onacit on 2021-06-09.
//

#ifndef DATA_STRUCTURES_IN_C_LIST_STACK_H
#define DATA_STRUCTURES_IN_C_LIST_STACK_H

#include <stdbool.h>
#include "list.h"
#include "stack.h"

struct stack * list_stack(struct list *l);

struct list * list_stack_free(struct stack * s);

#endif //DATA_STRUCTURES_IN_C_LIST_STACK_H
