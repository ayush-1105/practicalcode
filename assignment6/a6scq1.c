#include <stdio.h>
#include "sttstack.h"

int main() {
    Stack s;
    init(&s);

    push(&s, 10);
    push(&s, 20);
    push(&s, 30);
    push(&s, 40);

    printf("Stack before deleting last element: ");
    for (int i = 0; i <= s.top; i++) {
        printf("%d ", s.data[i]);
    }
    printf("\n");

    deleteLast(&s);

    printf("Stack after deleting last element: ");
    for (int i = 0; i <= s.top; i++) {
        printf("%d ", s.data[i]);
    }
    printf("\n");

    return 0;
}
