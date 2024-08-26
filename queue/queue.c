#include <stdlib.h>

typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
    int size;
} queue_t;

queue_t *queue_create(int capacity) {
    queue_t *queue = malloc(sizeof(queue_t));
    queue->data = malloc(capacity * sizeof(int));
    queue->front = 0;
    queue->rear = -1;
    queue->capacity = capacity;
    queue->size = 0;
    return queue;
}

int queue_is_empty(queue_t *queue) {
    return queue->size == 0;
}

int queue_is_full(queue_t *queue) {
    return queue->size == queue->capacity;
}

void queue_enqueue(queue_t *queue, int item) {
    if (queue_is_full(queue)) return;
    queue->rear = (queue->rear + 1) % queue->capacity;
    queue->data[queue->rear] = item;
    queue->size++;
}

int queue_dequeue(queue_t *queue) {
    if (queue_is_empty(queue)) return -1;
    int item = queue->data[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int queue_peek(queue_t *queue) {
    if (queue_is_empty(queue)) return -1;
    return queue->data[queue->front];
}

void queue_free(queue_t *queue) {
    free(queue->data);
    free(queue);
}