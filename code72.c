#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1, size = 0, capacity;

bool isEmpty() {
    return size == 0;
}

bool isFull() {
    return size == capacity;
}

bool insertFront(int value) {
    if (isFull())
        return false;

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + capacity) % capacity;
    }

    deque[front] = value;
    size++;
    return true;
}

bool insertLast(int value) {
    if (isFull())
        return false;

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % capacity;
    }

    deque[rear] = value;
    size++;
    return true;
}

bool deleteFront() {
    if (isEmpty())
        return false;

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % capacity;
    }

    size--;
    return true;
}

bool deleteLast() {
    if (isEmpty())
        return false;

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + capacity) % capacity;
    }

    size--;
    return true;
}

int getFront() {
    if (isEmpty())
        return -1;
    return deque[front];
}

int getRear() {
    if (isEmpty())
        return -1;
    return deque[rear];
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
        i = (i + 1) % capacity;
    }
    printf("\n");
}

int main() {
    capacity = 3;

    insertLast(1);
    insertLast(2);
    insertFront(3);

    if (!insertFront(4))
        printf("Deque is full\n");

    printf("Rear element: %d\n", getRear());
    printf("Is Full: %s\n", isFull() ? "true" : "false");

    deleteLast();
    insertFront(4);

    printf("Front element: %d\n", getFront());

    printf("Deque elements: ");
    display();

    return 0;
}