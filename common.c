//
// Created by onacit on 2021-06-07.
//

#include "common.h"

void increase_by(size_t *value, unsigned int delta) {
    *value += delta;
}

void increase_by_one(size_t *value) {
    increase_by(value, 1U);
}

void do_nothing(void *x, ...) {
    // does nothing
}

