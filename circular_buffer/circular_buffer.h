#ifndef CIRCULAR_BUFFER_H
#define CIRCULAR_BUFFER_H

#define BUFFER_SIZE 5

typedef struct{
    int buffer[BUFFER_SIZE];
    int write_index;
    int read_index;
    int counter;
} CircularBuffer;

void initializeBuffer(CircularBuffer *cb);
int isFull(CircularBuffer *cb);
int isEmpty(CircularBuffer *cb);
void writeBuffer(CircularBuffer *cb, int data);
int readBuffer(CircularBuffer *cb);

#endif