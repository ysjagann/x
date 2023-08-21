#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Stack {
    int arr[MAX_SIZE];
    int top;
};

void initStack(struct Stack *s) {
    s->top = -1;
}

bool isEmpty(struct Stack *s) {
    return s->top == -1;
}

bool isFull(struct Stack *s) {
    return s->top == MAX_SIZE - 1;
}

void push(struct Stack *s, int x) {
    if (isFull(s)) {
        printf("Stack is full, cannot push.\n");
        return;
    }
    s->arr[++s->top] = x;
    printf("Successfully inserted.\n");
}

int pop(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return -1; // Return -1 to indicate an empty stack
    }
    return s->arr[s->top--];
}

int peek(struct Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return -1; // Return -1 to indicate an empty stack
    }
    return s->arr[s->top];
}

struct MyQueue {
    struct Stack stack1;
    struct Stack stack2;
};

void initQueue(struct MyQueue *q) {
    initStack(&(q->stack1));
    initStack(&(q->stack2));
}

void pushQueue(struct MyQueue *q, int x) {
    push(&(q->stack1), x);
}

void transfer(struct Stack *src, struct Stack *dest) {
    while (!isEmpty(src)) {
        push(dest, pop(src));
    }
}

int popQueue(struct MyQueue *q) {
    if (isEmpty(&(q->stack2))) {
        if (!isEmpty(&(q->stack1))) {
            transfer(&(q->stack1), &(q->stack2));
        } else {
            printf("Queue is empty.\n");
            return -1; // Return -1 to indicate an empty queue
        }
    }
    return pop(&(q->stack2));
}

int peekQueue(struct MyQueue *q) {
    if (isEmpty(&(q->stack2))) {
        if (!isEmpty(&(q->stack1))) {
            transfer(&(q->stack1), &(q->stack2));
        } else {
            printf("Queue is empty.\n");
            return -1; // Return -1 to indicate an empty queue
        }
    }
    return peek(&(q->stack2));
}

bool emptyQueue(struct MyQueue *q) {
    return isEmpty(&(q->stack1)) && isEmpty(&(q->stack2));
}

int main() {
    struct MyQueue queue;
    initQueue(&queue);
    pushQueue(&queue, 11);
    pushQueue(&queue, 20);
    printf("Peek element is %d\n", peekQueue(&queue));
    printf("Popped element is %d\n", popQueue(&queue));
    printf("Popped element is %d\n", popQueue(&queue));
    printf("Queue is Empty: %s\n", emptyQueue(&queue) ? "true" : "false");
    return 0;
}

