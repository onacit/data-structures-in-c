//
// Created by onacit on 2021-06-12.
//

#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "presidents_of_united_states.h"

static char FileName[] = "..\\presidents_of_united_states.txt";

void presidents_of_united_states_iterate(struct president_of_united_state_iterator * i) {
    assert(i != NULL);
    FILE *stream = fopen(FileName, "r");
    if (stream == NULL) {
        fprintf(stderr, "failed to open %s\n", FileName);
        return;
    }
    char b[27];
    char *n;
    while (fgets(b, 27, stream)) {
        b[strcspn(b, "\r\n")] = 0;
        const long int ordinal = strtol(b, &n, 10);
        ++n;
        struct president_of_united_state *p = malloc(sizeof (struct president_of_united_state));
        assert(p != NULL);
        p->o = ordinal;
        size_t size = strlen(n) + 1;
        p->n = malloc(size);
        strcpy(p->n, n);
        i->n(i, p);
    }
    {
        const int closed = fclose(stream);
        if (closed != 0) {
            fprintf(stderr, "failed to close %s; result: %d\n", FileName, closed);
        }
    }
}




