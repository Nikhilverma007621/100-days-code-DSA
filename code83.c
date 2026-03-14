#include <stdio.h>
#define MAX 100

int queue[MAX], stack[MAX];
int front = -1, rear = -1, top = -1;

// Enqueue
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

// Push into stack
void push(int x) {
    if (top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

// Pop from stack
int pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int main() {
    int n, i, x;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Move queue elements to stack
    while (front <= rear) {
        push(dequeue());
    }

    // Reset queue
    front = rear = -1;

    // Step 2: Move stack elements back to queue
    while (top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    printf("Reversed queue: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}