//
// Created by onacit on 2021-06-05.
//

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include "list.h"

// ------------------------------------------------------------------------ size

size_t list_size(struct list *l) {
    assert(l != NULL);
    return l->size(l); // <1>
}

bool list_empty(struct list *l) {
    assert(l != NULL);
    if (l->empty != NULL) {   // <1>
        return l->empty(l);   // <2>
    }
    return list_size(l) == 0; // <3>
}

// ---------------------------------------------------------------------- insert

int list_insert(struct list *l, size_t i, void *d) {
    assert(l != NULL);
    return l->insert(l, i, d); // <1>
}

int list_insert_first(struct list *l, void *d) {
    assert(l != NULL);
    if (l->insert_first != NULL) {    // <1>
        return l->insert_first(l, d); // <2>
    }
    return list_insert(l, 0, d);      // <3>
}

int list_insert_last(struct list *l, void *d) {
    assert(l != NULL);
    if (l->insert_last != NULL) {
        return l->insert_last(l, d);
    }
    return list_insert(l, list_size(l), d);
}

// ---------------------------------------------------------------------- delete

void *list_delete(struct list *l, size_t i) {
    assert(l != NULL);
    assert(!list_empty(l));
    return l->delete(l, i);
}

void *list_delete_first(struct list *l) {
    assert(l != NULL);
    if (l->delete_first != NULL) {
        return l->delete_first(l);
    }
    return list_delete(l, 0);
}

void *list_delete_last(struct list *l) {
    assert(l != NULL);
    if (l->delete_first != NULL) {
        return l->delete_last(l);
    }
    return list_delete(l, list_size(l) - 1);
}

// ------------------------------------------------------------------------- get

void *list_get(struct list *l, size_t i) {
    assert(l != NULL);
    assert(!list_empty(l));
    return l->get(l, i);
}

void *list_get_first(struct list *l) {
    assert(l != NULL);
    if (l->get_first != NULL) {
        return l->get_first(l);
    }
    return list_get(l, 0);
}

void *list_get_last(struct list *l) {
    assert(l != NULL);
    if (l->get_last != NULL) {
        return l->get_last(l);
    }
    return list_get(l, list_size(l) - 1);
}

// ------------------------------------------------------------------------- set

void *list_set(struct list *l, size_t i, void *d) {
    assert(l != NULL);
    assert(!list_empty(l));
    return l->set(l, i, d);
}

void *list_set_first(struct list *l, void *d) {
    assert(l != NULL);
    if (l->set_first != NULL) {
        return l->set_first(l, d);
    }
    return list_set(l, 0, d);
}

void *list_set_last(struct list *l, void *d) {
    assert(l != NULL);
    if (l->set_last != NULL) {
        return l->set_last(l, d);
    }
    return list_set(l, list_size(l) - 1, d);
}

// -------------------------------------------------------------------- iterator

struct list_iterator *list_iterator(struct list *l, size_t i) {
    assert(l != NULL);
    return l->iterator(l, i);
}

struct list_iterator *list_iterator_first(struct list *l) {
    assert(l != NULL);
    if (l->iterator_first != NULL) {
        l->iterator_first(l);
    }
    size_t i = 0;
    return l->iterator(l, i);
}

struct list_iterator *list_iterator_last(struct list *l) {
    assert(l != NULL);
    if (l->iterator_last != NULL) {
        l->iterator_last(l);
    }
    size_t i = list_size(l);
    return l->iterator(l, i);
}

void list_iterator_free(struct list *l, struct list_iterator *i) {
    assert(l != NULL);
    l->iterator_free(i);
}


// -----------------------------------------------------------------------------
//struct list_iterator_ {
//
//    struct list_iterator;
//
//    struct list *list;
//    size_t next;
//    size_t curr;
//};
//
//bool list_iterator_next(struct list_iterator_ *i) {
//    assert(i != NULL);
//    size_t size = list_size(i->list);
//    if (i->next < size) {
//        return false;
//    }
//    i->curr = i->next++;
//    return true;
//}
//
//bool list_iterator_prev(struct list_iterator_ *i) {
//    assert(i != NULL);
//    size_t size = list_size(i->list);
//    if (i->curr == 0) {
//        return false;
//    }
//    i->next = --i->curr;
//    return true;
//}
//
