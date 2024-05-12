#ifndef EX04_LIBRARY_H_
#define EX04_LIBRARY_H_

class Buffer {
public:
    virtual void write(int v) = 0;
    virtual int read() = 0;
    virtual int occupancy() = 0;
    virtual ~Buffer() {};
};

// Task 4(a).  Declare the class AutoReducingBuffer, by extending Buffer
// Write your code here

class AutoReducingBuffer : public Buffer {
public:
    AutoReducingBuffer(unsigned int capacity, int emptyValue);
    void write(int v) override;
    int read() override;
    int occupancy() override;
    bool contains(int v);
    ~AutoReducingBuffer() override;

private:
    unsigned int capacity;
    int emptyValue;
    int *buffer;
    unsigned int head;
    unsigned int tail;
    unsigned int numElements;
};

#endif /* EX04_LIBRARY_H_ */
