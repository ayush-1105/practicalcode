#include "cstqueue.h"

int main() {
    CircularQueue q;
    init(&q);

    add(&q, 10);
    add(&q, 20);
    add(&q, 30);
    display(&q);

    printf("Deleted: %d\n", delete(&q));
    display(&q);

    add(&q, 40);
    add(&q, 50);
    display(&q);

    return 0;
}
