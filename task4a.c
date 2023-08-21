#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int isEmpty() {
    return front == -1;
}

int isFull() {
    return rear == MAX_SIZE - 1;
}

void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = value;
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    if (front == rear)
        front = rear = -1;
    else
        front++;
}

int peek() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot peek.\n");
        return -1;
    }
    return queue[front];
}

void display() {
    int i;
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, n, value, i, j;

    do {
        printf("Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of elements to enqueue: ");
                scanf("%d", &n);
                printf("Enter %d elements to enqueue: ", n);
                for (i = 0; i < n; i++) {
                    scanf("%d", &value);
                    enqueue(value);
                }
                break;

            case 2:
                printf("Enter the number of elements to dequeue: ");
                scanf("%d", &n);
                for (j = 0; j < n; j++) {
                    dequeue();
                }
                break;

            case 3:
                printf("Peek value: %d\n", peek());
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

