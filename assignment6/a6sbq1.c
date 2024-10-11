#include <stdio.h>

#define MAX 100

typedef struct {
    int top;
    char data[MAX];
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

int isFull(Stack* s) {
    return s->top == MAX - 1;
}

void push(Stack* s, char x) {
    if (!isFull(s)) {
        s->data[++(s->top)] = x;
    }
}

char pop(Stack* s) {
    if (!isEmpty(s)) {
        return s->data[(s->top)--];
    }
    return '\0';
}

int isMatching(char* expr) {
    Stack s;
    init(&s);
    for (int i = 0; expr[i] != '\0'; i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            push(&s, expr[i]);
        } else if (expr[i] == ')' || expr[i] == '}' || expr[i] == ']') {
            if (isEmpty(&s)) {
                return 0;
            }
            char top = pop(&s);
            if ((expr[i] == ')' && top != '(') ||
                (expr[i] == '}' && top != '{') ||
                (expr[i] == ']' && top != '[')) {
                return 0;
            }
        }
    }
    return isEmpty(&s);
}

int main() {
    char expr[100];
    printf("Enter an expression: ");
    scanf("%s", expr);

    if (isMatching(expr)) {
        printf("Parentheses are matching.\n");
    } else {
        printf("Parentheses are not matching.\n");
    }

    return 0;
}
