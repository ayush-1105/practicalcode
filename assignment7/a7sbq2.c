#include "dstqueue.h"

int main() {
    Deque dq;
    init(&dq);

    addRear(&dq, 10);
    addRear(&dq, 20);
    addFront(&dq, 5);
    display(&dq);

    deleteFront(&dq);
    display(&dq);

    deleteRear(&dq);
    display(&dq);

    addFront(&dq, 1);
    addRear(&dq, 30);
    display(&dq);

    return 0;
}
