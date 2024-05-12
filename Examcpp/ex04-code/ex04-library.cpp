#include "ex04-library.h"
#include <cmath>

using namespace std;

// Task 4(a).  Write a placeholder implementation of AutoReducingBuffer's
// constructor, which takes two parameters: capacity and emptyValue
AutoReducingBuffer::AutoReducingBuffer(unsigned int capacity, int emptyValue) {
    this->capacity = capacity;
    this->emptyValue = emptyValue;
    this->buffer = new int[capacity]();
    this->head = 0;
    this->tail = 0;
    this->numElements = 0;
}


// Task 4(b).  Write a working implementation of write(int v) and occupancy()
void AutoReducingBuffer::write(int v) {
    if (numElements == capacity) {
        int total = v;

        for (unsigned int i = 0; i < capacity; i++) {
            total += buffer[(head + i) % capacity];
        }

        int average = total / capacity;

        buffer[head] = average;
        head = (head + 1) % capacity;
    } else {
        buffer[tail] = v;
        tail = (tail + 1) % capacity;
        numElements++;
    }
}

// Task 4(c).  Write a working implementation of read()
int AutoReducingBuffer::read() {
    if (numElements == 0) {
        return emptyValue;
    }
    int oldestValue = buffer[head];
    head = (head + 1) % capacity;
    numElements--;
    return oldestValue;
}

int AutoReducingBuffer::occupancy() {
    return numElements;
}

// Task 4(d).  Write a working implementation of contains(int v)
bool AutoReducingBuffer::contains(int v) {
    for (unsigned int i = 0; i < numElements; i++) {
        int index = (head + i) % capacity;
        if (buffer[index] == v) {
            return true;
        }
    }
    return false;
}

AutoReducingBuffer::~AutoReducingBuffer() {
    delete[] buffer;
}

// Do not modify
Buffer::~Buffer() {
    // Empty destructor
}
