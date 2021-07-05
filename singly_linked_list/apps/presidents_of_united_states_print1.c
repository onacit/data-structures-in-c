//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "presidents_of_united_states.h"
#include "singly_linked_list.h"

static struct singly_linked_list *list;

bool accept(long presidency, char *president) {
    struct president_of_united_state *p = president_of_united_states(presidency, president);
    if (p == NULL) {
        return false;
    }
    size_t size = singly_linked_list_size(list);
    int inserted = singly_linked_list_insert(list, size, p);
    if (inserted != EXIT_SUCCESS) {
        president_of_united_states_free(p);
        return false;
    }
    return true;
}

bool print(void *data) {
    return true;
}

int main() {
    list = malloc(sizeof(struct singly_linked_list));
    if (list == NULL) {
        EXIT_FAILURE;
    }
    if (!presidents_of_united_states_consume_while(accept)) {
        fprintf(stderr, "failed to consume presidents");
        singly_linked_list_free(list, president_of_united_states_free_void);
        return EXIT_FAILURE;
    }
    singly_linked_list_consume_while(list, print);
    singly_linked_list_free(list, president_of_united_states_free_void);
    return EXIT_SUCCESS;
}


