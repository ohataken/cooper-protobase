#include "cooper_object.h"
#include <stdio.h>

void greeting() {
    printf("hello world\n");
}

int main(void) {
    printf("cooper-protobase\n");
    struct cooper_object *a = new_cooper_object(7, NULL);
    struct cooper_object *b = new_cooper_object(7, a);

    insert_cooper_object(a, "greeting", greeting);

    ((void (*)())lookup_cooper_object(b, "greeting"))();

    return 0;
}
