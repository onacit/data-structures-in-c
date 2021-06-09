//
// Created by onacit on 2021-06-09.
//

#ifndef DATA_STRUCTURES_IN_C_STACK_H
#define DATA_STRUCTURES_IN_C_STACK_H

typedef struct stack_ {
    singly_linked_list *list;
} stack;

stack * stack_alloc();

void stack_free(stack *s, void const (*a)(void *));

int stack_push(stack const *s, void const *d);

void * stack_pop(stack const *s);

size_t stack_size(stack const *s);

bool stack_empty(stack const *s);

#endif //DATA_STRUCTURES_IN_C_STACK_H
