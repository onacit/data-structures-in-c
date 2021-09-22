#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "array_list.h"


struct array_list_env {
    void **array;
    size_t capacity;
    size_t size;
};

// ------------------------------------------------------------------------ size

size_t array_list_size(struct list *const l) {
    assert(l != NULL);
    struct array_list_env *e = l->env;
    return e->size;
}

bool array_list_empty(struct list *l) {
    return array_list_size(l) == 0;
}

// ---------------------------------------------------------------------- insert

bool array_list_insert(struct list *const l, const size_t i, void *const d) {
    assert(l != NULL);
    assert(i <= array_list_size(l));
    struct array_list_env *e = l->env;
    if (e->size == e->capacity) {
        e->capacity = e->capacity == 0 ? 1 : e->capacity << 1;
        void **a = realloc(e->array, sizeof(void *) * (e->capacity));
        if (a == NULL) {
            return false;
        }
        e->array = a;
    }
    memmove(e->array + (i + 1), e->array + i, sizeof(void *) * (e->size - i));
    e->array[i] = d;
    e->size = e->size + 1;
    return true;
}

bool array_list_insert_first(struct list *const l, void *const d) {
    return array_list_insert(l, 0, d);
}

bool array_list_insert_last(struct list *const l, void *const d) {
    return array_list_insert(l, array_list_size(l), d);
}

// ---------------------------------------------------------------------- delete

void *array_list_delete(struct list *const l, const size_t i) {
    assert(l != NULL);
    assert(i < array_list_size(l));
    struct array_list_env *e = l->env;
    void *d = e->array[i];
    memmove(e->array + i, e->array + (i + 1), sizeof(void *) * (e->size - (i - 1)));
    e->array[e->size - 1] = NULL;
    e->size = e->size - 1;
    return d;
}

void *array_list_delete_first(struct list *l) {
    return array_list_delete(l, 0);
}

void *array_list_delete_last(struct list *l) {
    array_list_delete(l, array_list_size(l) - 1);
}

// ------------------------------------------------------------------------- get

void *array_list_get(struct list *const l, const size_t i) {
    assert(l != NULL);
    assert(i < array_list_size(l));
    struct array_list_env *const e = l->env;
    return e->array[i];
}

void *array_list_get_first(struct list *const l) {
    return array_list_get(l, 0);
}

void *array_list_get_last(struct list *const l) {
    return array_list_get(l, array_list_size(l) - 1);
}

// ------------------------------------------------------------------------- set

void *array_list_set(struct list *const l, const size_t i, void *const d) {
    assert(l != NULL);
    struct array_list_env *e = l->env;
    void *const p = e->array[i];
    e->array[i] = d;
    return p;
}

void *array_list_set_first(struct list *const l, void *const d) {
    return array_list_set(l, 0, d);
}

void *array_list_set_last(struct list *const l, void *const d) {
    return array_list_set(l, array_list_size(l) - 1, d);
}

// -------------------------------------------------------- construct / destruct

struct list *array_list() {
    struct array_list_env *const e = malloc(sizeof(struct array_list_env));
    if (e == NULL) {
        return NULL;
    }
    e->array = NULL;
    e->capacity = 0;
    e->size = 0;
    struct list *const l = malloc(sizeof(struct list));
    if (l == NULL) {
        free(e);
        return NULL;
    }
    l->env = e;
    l->size = array_list_size;
    l->empty = array_list_empty;
    l->insert = array_list_insert;
    l->insert_first = array_list_insert_first;
    l->insert_last = array_list_insert_last;
    l->delete = array_list_delete;
    l->delete_first = array_list_delete_first;
    l->delete_last = array_list_delete_last;
    l->get = array_list_get;
    l->get_first = array_list_get_first;
    l->get_last = array_list_get_last;
    l->set = array_list_set;
    l->set_first = array_list_set_first;
    l->set_last = array_list_set_last;
    return l;
}

void array_list_free(struct list *const l) {
    assert(l != NULL);
    assert(array_list_size(l) == 0);
    struct array_list_env *const e = l->env;
    free(e->array);
    free(e);
    free(l);
}

// -------------------------------------------------------------------- iterator



//struct array_list_iterator_environment {
//    struct list *list;
//    size_t next;
//    size_t curr;
//};
//
//struct array_list_iterator {
//    struct list_iterator;
//    struct list *list;
//    size_t next;
//    size_t curr;
//};
//
//// -----------------------------------------------------------------------------
//bool array_list_iterator_next(struct list_iterator *i_) {
//    assert(i_ != NULL);
//    struct array_list_iterator *i = i_;
////    size_t size = array_list_size(e->list);
////    if (e->next < size) {
////        return false;
////    }
////    e->curr = e->next++;
//    return true;
//}
//
//bool array_list_iterator_previous(struct list_iterator *i) {
//    assert(i != NULL);
//    struct array_list_iterator_environment *e = i->environment;
//    size_t size = array_list_size(e->list);
//    if (e->curr == 0) {
//        return false;
//    }
//    e->next = --e->curr;
//    return true;
//}
//
//struct list_iterator * array_list_iterator(struct list *l, size_t i) {
//    assert(l != NULL);
//    assert(i <= array_list_size(l));
//    struct array_list_env *le = l->env;
//    struct array_list_iterator_environment *ie
//            = malloc(sizeof(struct array_list_iterator_environment));
//    if (ie == NULL) {
//        return NULL;
//    }
//    ie->list = l;
//    ie->next = i;
//    ie->curr = i - 1;
//}
//
//
//
//
