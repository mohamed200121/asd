#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100 // Maximum size of the queue

// Define the queue structure
struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

// Function to initialize the queue
void initializeQueue(struct Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return queue->front == -1;
}

// Function to check if the queue is full
bool isFull(struct Queue* queue) {
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

// Function to enqueue an element
void enqueue(struct Queue* queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d.\n", value);
    } else {
        if (isEmpty(queue)) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->items[queue->rear] = value;
        printf("Enqueued %d to the queue.\n", value);
    }
}

// Function to dequeue an element
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! Cannot dequeue from an empty queue.\n");
        return -1; // Return an invalid value
    } else {
        int value = queue->items[queue->front];
        if (queue->front == queue->rear) {
            // Reset the queue after the last element is dequeued
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX_SIZE;
        }
        printf("Dequeued %d from the queue.\n", value);
        return value;
    }
}

// Function to peek at the front element
int peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No front element.\n");
        return -1; // Return an invalid value
    } else {
        return queue->items[queue->front];
    }
}

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element: %d\n", peek(&queue));

    dequeue(&queue);
    dequeue(&queue);

    printf("Front element after dequeues: %d\n", peek(&queue));

    dequeue(&queue); // Try to dequeue from an empty queue

    return 0;
}