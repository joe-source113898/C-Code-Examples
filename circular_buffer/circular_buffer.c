#include <stdio.h>
#include "circular_buffer.h"

void initializeBuffer(CircularBuffer *cb)
{
    cb->write_index = 0;
    cb->read_index = 0;
    cb->counter = 0;
}

int isFUll(CircularBuffer *cb)
{
    return cb->counter == BUFFER_SIZE;
}

int isEmpty(CircularBuffer *cb)
{
    return cb->counter == 0;
}

void writeBuffer(CircularBuffer *cb, int data)
{
    if (!isFUll(cb))
    {
        cb->buffer[cb->write_index] = data;
        cb->write_index = (cb->write_index + 1) % BUFFER_SIZE;
        cb->counter++;
        printf("The buffer has a new value: %d\n", data);
    }
    else
    {
        printf("The buffer is full. You cannot add other value!\n");
    }
}

int readBuffer(CircularBuffer *cb)
{
    int data = 0;

    if (!isEmpty(cb))
    {
        data = cb->buffer[cb->read_index];
        cb->read_index = (cb->read_index + 1) % BUFFER_SIZE;
        cb->counter--;
    }
    else
    {
        printf("The buffer is empty. You cannot read any value!\n");
    }

    return data;
}

int main()
{   
    CircularBuffer cb;
    initializeBuffer(&cb);

    /* We call 5 times the function which write data within the buffer */
    writeBuffer(&cb, 1);
    writeBuffer(&cb, 2);
    writeBuffer(&cb, 3);
    writeBuffer(&cb, 4);
    writeBuffer(&cb, 5); /* The buffer is full at this point */

    writeBuffer(&cb, 6);

    printf("We are reading the value of %d\n", readBuffer(&cb));
    printf("We are reading the value of %d\n", readBuffer(&cb));

    writeBuffer(&cb, 11);
    writeBuffer(&cb, 12);

    while (!isEmpty(&cb)){
        printf("We are reading the value of %d\n", readBuffer(&cb));
    }

    readBuffer(&cb);

    return 0;
}