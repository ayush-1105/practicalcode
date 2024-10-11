#include <stdio.h>
#include "sttstack.h"

int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    int poppedValue;

    if (pop(&s, &poppedValue)) {
        printf("Popped value: %d\n", poppedValue);
    } else {
        printf("Stack is empty, nothing to pop.\n");
    }

    printf("Current top value: %d\n", top(&s));

    return 0;
}
