#ifndef COOPER_OBJECT_H
#define COOPER_OBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cooper_property {
    char *name;
    void *value;
    struct cooper_property *next;
};

struct cooper_object {
    int size;
    int count;
    struct cooper_object *prototype;
    struct cooper_property **table;
};

struct cooper_object *new_cooper_object(int size, struct cooper_object *proto);

void *insert_cooper_object(struct cooper_object *obj, char *name, void *value);

void *lookup_cooper_object(struct cooper_object *obj, char *name);

#endif
