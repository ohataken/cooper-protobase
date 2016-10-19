#include "cooper_object.h"

static struct cooper_property *new_cooper_property(char *name, void *value) {
    struct cooper_property *p = malloc(sizeof(struct cooper_property));
    p->name = malloc(sizeof(char) * 32);
    strcpy(p->name, name);
    p->value = value;
    p->next = NULL;
    return p;
}

struct cooper_object *new_cooper_object(int size, struct cooper_object *proto) {
    struct cooper_object *p = malloc(sizeof(struct cooper_object));
    p->size = size;
    p->count = 0;
    p->table = malloc(sizeof(struct cooper_property *) * size);
    p->prototype = proto;

    for (int i = 0; i < size; ++i) {
        p->table[i] = NULL;
    }

    return p;
}

static int generate_hash_value(char *name) {
    int tmp = 0;

    for (int i = 0; i < (int)strlen(name); ++i) {
        tmp = (tmp << 1) + name[i];
    }

    return tmp;
}

void *insert_cooper_object(struct cooper_object *obj, char *name, void *value) {
    struct cooper_property *prop = new_cooper_property(name, value);
    int index = generate_hash_value(name) % obj->size;
    struct cooper_property *tail = obj->table[index];

    if (tail) {
        while (tail->next)
            tail = tail->next;

        tail->next = prop;
    } else {

        obj->table[index] = prop;
    }

    return value;
}

void *lookup_cooper_object(struct cooper_object *obj, char *name) {
    int index = generate_hash_value(name) % obj->size;
    struct cooper_property *prop = obj->table[index];

    if (prop) {
        while (strcmp(prop->name, name) != 0)
            prop = prop->next;

        return prop->value;
    } else if (obj->prototype) {
        return lookup_cooper_object(obj->prototype, name);
    } else {
        return NULL;
    }
}
