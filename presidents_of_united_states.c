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

void presidents_of_united_states_for_each(void (*a)(struct president_of_united_state *)) {
    FILE *stream;
    const errno_t opened = fopen_s(&stream, FileName, "r");
    if (opened != 0) {
        fprintf(stderr, "failed to open %s; errno: %d\n", FileName, opened);
        return;
    }
    char buf[27];
    while (fgets(buf, 27, stream)) {
        buf[strcspn(buf, "\r\n")] = 0;
        printf("%s\n", buf);
        char *name;
        const long int ordinal = strtol(buf, &name, 10);
        name++;
        printf("%ld\n", ordinal);
        printf("%s\n", name);
        struct president_of_united_state *p = malloc(sizeof (struct president_of_united_state));
        if (p == NULL) {
        }
        p->ordinal = ordinal;
        size_t size = strlen(name) + 1;
        p->name = malloc(size);
        strcpy_s(p->name, size, name);
        printf("%u %s\n", p->ordinal, p->name);
        free(p->name);
        free(p);
    }
    const int closed = fclose(stream);
    if (closed != 0) {
        fprintf(stderr, "failed to close %s; result: %d\n", FileName, closed);
    }
}

//struct singly_linked_node * presidents_of_united_states_singly_linked_nodes() {
//    FILE *stream;
//    const errno_t opened = fopen_s(&stream, FileName, "r");
//    if (opened != 0) {
//        fprintf(stderr, "failed to open %s; errno: %d\n", FileName, opened);
//        return NULL;
//    }
//    int *ordinal = NULL;
//    char *name = NULL;
//    while (fscanf_s(stream, "%d %s\n", ordinal, name) != EOF) {
//    }
//    const int closed = fclose(stream);
//    if (closed != 0) {
//        fprintf(stderr, "failed to close %s; result: %d\n", FileName, closed);
//    }
//}



