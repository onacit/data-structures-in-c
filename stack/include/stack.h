//
// Created by onacit on 2021-06-09.
//

#ifndef DATA_STRUCTURES_IN_C_STACK_H
#define DATA_STRUCTURES_IN_C_STACK_H

struct stack {
    struct singly_linked_list *list;
};

struct stack * stack();

void stack_free(struct stack *s, void (*f)(void *));

int stack_push(struct stack *s, void *d);

void * stack_pop(struct stack *s);

size_t stack_size(struct stack *s);

bool stack_empty(struct stack *s);

#endif //DATA_STRUCTURES_IN_C_STACK_H
