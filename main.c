#include "cooper_object.h"
#include <stdio.h>

void greeting() {
    printf("hello world\n");
}

int main(void) {
    printf("cooper-protobase\n");
    struct cooper_object *a = new_cooper_object(1, NULL);
    struct cooper_object *b = new_cooper_object(1, a);

    insert_cooper_object(a, "greeting", greeting);
    insert_cooper_object(a, "hi", greeting);
    insert_cooper_object(a, "hello", greeting);

    ((void (*)())lookup_cooper_object(b, "greeting"))();

    return 0;
}
